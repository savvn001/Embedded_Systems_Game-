#include "gameEngine.h"


Serial serial2(USBTX, USBRX);


gameEngine::gameEngine(){

}

gameEngine::~gameEngine(){

}

void gameEngine::init(ghzone &level, sonicClass &sonic, Gamepad &pad){

  level.init();
  sonic.init(pad);

  sonic_player_x = 40;
  sonic_player_y = 28;

  ringCount = 0;

}


void gameEngine::read_input(Gamepad &pad, sonicClass sonic)
{

    sonic.getInput(pad);
    //Testing buttons with printf
    // if(pad_A){
    //   serial2.printf ("%s \n", "A");
    // }
    // if(pad_B){
    //   serial2.printf ("%s \n", "B");
    // }
    // if(pad_X){
    //   serial2.printf ("%s \n", "X");
    // }
    // if(pad_Y){
    //   serial2.printf ("%s \n", "Y");
    // }
    // if(pad_start){
    //   serial2.printf ("%s \n", "start");
    // }
    // if(pad_back){
    //   serial2.printf ("%s \n", "back");
    // }
    // serial2.printf ("%s \n", joystick_dir);
    // serial2.printf ("%f \n", joystick_mag);

}

/*

1


*/

void gameEngine::draw(N5110 &lcd, ghzone &level, sonicClass &sonic){

  level.drawMap(lcd);
  sonic.draw(lcd);

  //Converting ring count integer to string using c++ <sstream> lib
  stringstream convert;
  convert << ringCount;
  string s_ringCont = convert.str();

  //In game HUDss
  lcd.drawCircle(3, 3, 2, 0);
  lcd.printString("=",8,0);
  lcd.printString(s_ringCont.c_str(),15,0);


}

void gameEngine::update(sonicClass &sonic, ghzone &level){

  //values before user input
  last_sonic_player_x = sonic_player_x;
  last_sonic_player_y = sonic_player_y;

  sonic.update(sonic_player_x, sonic_player_y);

  sonic_player_x = sonic.getPlayerX();
  sonic_player_y = sonic.getPlayerY();

  direction_x = sonic.getDirectionX();

  collisionCheck(level);
  sonic.handleCollision(collision_top, collision_bottom);

  level.updateMap(sonic_player_x, sonic_player_y); //Offset camera, fix later
}

//private

void gameEngine::collisionCheck(ghzone &level){

    //check for collisions across X
    collision_x = false;
    collision_y = false;
    collision_top = false;
    collision_bottom = false;
    
    switch(direction_x){

      case false:
        collisionRight(level);
      case true:
        collisionLeft(level);
    }

    collisionTop(level);
    collisionBottom(level);

}

void gameEngine::collisionRight(ghzone &level){

  for (int x_start = last_sonic_player_x; x_start <= sonic_player_x; x_start++) {

    int hitbox_left =  (int)(x_start+1)/4; //X
    int hitbox_right = (int)(x_start+12)/4;//X

    int hitbox_top =  (int)(sonic_player_y+1)/4;//Y
    int hitbox_bttm = (int)(sonic_player_y+10)/4; //Y

    collision_x = checkTiles(hitbox_left, hitbox_right, hitbox_top, hitbox_bttm, level);

    //When collision with solid tile detected
    if(collision_x){
      sonic_player_x = x_start-1;
      break;
    }
  }
}

void gameEngine::collisionLeft(ghzone &level){

  for (int x_start = last_sonic_player_x; x_start >= sonic_player_x; x_start--) {

    int hitbox_left =  (int)(x_start-2)/4; //X
    int hitbox_right = (int)(x_start+12)/4;//X

    int hitbox_top =  (int)(sonic_player_y+1)/4;//Y
    int hitbox_bttm = (int)(sonic_player_y+10)/4; //Y

    collision_x = checkTiles(hitbox_left, hitbox_right, hitbox_top, hitbox_bttm, level);

    //When collision with solid tile detected
    if(collision_x){
      sonic_player_x = x_start+1;
      break;
    }
  }



}

void gameEngine::collisionBottom(ghzone &level){

  for (int y_start = last_sonic_player_y; y_start <= sonic_player_y; y_start++) {

    int hitbox_left =  (int)(sonic_player_x-2)/4; //X
    int hitbox_right = (int)(sonic_player_x+12)/4;//X

    int hitbox_top =  (int)(y_start+1)/4;//Y
    int hitbox_bttm = (int)(y_start+12)/4; //Y

    collision_y = checkTiles(hitbox_left, hitbox_right, hitbox_top, hitbox_bttm, level);

    //When collision with solid tile detected
    if(collision_y){
      collision_bottom = true;
      sonic_player_y = y_start-1;
      break;
    }
  }

}

void gameEngine::collisionTop(ghzone &level){

  for (int y_start = last_sonic_player_y; y_start >= sonic_player_y; y_start--) {

    int hitbox_left =  (int)(sonic_player_x-2)/4; //X
    int hitbox_right = (int)(sonic_player_x+12)/4;//X

    int hitbox_top =  (int)(y_start+1)/4;//Y
    int hitbox_bttm = (int)(y_start+12)/4; //Y

    collision_y = checkTiles(hitbox_left, hitbox_right, hitbox_top, hitbox_bttm, level);

    //When collision with solid tile detected
    if(collision_y){
      collision_top = true;
      sonic_player_y = y_start+1;
      break;
    }
  }
}


bool gameEngine::checkTiles(int boxleft, int boxright, int boxtop, int boxbottom, ghzone &level){

  bool collision = false;

  //Collisions on left & right
  for(int i = boxleft; i<=boxright; i++)
  {
    for(int j = boxtop; j<=boxbottom; j++)
    {
        char symbol_check = level.getTile(i, j); //check symbol of tile in question

        if(level.checkSolid(symbol_check)){
          collision = true;
        }

        switch (symbol_check) {
          case '*':
          ringCount++;
          level.setTile(i, j, ' ');
        }

    }
  }
  return collision;
}

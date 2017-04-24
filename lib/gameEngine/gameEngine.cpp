#include "gameEngine.h"


Serial serial2(USBTX, USBRX);


gameEngine::gameEngine(){

}

gameEngine::~gameEngine(){

}

void gameEngine::init(ghzone &level, sonicClass &sonic, Gamepad &pad){

  level.init();
  sonic.init(pad);

  sonic_player_x = 4;
  sonic_player_y = 28;

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

}

void gameEngine::update(sonicClass &sonic, ghzone &level){

  //values before user input
  last_sonic_player_x = sonic_player_x;
  last_sonic_player_y = sonic_player_y;

  sonic.update(sonic_player_x, sonic_player_y);

  sonic_player_x = sonic.getPlayerX();
  sonic_player_y = sonic.getPlayerY();

  collisionCheck(sonic_player_x, sonic_player_y, level);

  level.updateMap(sonic_player_x, sonic_player_y); //Offset camera, fix later

}


void gameEngine::collisionCheck(int sonic_player_x, int sonic_player_y, ghzone &level){

  for (int i = 0; i < 2; i++) {

    int rightEdge = sonic_player_x+10;
    int bottomEdge = sonic_player_y+10;
    int leftEdge = sonic_player_x+2;
    int topEdge = sonic_player_y+1;

    int hitbox_left = (leftEdge -= leftEdge % 4)/4; //X
    int hitbox_right = (rightEdge -= rightEdge % 4)/4; //X
    int hitbox_top = (topEdge -= topEdge % 4)/4; //Y
    int hitbox_bttm = (bottomEdge -= bottomEdge % 4)/4; //Y

    //check for collision
    bool collision = checkTiles(hitbox_left, hitbox_right, hitbox_top, hitbox_bttm, level);

    //First set X position to value before collision
    if(collision && i == 0){
      sonic_player_x = last_sonic_player_x;
    }
    //Come back into loop, if there's still a collision, set Y value to value before collision
    if(collision && i == 1){
      sonic_player_y = last_sonic_player_y;
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

        //collisionAction;
        // switch (symbol_check) {
        //   case '*':
        //   ringCount++;
        //   break;
        // }
    }
  }
  return collision;

}

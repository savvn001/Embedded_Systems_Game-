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

  collisionCheck(level);

  level.updateMap(sonic_player_x, sonic_player_y); //Offset camera, fix later
}

//private

void gameEngine::collisionCheck(ghzone &level){

    //check for collisions across X
    bool collision_x = false;

    for (int x_start = last_sonic_player_x; x_start < sonic_player_x; x_start++) {

      int rightEdge = x_start+12;
      int leftEdge = x_start+1;

      int topEdge = sonic_player_y+1;
      int bottomEdge = sonic_player_y+10;

      int hitbox_left = (leftEdge -= leftEdge % 4)/4; //X
      int hitbox_right = (rightEdge -= rightEdge % 4)/4; //X

      int hitbox_top = (topEdge -= topEdge % 4)/4; //Y
      int hitbox_bttm = (bottomEdge -= bottomEdge % 4)/4; //Y

      collision_x = checkTiles(hitbox_left, hitbox_right, hitbox_top, hitbox_bttm, level);

      //When collision with solid tile detected
      if(collision_x){
        sonic_player_x = x_start;
        break;
      }
    }

    bool collision_y = false;

    for (int y_start = last_sonic_player_y; y_start < sonic_player_y; y_start++) {

      int rightEdge = sonic_player_x+12;
      int leftEdge = sonic_player_x+1;

      int topEdge = y_start+1;
      int bottomEdge = y_start+10;

      int hitbox_left = (leftEdge -= leftEdge % 4)/4; //X
      int hitbox_right = (rightEdge -= rightEdge % 4)/4; //X

      int hitbox_top = (topEdge -= topEdge % 4)/4; //Y
      int hitbox_bttm = (bottomEdge -= bottomEdge % 4)/4; //Y

      collision_y = checkTiles(hitbox_left, hitbox_right, hitbox_top, hitbox_bttm, level);

      //When collision with solid tile detected
      if(collision_y){
        sonic_player_y = y_start;
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

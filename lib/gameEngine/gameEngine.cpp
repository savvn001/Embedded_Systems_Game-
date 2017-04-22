#include "gameEngine.h"


Serial serial2(USBTX, USBRX);


gameEngine::gameEngine(){

}

gameEngine::~gameEngine(){

}

void gameEngine::init(ghzone &level, sonicClass &sonic, Gamepad &pad){

  level.init();
  sonic.init(pad);


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
  //
  // level_collision = level.collisionCheck(sonic_player_x, sonic_player_y);
  // sonic.collisionCheck(level_collision);
  sonic.update();
  sonic_player_x = sonic.getPlayerX();
  sonic_player_y = sonic.getPlayerY();
  level.updateMap(sonic_player_x, sonic_player_y);

}


void collisionCheck(){

 //  int rightEdge = player_x+11;
 //  int bottomEdge = player_y+13;
 //
 //  int hitbox_left = (player_x -= player_x % 4)/4;
 //  int hitbox_right = (rightEdge -= rightEdge % 4)/4;
 //  int hitbox_top = (player_y -= player_y % 4)/4;
 //  int hitbox_bttm = (bottomEdge -= bottomEdge % 4)/4;
 //
 //  if(hitbox_left < 0){
 //    hitbox_left = 0;
 //  }
 //  if(hitbox_right > NO_OF_SCREENS_ACROSS*21) {
 //    hitbox_right = NO_OF_SCREENS_ACROSS*21;
 //  }
 //  if(hitbox_top < 0){
 //    hitbox_top = 0;
 //  }
 //  if(hitbox_bttm > NO_OF_SCREENS_DOWN*12) {
 //    hitbox_bttm = NO_OF_SCREENS_DOWN*12;
 //  }
 //
 //
 // for (int i = 0; i < 3; i++) {
 //   collision_x = tileCheck(hitbox_right, hitbox_bttm-i); //check tiles right side of sonic
 //   collision_y = tileCheck(hitbox_right-i, hitbox_bttm); //check tiles underneath sonic
 // }
 //
 // return collision_id;
}

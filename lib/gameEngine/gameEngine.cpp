#include "gameEngine.h"


Serial serial2(USBTX, USBRX);


gameEngine::gameEngine(){

}

gameEngine::~gameEngine(){

}

void gameEngine::init(maps &Maps, sonicClass &sonic, Gamepad &pad){

  Maps.init();
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

void gameEngine::draw(N5110 &lcd, maps &Maps, sonicClass &sonic){

  //
  // Maps.drawMap(lcd);
  // sonic.draw(lcd);

}

void gameEngine::update(sonicClass &sonic, maps &Maps){

  // maps_collision = Maps.collisionCheck(sonic_player_x, sonic_player_y);
  // sonic.collisionCheck(maps_collision);
  // sonic.update(joystick_dir, joystick_mag, pad_A);
  // sonic_player_x = sonic.getPlayerX();
  // sonic_player_y = sonic.getPlayerY();
  // Maps.updateMap(sonic_player_x, sonic_player_y);

}


/////////////////private functions/////////////////////
/*
  Drawmap function
  Draw

*/

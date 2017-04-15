/*

Class that describes sonic's behaviour; his movements, animations and how he interacts with the map.


*/

#include "sonicClass.h"

sonicClass::sonicClass(){

}

sonicClass::~sonicClass(){

}

void sonicClass::init(int offset_x, int map_y){

  //initalize sonic's position within the map array
  //map1_data[8][0] = 4;


}

void sonicClass::draw(N5110 &lcd){





}



void sonicClass::update(Direction joystick_dir, float joystick_mag){

  speed = (joystick_mag/5);
  printf("speed = %f\n\n", speed);
  printf("mag = %f\n\n", joystick_mag);

  //call running function if analogue stick moved
  if(joystick_mag > 0){
    running(joystick_dir,joystick_mag);
  }

  //other movement functions....

  //update position within array
  // if(player_x > 0){
  //   //map1_data[8][player_x - 1] = 0;
  //
  // }
  //map1_data[8][player_x] = 4;
  //updateCamera();

}



int sonicClass::getPlayerPos(){

  return player_x;
  //return map_y;

}





//Private functions


void sonicClass::running(Direction joystick_dir, float joystick_mag){
  //update poisition in map array
  if(joystick_dir == E){
    speed_x+= speed;
  }
  else if(joystick_dir == W){
    speed_x-= speed;
  }

  player_x = int(speed_x);

}

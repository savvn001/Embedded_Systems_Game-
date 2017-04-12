/*

Class that describes sonic's behaviour; his movements, animations and how he interacts with the map.


*/

#include "sonicClass.h"

sonicClass::sonicClass(){

}

sonicClass::~sonicClass(){

}

void sonicClass::init(){

  //initalize sonic's position within the map array
  //map1_data[8][0] = 4;
  player_x = 0;
  player_y = 4;
  map_x = 0;
  map_y = 0;

}

void sonicClass::draw(N5110 &lcd){





}



void sonicClass::update(Direction joystick_dir, float joystick_mag, maps &Maps){

  speed = (joystick_mag/10);
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

  updateCamera();
  updateMaps(Maps);
}









//Private functions

void sonicClass::updateCamera(){

  if (player_x < int(21/2)){
    map_x = 0;
  }
  else if (player_x > int(84 - 21) / 2){
    map_x = 84-21;
  }
  else {
    map_x = player_x - int(21 / 2);
  }

  printf("                                                        map_x in sonic = %i\n\n", map_x);


}

void sonicClass::running(Direction joystick_dir, float joystick_mag){
  //update poisition in map array
  if(joystick_dir == E){
    speed_x+= speed;
  }
  else if(joystick_dir == W){
    speed_x-= speed;
  }

  player_x = int(speed_x);
  printf("                     player x = %i\n\n ", player_x);



}

void sonicClass::updateMaps(maps &Maps){

    Maps._map_x = map_x;

}

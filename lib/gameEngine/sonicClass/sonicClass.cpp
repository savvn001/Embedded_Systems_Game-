/*

Class that describes sonic's behaviour; his movements, animations and how he interacts with the map.


*/

#include "sonicClass.h"

sonicClass::sonicClass(){

}

sonicClass::~sonicClass(){

}

////////////////////////////////************Sonic's sprite set*************///////////////////////////////////////

static int sonic_stationary[] = {

  0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,0,
  0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,1,1,1,1,1,
  1,1,1,1,

};

static int sonic_walk_1[] = {

  0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,0,
  0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,
  0,0,0,0,

};
static int sonic_walk_2[] = {

  0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,0,
  0,0,0,0,1,1,1,1,1,0,0,1,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,
  0,0,0,0,

};
static int sonic_walk_3[] = {

  0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,0,
  0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,
  0,0,0,0,

};
static int sonic_walk_4[] = {

  0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,0,
  0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,
  0,0,0,0,

};
static int sonic_walk_5[] = {

  0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,0,
  0,0,0,1,0,0,1,1,1,0,0,1,0,0,1,0,1,1,1,1,1,1,1,0,0,1,0,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
  0,0,0,0,

};
static int sonic_walk_6[] = {

  0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,0,
  0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,
  0,0,0,0,

};

static int sonic_run1[] = {

};
static int sonic_run2[] = {

};
static int sonic_run3[] = {

};
static int sonic_run4[] = {

};


/////////////////

struct _sonicSpriteSet{


    string state;

    int *array;
    int rows;
    int columns;
    int Joystick_Direction; //delay time until next sprite in animation

    string nextState;

  };


_sonicSpriteSet sonicSpriteSet [12] = {

  {"stat", sonic_stationary, 12, 12, 0, "walk1"},
  {"walk1", sonic_walk_1, 12, 12, 0, "walk2"},
  {"walk2", sonic_walk_2, 12, 12, 0, "walk3"},
  {"walk3", sonic_walk_3, 12, 12, 0, "walk4"},
  {"walk4", sonic_walk_4, 12, 12, 0, "walk5"},
  {"walk5", sonic_walk_5, 12, 12, 0, "walk6"},
  {"walk6", sonic_walk_6, 12, 12, 0, "walk1"},
  {"run1",  sonic_run1, 12, 12, 0, ""},
  {"run2",  sonic_run2, 12, 12, 0, ""},
  {"run3",  sonic_run3, 12, 12, 0, ""},
  {"run4",  sonic_run4, 12, 12, 0, ""},

};

void sonicClass::init(Gamepad &pad){

  spriteStateOutput_nextState = (sonicSpriteSet+0)->nextState;
  mirror = false;

  player_x = 0;
  player_y = 28;

  gravity = 0.21875;
  jump_speed = 0.09375;
  jumping = false;
  air_acc =  0.09375;

  ground_acc = 0.5+0.046875;
  ground_dec = 0.5+1;
  top_speed = 6;
}




void sonicClass::getInput(Gamepad &pad){


}

void sonicClass::draw(N5110 &lcd){

  for (int i = 0; i < 12; i++) {

    if((sonicSpriteSet+i)->state == spriteStateOutput){
      Bitmap sonic((sonicSpriteSet+i)->array, (sonicSpriteSet+i)->rows , (sonicSpriteSet+i)->columns);
      sonic.render(lcd, player_x, player_y, mirror);
      break;
    }

  }

}



void sonicClass::update(Direction joystick_dir, float joystick_mag){

  speedFloat = (joystick_mag/2); //divisor sets speed, can be changed
  printf("speedFloat  = %f\n\n", joystick_mag);



  running(joystick_dir,joystick_mag);
  //jump(joystick_dir, joystick_mag);
}


int sonicClass::getPlayerPos(){

  return player_x;
  //return map_y;

}






////////////////////////////////////Private functions/////////////////////////////////////////////


void sonicClass::running(Direction joystick_dir, float joystick_mag){
  //if(joystick_mag > 0){
    if (joystick_dir == W)
        {
          mirror = true;
            if (speed_x > 0)
            {
                speed_x -= ground_dec;
            }
            else if (speed_x > -top_speed)
            {
                speed_x -= ground_acc;
            }
        }
        else if (joystick_dir == E)
      {
          mirror = false;
          if (speed_x < 0)
          {
              speed_x += ground_dec;
          }
          else if (speed_x < top_speed)
          {
              speed_x += ground_acc;
          }

      }
      else{
        speed_x = min(abs(speed_x), ground_acc)*sign(speed_x);
      }
      player_x += int(speed_x)/4; //divisor sets character speed
      run_animation(speed_x, player_x);

printf("                                                                     speed_x = %f\n", speed_x);
printf("                                                                     player_x = %i\n", player_x);
}

void sonicClass::run_animation(float speed_x, int player_x){
  //when running
  if(speed_x != 0){
    //checking if speed_x is equal to player_x, every multiple of 2, means animation frame only changes every 2 changes in x position
    if(player_x % 3 == 0){
      animationLoop(0, 12);
    }

  }
  else if (speed_x == 0){
    spriteStateOutput = (sonicSpriteSet+0)->state;
    spriteStateOutput_nextState = (sonicSpriteSet+0)->nextState;
  }
}

void sonicClass::jump(){

  if(1){

    jumping = true;
    jump_speed -= gravity;
    speed_y += jump_speed;


    player_y = int(speed_y); //in pixels (not to alligned to tiles)

    }
}

void sonicClass::fall(){

  //if(collision == false)
  speed_y+= gravity;
  player_y -= int(speed_y);


}




void sonicClass::animationLoop(int i, int i_max){

  for(int i; i < i_max; i++){
      if(spriteStateOutput_nextState == (sonicSpriteSet+i)->state){

        spriteStateOutput = (sonicSpriteSet+i)->state;
        spriteStateOutput_nextState = (sonicSpriteSet+i)->nextState;
        break;
      }

  }

}

int sonicClass::sign(int value){

  int sgn;

  if(value < 0){
    sgn = - 1;
  }
  else if(value == 0){
    sgn = 0;
  }
  else if(value > 0){
    sgn = 1;
  }
  return sgn;

}

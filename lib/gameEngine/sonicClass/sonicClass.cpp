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
    int Joystick_Direction;

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

  player_x = 4;
  player_y = 28; //change after
  draw_player_x = 0;
  draw_player_y = 28;

  vel_x = 0;
  vel_y = 0;

  gravity = 0.21875;
  jumping = false;
  air_acc =  0.09375; //X axis acceleration while in air, greater than when on ground

  ground_acc = 0.5+0.046875;
  ground_dec = 0.5+1;
  top_vel = 6;
}




void sonicClass::getInput(Gamepad &pad){

  pad_A = pad.check_event(Gamepad::A_PRESSED);
  pad_B = pad.check_event(Gamepad::B_PRESSED);
  pad_X = pad.check_event(Gamepad::X_PRESSED);
  pad_Y = pad.check_event(Gamepad::Y_PRESSED);
  pad_back = pad.check_event(Gamepad::BACK_PRESSED);
  pad_start = pad.check_event(Gamepad::START_PRESSED);
  joystick_mag = pad.get_mag();
  joystick_dir = pad.get_direction();


}

void sonicClass::draw(N5110 &lcd){


  for (int i = 0; i < 12; i++) {

    if((sonicSpriteSet+i)->state == spriteStateOutput){
      Bitmap sonic((sonicSpriteSet+i)->array, (sonicSpriteSet+i)->rows , (sonicSpriteSet+i)->columns);
      sonic.render(lcd, draw_player_x, draw_player_y, mirror);
      break;
    }

  }

}



void sonicClass::update(){

  //velFloat = (joystick_mag/2); //divisor sets vel, can be changed
  player_x += int(vel_x)/4; //divisor scales character velocity
  player_y += int(vel_y);

  //some boundaries for x & y values
  if(player_x < 0){
    player_x = 0;
  }
  if(player_y < 0){
    player_y = 0;
  }

  camera();
  //Movement functions
  running();
  jump();
printf("%f\n", joystick_mag);
  printf("                                                                     vel_x = %f\n", vel_x);
  printf("                                                                     player_x = %i\n", player_x);
  printf("                                                                     player_y = %i\n", player_y);

}



int sonicClass::getPlayerX(){

return player_x;

}
int sonicClass::getPlayerY(){

return player_y;

}

void sonicClass::collisionCheck(char collision){

  // switch (collision) {
  //
  //   case 'r': //collision right
  //   vel_x = 0; //set vel to 0
  //   player_x -= 1; //'bounce' back by 1px, so sonic doesn't stick to wall
  //
  //   case 'b': //collision underneath
  //
  //   vel_y = 0;
  //   // player_y -= 1;
  //  }

}



////////////////////////////////////Private functions/////////////////////////////////////////////

void sonicClass::camera(){

  if(player_x < 42){
    draw_player_x = player_x;
  }
  else if(player_x >= 42){
    draw_player_x = 42;
  }

  draw_player_y = player_y; //FIX LATER

}




void sonicClass::running(){
  //if(joystick_mag > 0){
    if (joystick_dir == W) //Running left
        {
          mirror = true;
          currentState = RUN_LEFT;
            if (vel_x > 0)
            {
                vel_x -= ground_dec;
            }
            else if (vel_x > -top_vel)
            {
                vel_x -= ground_acc;
            }
        }
        else if (joystick_dir == E) //Running right
      {
          mirror = false;
          currentState = RUN_RIGHT;
          if (vel_x < 0)
          {
              vel_x += ground_dec;
          }
          else if (vel_x < top_vel)
          {
              vel_x += ground_acc;
          }

      }
      else{
        vel_x = min(abs(vel_x), ground_acc)*sign(vel_x);
      }

      run_animation(vel_x, player_x);


}



void sonicClass::jump(){

  if(pad_A){ //when jump button first pressed
    printf("JUMP\n" );
    jumping = true; //set jumping flag to true
    vel_y = -3; //initial jump velocity
  }

  if(jumping){ //subsequent motion after pressing button

      vel_y += gravity; //add gravity to vel_y, will cause 'decelleration' to 0, then increasing acelleration downwards after top of jump

      if(vel_y == 3){ //when we get to end of jump
        jumping = false;
        vel_y = 0;
      }
  }
}

void sonicClass::fall(){

  // //if(collision == false)
  // vel_y+= gravity;
  // player_y -= int(vel_y);


}

////////////////////////////////////////////Animations/////////////////////////////////////////

void sonicClass::run_animation(float vel_x, int player_x){
  //when running
  if(currentState == RUN_LEFT || currentState == RUN_RIGHT){
    //checking if vel_x is equal to player_x, every multiple of 2, means animation frame only changes every 2 changes in x position
    if(player_x % 3 == 0){
      animationLoop(0, 12);
    }

  }
  else if (vel_x == 0){
    spriteStateOutput = (sonicSpriteSet+0)->state;
    spriteStateOutput_nextState = (sonicSpriteSet+0)->nextState;
  }
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

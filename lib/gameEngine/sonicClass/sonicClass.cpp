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

  2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,1,2,2,2,1,1,1,1,1,2,2,2,1,2,2,2,2,2,1,1,1,1,2,2,1,2,2,2,2,1,1,1,1,1,1,1,2,
  2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,2,1,1,2,2,2,2,2,2,2,2,1,2,1,2,2,2,2,2,2,2,2,1,1,2,1,1,1,2,2,2,2,2,1,1,1,1,1,
  1,1,1,1,

};

static int sonic_walk_1[] = {

  2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,1,2,2,2,1,1,1,1,1,2,2,2,1,2,2,2,2,2,1,1,1,1,2,2,1,2,2,2,2,1,1,1,1,1,1,1,2,
  2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,1,2,2,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,1,1,2,2,2,2,2,1,1,1,2,2,
  2,2,2,2,

};
static int sonic_walk_2[] = {

  2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,1,2,2,2,1,1,1,1,1,2,2,2,1,2,2,2,2,2,1,1,1,1,2,2,1,2,2,2,2,1,1,1,1,1,1,1,2,
  2,2,2,2,1,1,1,1,1,2,2,1,1,2,2,1,2,2,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,1,1,2,2,2,2,1,1,1,2,2,2,1,1,2,2,2,2,1,1,2,2,2,1,1,2,2,2,2,2,
  2,2,2,2,

};
static int sonic_walk_3[] = {

  2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,1,2,2,2,1,1,1,1,1,2,2,2,1,2,2,2,2,2,1,1,1,1,2,2,1,2,2,2,2,1,1,1,1,1,1,1,2,
  2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,1,1,2,2,2,1,2,2,2,1,2,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,
  2,2,2,2,

};
static int sonic_walk_4[] = {

  2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,1,2,2,2,1,1,1,1,1,2,2,2,1,2,2,2,2,2,1,1,1,1,2,2,1,2,2,2,2,1,1,1,1,1,1,1,2,
  2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,2,1,1,2,2,2,2,2,2,1,1,2,2,2,1,1,1,2,2,2,2,1,1,1,2,2,2,
  2,2,2,2,

};
static int sonic_walk_5[] = {

  2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,1,2,2,2,1,1,1,1,1,2,2,2,1,2,2,2,2,2,1,1,1,1,2,2,1,2,2,2,2,1,1,1,1,1,1,1,2,
  2,2,2,1,2,2,1,1,1,2,2,1,2,2,1,2,1,1,1,1,1,1,1,2,2,1,2,1,1,1,1,2,2,2,1,1,1,2,2,1,1,1,2,2,2,2,1,1,1,2,1,1,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
  2,2,2,2,

};
static int sonic_walk_6[] = {

  2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,1,2,2,2,1,1,1,1,1,2,2,2,1,2,2,2,2,2,1,1,1,1,2,2,1,2,2,2,2,1,1,1,1,1,1,1,2,
  2,2,2,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,2,2,1,1,1,2,2,2,2,2,1,1,2,2,2,1,2,2,2,2,2,2,1,1,1,2,2,1,1,1,1,1,2,2,2,2,1,2,2,2,1,1,1,2,2,2,2,2,2,2,2,2,
  2,2,2,2,

};

static int sonic_run1[] = {

};
static int sonic_run2[] = {

};
static int sonic_run3[] = {

};
static int sonic_run4[] = {

};
static int sonic_spin[] = {

  2,2,2,1,1,1,2,2,2,2,1,1,1,1,1,1,1,2,2,1,1,1,1,1,2,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,
  1,2,2,2,2,1,1,1,2,2,2,

};


/* Sonic sprite set
*
* struct for holding a finite state machine of sonic's animation sprites.
*/
struct _sonicSpriteSet{


  string state;

  int *array; //Pointer to bitmap array
  int rows;
  int columns;
  string nextState;
};

_sonicSpriteSet sonicSpriteSet [13] = {

  {"stat", sonic_stationary, 12, 12,"walk1"},
  {"walk1", sonic_walk_1, 12, 12, "walk2"},
  {"walk2", sonic_walk_2, 12, 12, "walk3"},
  {"walk3", sonic_walk_3, 12, 12, "walk4"},
  {"walk4", sonic_walk_4, 12, 12, "walk5"},
  {"walk5", sonic_walk_5, 12, 12, "walk6"},
  {"walk6", sonic_walk_6, 12, 12, "walk1"},
  {"run1",  sonic_run1, 12, 12, "run2"},
  {"run2",  sonic_run2, 12, 12, "run3"},
  {"run3",  sonic_run3, 12, 12, "run4"},
  {"run4",  sonic_run4, 12, 12, "run1"},
  {"spin1", sonic_spin, 9, 9, "spin1"},

};

//gamepad inputs
bool pad_A;
bool pad_B;
bool pad_X;
bool pad_Y;
bool pad_start;
bool pad_back;
float joystick_mag;
Direction joystick_dir;


/////////////////////////////////////// Public functions ////////////////////////////////////////////////////////

/* init
*
* Initialises the variables that control sonic's behaviour.
*/
void sonicClass::init(Gamepad &pad){

  spriteStateOutput_nextState = (sonicSpriteSet+0)->nextState;
  mirror = false;

  draw_player_x = 0;
  draw_player_y = 28;

  vel_x = 0;
  vel_y = 0;

  gravity = 0.2;
  jumping = false;

  air_acc =  0.5+0.06375; //X axis acceleration while in air, slightly greater than when on ground
  air_dec = 0.8; //Air decelleration

  ground_acc = 0.5; //acceleration whilst running
  ground_dec = 0.5+1;

  top_vel = 6; //Sonic's maximum velocity

  currentState = STAND;
  sonic_x_direction = 1;
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

/* draw
*
* Draws sonic with the correct animation sprite
*/
void sonicClass::draw(N5110 &lcd){

  for (int i = 0; i < 12; i++) { //Itterate through animation FSM

    if((sonicSpriteSet+i)->state == spriteStateOutput){
      Bitmap sonic((sonicSpriteSet+i)->array, (sonicSpriteSet+i)->rows , (sonicSpriteSet+i)->columns);
      sonic.render(lcd, draw_player_x, draw_player_y, mirror); //Render sonic with correct sprite
      break;
    }
  }
}


/* update
*
* updates sonic's x & y positions within the class. Also sets boundaries to prevent going off screen.
*/
void sonicClass::update(int _player_x, int _player_y){

  player_x = _player_x;
  player_y = _player_y;

  player_x += int(vel_x)/2; //divisor scales character velocity.
  player_y += int(vel_y);

  //some boundaries for x & y values (prevents going off screen)
  if(player_x < 0){
    player_x = 0;
  }
  if(player_y < 0){
    player_y = 0;
  }

  camera();
  checkCharacterStates();

  //printf("\t\t\tX VELOCITY = %f\n", vel_x);
  //printf("\t\t\t\tplayer_x = %i\n", player_x);
  //printf("\t\t\t\t\tplayer_y = %i\n", player_y);

}



int sonicClass::getPlayerX(){

  return player_x;

}
int sonicClass::getPlayerY(){

  return player_y;

}

bool sonicClass::getDirectionX(){

  return mirror;

}



/* update
*
* updates sonic's x & y positions within the class. Also sets boundaries to prevent going off screen.
*/
void sonicClass::handleCollision(bool _collision_top, bool _collision_bottom){

  collision_top = _collision_top;
  collision_bottom = _collision_bottom;

  if(collision_bottom){
    vel_y = 0;
    currentState = STAND;
  }
  if(collision_top){


  }

}

////////////////////////////////////Private functions/////////////////////////////////////////////

void sonicClass::camera(){

  if(player_x < 42){
    draw_player_x = player_x;
  }
  else if(player_x >= 42){ //Centre sonic in middle of lcd
    draw_player_x = 42;
  }

  draw_player_y = player_y; //FIX LATER

}

void sonicClass::checkCharacterStates(){

  switch (currentState) {

    case STAND:
    stationary();
    if(pad_A){
      vel_y = -3;
      currentState = JUMP;
    }
    else if(joystick_mag > 0){
      currentState = RUN;
    }
    break;

    case RUN:
    running();
    if(player_x % 2 == 0){
      animationLoop(1, 6);
    }
    if(pad_A){
      vel_y = -3;
      currentState = JUMP;
    }
    if(collision_bottom == false){
      fall();
    }
    break;

    case JUMP:
    //animationLoop(12, 12);
    spriteStateOutput = (sonicSpriteSet+11)->state;
    jump();
    break;

    case SPINDASH:

    break;
  }
}





void sonicClass::stationary(){

  spriteStateOutput = (sonicSpriteSet+0)->state;
  spriteStateOutput_nextState = (sonicSpriteSet+0)->nextState;

}



void sonicClass::running(){

  //printf("%f\n", joystick_mag);

  if (joystick_dir == W) //Running left
  {
    mirror = true;
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
    if (vel_x < 0)
    {
      vel_x += ground_dec;
    }
    else if (vel_x < top_vel)
    {
      vel_x += ground_acc;
    }

  }
  else if(joystick_mag < 0.2 && joystick_mag > -0.2){
    //When stick released
    //vel_x = min(abs(vel_x), ground_dec)*sign(vel_x);
    vel_x = 0;
  }


}



void sonicClass::jump(){

  vel_y += gravity; //add gravity to vel_y, will cause 'decelleration' to 0,
  //then increasing acelleration downwards after top of jump

  if(joystick_dir == E){ //Left and right movement whilst jumping
    vel_x += air_acc;
  }
  else if(joystick_dir == W){
    vel_x -= air_acc;
  }
  else{
    vel_x -= min(abs(vel_x), air_dec)*sign(vel_x);
  }
  printf("\t\tY Velocity = %f\n",vel_y );
}


void sonicClass::fall(){

  vel_y+= gravity; //Accelerate y velocity

  if(vel_y > 6){ //Limit y velocity to 6
    vel_y = 6;
  }

}

void sonicClass::animationLoop(int i, int i_max){

  for(int i; i <= i_max; i++){
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

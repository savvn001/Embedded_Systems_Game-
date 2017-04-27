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

//gamepad inputs
 bool pad_A;
 bool pad_B;
 bool pad_X;
 bool pad_Y;
 bool pad_start;
 bool pad_back;
 float joystick_mag;
 Direction joystick_dir;



void sonicClass::init(Gamepad &pad){

  spriteStateOutput_nextState = (sonicSpriteSet+0)->nextState;
  mirror = false;

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

  currentState = STAND;
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



void sonicClass::update(int _player_x, int _player_y){

  player_x = _player_x;
  player_y = _player_y;

  //velFloat = (joystick_mag/2); //divisor sets vel, can be changed
  player_x += int(vel_x)/2; //divisor scales character velocity
  player_y += int(vel_y);

  //some boundaries for x & y values
  if(player_x < 0){
    player_x = 0;
  }
  if(player_y < 0){
    player_y = 0;
  }

  camera();
  checkCharacterStates();


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

void sonicClass::checkCharacterStates(){

  switch (currentState) {

    case STAND:
       stationary();
       if(pad_A){
         currentState = JUMP;
       }
       else if(joystick_mag > 0){
         currentState = RUN;
       }
       break;

     case RUN:
       running();
       if(pad_A){
         currentState = JUMP;
       }
       break;

     case JUMP:
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

    printf("%f\n", joystick_mag);

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
      else{
        //When stick released
        vel_x = min(abs(vel_x), ground_acc)*sign(vel_x);
      }

      if(player_x % 4 == 0){
        animationLoop(0, 12);
      }
}



void sonicClass::jump(){

  printf("JUMP\n" );
  vel_y = -3; //initial jump velocity
  vel_y += gravity; //add gravity to vel_y, will cause 'decelleration' to 0,
                    //then increasing acelleration downwards after top of jump


}

void sonicClass::fall(){

  vel_y+= gravity;

}

////////////////////////////////////////////Animations/////////////////////////////////////////

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

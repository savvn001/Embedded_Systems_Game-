#ifndef SONICCLASS_H
#define SONICCLASS_H

#include <mbed.h>
#include <N5110.h>
#include <Bitmap.h>
#include <Gamepad.h>
#include <cmath>
#include <vector>
#include <iostream>


class sonicClass
{

public:
  enum sonic_state{
    STAND,
    RUN,
    JUMP,
    SPINDASH,
  };



public:

  sonicClass();
  ~sonicClass();

  void init(Gamepad &pad);
  void getInput(Gamepad &pad);
  void draw(N5110 &lcd);
  void update(int player_x, int player_y);
  void handleCollision(bool _collision_top, bool _collision_bottom);

  int getPlayerX();
  int getPlayerY();
  bool getDirectionX();

private:




  void camera();

  void checkCharacterStates();

  //Character Movement functions
  void stationary();
  void running();

  void jump();
  void fall();

  void animationLoop(int i, int i_max);

  void updateArray();

  int sign(int value);


  //game mechanics variables
  float speedFloat;
  float vel_x;
  float vel_y;
  int player_x;
  int player_y;
  int draw_player_x;
  int draw_player_y;
  vector<float> sonicDirection;
  int top_vel;

  float gravity;
  float ground_dec;
  float jump_speed;
  bool jumping;
  float air_acc;
  float air_dec;
  float ground_acc;

  bool sonic_x_direction; //1 = right, 0 = left
  bool collision_top;
  bool collision_bottom;
  //Sonic spriteset
  static int sonic_stationary[];

  static int sonic_walk_1[];
  static int sonic_walk_2[];
  static int sonic_walk_3[];
  static int sonic_walk_4[];
  static int sonic_walk_5[];
  static int sonic_walk_6[];

  static int sonic_run1[];
  static int sonic_run2[];
  static int sonic_run3[];
  static int sonic_run4[];

  string spriteStateOutput;

  string spriteStateOutput_nextState;
  bool mirror;

  sonic_state currentState;
  bool collision_y;

};

#endif

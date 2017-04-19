#ifndef SONICCLASS_H
#define SONICCLASS_H

#include <mbed.h>
#include <N5110.h>
#include <Bitmap.h>
#include <Gamepad.h>
#include <cmath>

class sonicClass
{



public:

  sonicClass();
  ~sonicClass();

  void init(Gamepad &pad);
  void getInput(Gamepad &pad);
  void draw(N5110 &lcd);
  void update(Direction joystick_dir, float joystick_mag);

  int getPlayerPos();


private:


  void running(Direction joystick_dir, float joystick_mag);
  void run_animation(float speed_x, int player_x);

  void jump();
  void fall();

  void animationLoop(int i, int i_max);

  void updateArray();

  int sign(int value);
  //gamepad inputs
  bool  _pad_A;
  bool  _pad_B;
  bool  _pad_X;
  bool  _pad_Y;
  bool  _pad_back;
  bool  _pad_start;
  float  _joystick_mag;
  Direction  _joystick_dir;

  //game mechanics variables
  float speedFloat;
  float speed_x;
  float speed_y;
  int offset_x;
  int offset_y;
  int player_x;
  int player_y;
  int top_speed;

  float gravity;
  float ground_dec;
  float jump_speed;
  bool jumping;
  float air_acc;
  float ground_acc;

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

};

#endif

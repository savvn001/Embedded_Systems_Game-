#ifndef SONICCLASS_H
#define SONICCLASS_H

#include <mbed.h>
#include <N5110.h>
#include <Bitmap.h>
#include <Gamepad.h>

class sonicClass
{



public:

  sonicClass();
  ~sonicClass();

  void init();
  void draw(N5110 &lcd);
  void update(Direction joystick_dir, float joystick_mag);

  int getPlayerPos();


private:


  void running(Direction joystick_dir, float joystick_mag);
  void run_animation(Direction joystick_dir, float joystick_mag);

  void animationLoop(int i, int i_max, Direction joystick_dir);

  void updateArray();

  float speedFloat;
  float speed_x;
  float speed_y;
  int offset_x;
  int offset_y;
  int player_x;
  int player_y;
  bool mirror;
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


};

#endif

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

  void init(int map_x, int map_y);
  void draw(N5110 &lcd);
  void update(Direction joystick_dir, float joystick_mag);

  int getPlayerPos();


private:


  void running(Direction joystick_dir, float joystick_mag);

  void updateArray();

  float speedFloat;
  float speed_x;
  float speed_y;
  int offset_x;
  int offset_y;
  int player_x;
  int player_y;



};

#endif

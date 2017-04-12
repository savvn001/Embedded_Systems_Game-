#ifndef SONICCLASS_H
#define SONICCLASS_H

#include <mbed.h>
#include <N5110.h>
#include <Bitmap.h>
#include <Gamepad.h>
#include <maps/maps.h>

class sonicClass
{



public:

  sonicClass();
  ~sonicClass();

  void init();
  void draw(N5110 &lcd);
  void update(Direction joystick_dir, float joystick_mag, maps &Maps);




private:


  void running(Direction joystick_dir, float joystick_mag);
  void updateCamera();
  void updateArray();
  void updateMaps(maps &Maps);

  float speed;
  float speed_x;
  float speed_y;
  int map_x;
  int map_y;
  int player_x;
  int player_y;



};

#endif

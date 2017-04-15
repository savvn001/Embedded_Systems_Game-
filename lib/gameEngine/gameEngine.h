#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "mbed.h"
#include <N5110.h>
#include <Bitmap.h>
#include <Gamepad.h>
#include <sonicClass/sonicClass.h>
#include <maps/maps.h>

class gameEngine{

public:

      gameEngine();
      ~gameEngine();

      void init();
      void read_input(Gamepad &pad);
      void draw(N5110 &lcd, maps &Maps);
      void update(sonicClass &sonic, maps &Maps);

      bool pad_A;
      bool pad_B;
      bool pad_X;
      bool pad_Y;
      bool pad_start;
      bool pad_back;

      float joystick_mag;
      Direction joystick_dir;


private:

  int sonic_player_x;
  int sonic_player_y;




};

#endif

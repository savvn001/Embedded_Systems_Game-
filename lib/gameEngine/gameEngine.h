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

      void init(maps &Maps, sonicClass &sonic, Gamepad &pad);
      void read_input(Gamepad &pad, sonicClass sonic);
      void draw(N5110 &lcd, maps &Maps, sonicClass &sonic);
      void update(sonicClass &sonic, maps &Maps);



private:

  int sonic_player_x;
  int sonic_player_y;

  int ringCount;
  int score;

  char maps_collision;
};

#endif

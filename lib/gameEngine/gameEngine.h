#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "mbed.h"
#include <N5110.h>
#include <Bitmap.h>
#include <Gamepad.h>
#include <sonicClass/sonicClass.h>
#include <levels/ghzone/ghzone.h>

class gameEngine{

public:

      gameEngine();
      ~gameEngine();

      void init(ghzone &level, sonicClass &sonic, Gamepad &pad);
      void read_input(Gamepad &pad, sonicClass sonic);
      void draw(N5110 &lcd, ghzone &level, sonicClass &sonic);
      void update(sonicClass &sonic, ghzone &level);



private:

  int sonic_player_x;
  int sonic_player_y;

  int last_sonic_player_x;
  int last_sonic_player_y;


  int ringCount;
  int score;

  char level_collision;


  //Collision engine
  void collisionCheck(int sonic_player_x, int sonic_player_y, ghzone &level);
  bool checkTiles(int boxleft, int boxright, int boxtop, int boxbottom, ghzone &level);
  void collisionAction();

  int hitbox_left;
  int hitbox_right;
  int hitbox_top;
  int hitbox_bottom;

  bool collision_right;
  bool collision_left;
  bool collision_top;
  bool collision_bottom;
  char collision_id;

};

#endif

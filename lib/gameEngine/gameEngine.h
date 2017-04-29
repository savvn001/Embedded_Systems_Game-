#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "mbed.h"
#include <sstream>
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
  void collisionCheck(ghzone &level);

  void collisionRight(ghzone &level);
  void collisionLeft(ghzone &level);
  void collisionTop(ghzone &level);
  void collisionBottom(ghzone &level);

  bool checkTiles(int boxleft, int boxright, int boxtop, int boxbottom, ghzone &level);
  void collisionAction(char symbol_to_check);

  int hitbox_left;
  int hitbox_right;
  int hitbox_top;
  int hitbox_bottom;

  bool collision_top;
  bool collision_bottom;

  bool collision_x;
  bool collision_y;
  bool direction_x;
};

#endif

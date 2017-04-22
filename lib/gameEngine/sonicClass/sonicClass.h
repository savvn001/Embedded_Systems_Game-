#ifndef SONICCLASS_H
#define SONICCLASS_H

#include <mbed.h>
#include <N5110.h>
#include <Bitmap.h>
#include <Gamepad.h>
#include <cmath>
#include <vector>


class sonicClass
{

public:
  enum sonic_state{
    STAND,
    RUN_LEFT,
    RUN_RIGHT,
    JUMP,
  };

public:

  sonicClass();
  ~sonicClass();

  void init(Gamepad &pad);
  void getInput(Gamepad &pad);
  void draw(N5110 &lcd);
  void update();
  void collisionCheck(char collision);

  int getPlayerX();
  int getPlayerY();

private:




  void camera();

  void running();
  void run_animation(float speed_x, int player_x);

  void jump();
  void fall();

  void animationLoop(int i, int i_max);

  void updateArray();

  int sign(int value);
  //gamepad inputs
  bool pad_A;
  bool pad_B;
  bool pad_X;
  bool pad_Y;
  bool pad_start;
  bool pad_back;
  float joystick_mag;
  Direction joystick_dir;

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

  bool collision_right;
  bool collision_left;
  bool collision_top;
  bool collision_bottom;

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

  sonic_state currentState;


};

#endif

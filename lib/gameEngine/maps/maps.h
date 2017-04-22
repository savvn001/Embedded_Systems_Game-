#ifndef MAPS_H
#define MAPS_H

#include <mbed.h>
#include <N5110.h>
#include <Bitmap.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <math.h>

using namespace std;

#define SCREEN_WIDTH 84
#define SCREEN_HEIGHT 48
#define TILE_WIDTH 4
#define TILE_HEIGHT 4
#define TILES_ACROSS_SCREEN ((SCREEN_WIDTH + TILE_WIDTH - 1) / TILE_WIDTH)
#define TILES_DOWN_SCREEN ((SCREEN_HEIGHT + TILE_HEIGHT - 1) / TILE_HEIGHT)

#define TILES_ACROSS_MAP 21
#define TILES_DOWN_MAP 12

#define NO_OF_SPRITES 4

#define NO_OF_SCREENS_ACROSS 2
#define NO_OF_SCREENS_DOWN 1

class maps
{

public:

  maps();
  ~maps();



  void init();
  void drawMap(N5110 &lcd);
  void updateMap(int player_x, int player_y);
  char collisionCheck(int player_x, int player_y);

private:

  void drawTile(char spriteSymbol, int xpos, int ypos, N5110 &lcd);
  char getSymbol(int x, int y);

  int offset_x;
  int offset_y;

  int _player_x;
  int _player_y;

  int toplefttile_x;
  int toplefttile_y;

  //Map arrays
  static char map1_1[12][21];
  static char map1_2[12][21];

  static char map1_data[12][42];



  //Map objects
  static int air[];
  static int level1ground[];
  static int ring[];
  static int solid_tile[];

  //Collision engine
  bool tileCheck(int index_x, int index_y);
  int hitbox_left;
  int hitbox_right;
  int hitbox_top;
  int hitbox_bttm;

  bool collision_x;
  bool collision_y;
  char collision_id;




};

#endif

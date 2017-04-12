#ifndef MAPS_H
#define MAPS_H

#include <mbed.h>
#include <N5110.h>
#include <Bitmap.h>
#include <mapData/mapData.h>
#include <sonicClass/sonic_spritesheet.h> //DELETE AFTER
//#include <sonicClass/sonicClass.h>

class maps
{
  friend class sonicClass;

public:

  maps();
  ~maps();



  void init();
  void drawMap(N5110 &lcd);
  void updateMap();
  static int map1_data [12][21];
  int level1ground_data[];

private:

  int _map_x;
  int _map_y;
  int _player_x;
  int _player_y;



};

#endif

#include "maps.h"

int maps::map1_data [12][21] = {

  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,2,0,2,0,2,0,2,0,2,0,2},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},



};

int level1ground_data[] = {

  1,1,1,1,
  1,1,0,0,
  0,0,1,1,
  0,0,1,1


};



Bitmap level1ground(level1ground_data, 4,4);

maps::maps()
{


}

maps::~maps(){


}

void maps::init(){

  _map_x = 0;
  _map_y = 0;

}

void maps::drawMap(N5110 &lcd){

  //draw map
  for (int draw_y = _map_y; draw_y < _map_y + 12; draw_y++) {

    for (int draw_x = _map_x; draw_x < _map_x + 21; draw_x++) {
      if(map1_data[draw_y][draw_x] == 1){

        level1ground.render(lcd, 4*draw_x, 4*draw_y);
      }
      else if(map1_data[draw_y][draw_x] == 2){
        lcd.drawCircle(4*draw_x+1, 4*draw_y, 2, 0);
      }
      else if(map1_data[draw_y][draw_x] == 3){
        //draw rectangle (no. that is multiplied here is the tile size factor, in this case 4, tiles are 4x4 pixels)
        lcd.drawRect((4*draw_x), (4*draw_y), 4, 4, 1);
      }
      else if(map1_data[draw_y][draw_x] == 4){
        //draw sonic
        Bitmap sprite_stat(sonic_stationary2, 12, 12);
        sprite_stat.render(lcd, 4*_player_x, 4*_player_y);

      }


    }

  }

printf("                                                        map_x in maps = %i\n\n", _map_x);

}

void maps::updateMap(){

  // _map_x = sonic.map_x;
  // _map_y = sonic.map_y;
  // _player_x = sonic.player_x;
  // _player_y = sonic.player_y;



}

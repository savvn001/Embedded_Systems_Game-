#include "maps.h"

maps::maps()
{


}

maps::~maps(){


}

gameObjects sprites;

void maps::init(){

sprites.init();

}

void maps::drawMap(N5110 &lcd){

  //draw map
  for (int draw_y = 0; draw_y < NO_OF_SCREENS_DOWN*12; draw_y++) {

    for (int draw_x = 0; draw_x < NO_OF_SCREENS_ACROSS*21; draw_x++) {

        string symbol = sprites.getSymbol(draw_x, draw_y);
        sprites.drawTile(symbol, 4*draw_x-offset_x, 4*draw_y-offset_y, lcd);
        sprites.drawSonic( _player_x, _player_y, "stat", lcd);

    }

  }


}

void maps::updateMap(int player_x, int player_y){

    _player_x = player_x;
    _player_y = 32; //only for now, change to = player_y after

    if (_player_x < 21/2){
      offset_x = 0;
    }
    // else if (player_x > NO_OF_SCREENS_ACROSS*21 - (21 / 2)){
    //   offset_x =  NO_OF_SCREENS_ACROSS*21 - 21;
    // }
    else {
      offset_x = 4*_player_x - (21 / 2);
    }

  printf("                                 player x = %i\n\n ", _player_x);
  printf("                                                 offset x = %i\n\n ", offset_x);

}

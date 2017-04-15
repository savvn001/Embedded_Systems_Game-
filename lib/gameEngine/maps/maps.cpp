#include "maps.h"

maps::maps()
{


}

maps::~maps(){


}

gameObjects sprites;

void maps::init(){



}

void maps::drawMap(N5110 &lcd){

  //draw map
  for (int draw_y = 0; draw_y < 12; draw_y++) {

    for (int draw_x = 0; draw_x < 21; draw_x++) {

        string symbol = sprites.getSymbol(draw_x, draw_y);
        sprites.drawTile(symbol, 4*draw_x-offset_x, 4*draw_y-offset_y, lcd);

    }

  }


}

void maps::updateMap(int player_x, int player_y){

    if (player_x < int(21/2)){
      offset_x = 0;
    }
    else if (player_x > 84 - 21 / 2){
      offset_x = 84-21;
    }
    else {
      offset_x = player_x - 21 / 2;
    }

   toplefttile_x = player_x / TILE_WIDTH;
   toplefttile_y = player_y / TILE_HEIGHT;

  printf("                                 player x = %i\n\n ", player_x);
  printf("                                                 offset x = %i\n\n ", offset_x);

}

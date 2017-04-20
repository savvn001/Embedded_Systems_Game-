#include "maps.h"

maps::maps()
{


}

maps::~maps(){


}

string maps::map1_1[12][21] = {

  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," ","*"," ","*"," ","*"," ","*"," ","*"," ","*"},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {"t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t"},
  {"=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","="},


};

string maps::map1_2[12][21] = {

  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," ","t"," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," ","t"," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," ","t"," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," ","*"," ","t"," "," ","*"," ","*"," ","*"," ","*"," ","*"," ","*"},
  {" "," "," "," "," "," "," ","t"," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {"t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t"},
  {"=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","="},


};

string maps::map1_data[NO_OF_SCREENS_DOWN*12][NO_OF_SCREENS_ACROSS*21] = {};




////////////////////////////////************In game map sprites*************//////////////////////////////////////
static int air[] = { //empty space

  0,0,0,0,
  0,0,0,0,
  0,0,0,0,
  0,0,0,0

};

static int level1ground[] = { //level 1 ground tile

  1,1,1,1,
  1,1,0,0,
  0,0,1,1,
  0,0,1,1,

};

static int ring[] = { //ring

  0,1,1,0,
  1,0,0,1,
  1,0,0,1,
  0,1,1,0};

static int solid_tile[] = {  //solid black tile

  1,1,1,1,
  1,1,1,1,
  1,1,1,1,
  1,1,1,1};

struct spritePropertiesStruct{

    string symbol;
    int *array;
    bool solid;
    int rows;
    int columns;

  };


spritePropertiesStruct mapSpriteSet [4] = {

  {" ", air,  false, 4, 4},
  {"t",level1ground, true, 4,4},
  {"*", ring,  false, 4,4},
  {"=", solid_tile,  true, 4,4},

};



gameObjects sprites;

void maps::init(){

  //concentuate all arrays to single map array
  for (int j = 0; j < 12; ++j) {

    for (int i = 0; i < 21; ++i)
    {

        map1_data[j][i] = map1_1[j][i];
        map1_data[j][i+21] = map1_2[j][i];
    }
  }


  //printing map in serial monitor
  for (int y=0; y< NO_OF_SCREENS_DOWN*12; y++)
  {

      for(int x = 0; x < NO_OF_SCREENS_ACROSS*21; x++){

      cout<<map1_data[y][x];
  }
     cout<< "\n";

     }



}

void maps::drawMap(N5110 &lcd){

  //draw map
  for (int draw_y = 0; draw_y < NO_OF_SCREENS_DOWN*12; draw_y++) {

    for (int draw_x = 0; draw_x < NO_OF_SCREENS_ACROSS*21; draw_x++) {

        string symbol = getSymbol(draw_x, draw_y); //get string from element in map array
        drawTile(symbol, 4*draw_x-offset_x, 4*draw_y-offset_y, lcd); //draw tile, offset by x & y offsets

    }

  }


}

void maps::updateMap(int player_x, int player_y){

    _player_x = player_x;
    _player_y = 28; //only for now, change to = player_y after

    if (_player_x < 84/2){
      offset_x = 0;
    }
    //FIX THIS LATER
    // else if (player_x > NO_OF_SCREENS_ACROSS*21 - (21 / 2)){
    //   offset_x =  NO_OF_SCREENS_ACROSS*21 - 21;
    // }
    else {
      offset_x = _player_x - (84 / 2);
    }

}


bool maps::collisionCheck(int player_x){


  if((player_x + 10) % 4 == 0){   //check if edge of 'hitbox' intersects with 'lines' of map array, ie. is a multiple of 4
    hitbox_r = (player_x+10)/4;
    printf("hitbox R coordinate %i\n", hitbox_r);
    symbol_coll = getSymbol(hitbox_r,9);  //get string for that tile element in map array
    }
  cout << "                 symbol in maps = " << symbol_coll;
    //map whether that tile is solid or not to 'collision' boolean
  for (int i = 0; i < 4; i++) {

    if((mapSpriteSet+i)->symbol == symbol_coll){
      collision = (mapSpriteSet+i)->solid;
      break;
    }
  }

return collision;

}

//////////////////////////////////////////////////////////Private functions///////////////////////////////////////////////////////

string maps::getSymbol(int x, int y){

  return map1_data[y][x];

}


void maps::drawTile(string spriteSymbol, int xpos, int ypos, N5110 &lcd){

  for (int i = 0; i < 4; i++) {

    if((mapSpriteSet+i)->symbol == spriteSymbol){

      Bitmap spriteBitmap((mapSpriteSet+i)->array, (mapSpriteSet+i)->rows, (mapSpriteSet+i)->columns);
      spriteBitmap.render(lcd, xpos, ypos, false);
      break;

    }
  }
}

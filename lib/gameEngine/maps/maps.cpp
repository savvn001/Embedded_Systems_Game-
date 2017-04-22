#include "maps.h"

maps::maps()
{


}

maps::~maps(){


}

char maps::map1_1[12][21] = {

  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*'},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {'t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t'},
  {'=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','='},


};

char maps::map1_2[12][21] = {

  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ','t',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ','t',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ','t',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ','*',' ','t',' ',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*'},
  {' ',' ',' ',' ',' ',' ',' ','t',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {'t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t'},
  {'=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','='},


};

char maps::map1_data[NO_OF_SCREENS_DOWN*12][NO_OF_SCREENS_ACROSS*21] = {};




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

    char symbol;
    int *array;
    bool solid;
    int rows;
    int columns;
    bool slope; //true if tile is slope, needs closer examination for collision engine
  };


spritePropertiesStruct mapSpriteSet [4] = {

  {' ', air,  false, 4, 4, false},
  {'t',level1ground, true, 4,4, false},
  {'*', ring,  false, 4,4, false},
  {'=', solid_tile,  true, 4,4, false},

};

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
     cout<< '\n';

     }



}

void maps::drawMap(N5110 &lcd){

  //draw map
  for (int draw_y = 0; draw_y < NO_OF_SCREENS_DOWN*12; draw_y++) {

    for (int draw_x = 0; draw_x < NO_OF_SCREENS_ACROSS*21; draw_x++) {

        char symbol = getSymbol(draw_x, draw_y); //get char from element in map array
        drawTile(symbol, 4*draw_x-offset_x, 4*draw_y-offset_y, lcd); //draw tile, offset by x & y offsets

    }

  }


}

void maps::updateMap(int player_x, int player_y){

    _player_x = player_x;
    _player_y = player_y; //only for now, change to = player_y after

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


char maps::collisionCheck(int player_x, int player_y){

  int rightEdge = player_x+11;
  int bottomEdge = player_y+13;

  int hitbox_left = (player_x -= player_x % 4)/4;
  int hitbox_right = (rightEdge -= rightEdge % 4)/4;
  int hitbox_top = (player_y -= player_y % 4)/4;
  int hitbox_bttm = (bottomEdge -= bottomEdge % 4)/4;

  if(hitbox_left < 0){
    hitbox_left = 0;
  }
  if(hitbox_right > NO_OF_SCREENS_ACROSS*21) {
    hitbox_right = NO_OF_SCREENS_ACROSS*21;
  }
  if(hitbox_top < 0){
    hitbox_top = 0;
  }
  if(hitbox_bttm > NO_OF_SCREENS_DOWN*12) {
    hitbox_bttm = NO_OF_SCREENS_DOWN*12;
  }


 for (int i = 0; i < 3; i++) {
   collision_x = tileCheck(hitbox_right, hitbox_bttm-i); //check tiles right side of sonic
   collision_y = tileCheck(hitbox_right-i, hitbox_bttm); //check tiles underneath sonic
 }

 return collision_id;
}









//////////////////////////////////////////////////////////Private functions///////////////////////////////////////////////////////



char maps::getSymbol(int x, int y){

  return map1_data[y][x];

}


void maps::drawTile(char spriteSymbol, int xpos, int ypos, N5110 &lcd){

  for (int i = 0; i < 4; i++) {

    if((mapSpriteSet+i)->symbol == spriteSymbol){

      Bitmap spriteBitmap((mapSpriteSet+i)->array, (mapSpriteSet+i)->rows, (mapSpriteSet+i)->columns);
      spriteBitmap.render(lcd, xpos, ypos, false);
      break;

    }
  }
}

bool maps::tileCheck(int index_x, int index_y){

  bool _collision;

  for (int i = 0; i < 4; i++) { //Loop through tile struct

    char symbol_check = map1_data[index_y][index_x]; //check symbol of tile in question

    if((mapSpriteSet+i)->symbol == symbol_check){

      _collision = (mapSpriteSet+i)->solid;

      switch (symbol_check) {
        case '*':
          map1_data[index_y][index_x] = ' ';
      }


      break;
    }
  }

return _collision;

}

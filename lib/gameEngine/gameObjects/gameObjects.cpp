/*
everything to 4x4 'tile'

" " = empty
"t" =  level 1 ground tile pattern
"*" =  ring
"=" = solid block

*/

#include "gameObjects.h"

gameObjects::gameObjects()
{


}

gameObjects::~gameObjects(){


}

string gameObjects::map1_data[12][21] = {

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
    bool bWall; //true if solid (cannot pass thru)
    int rows;
    int columns;

  };


spritePropertiesStruct SpriteSet [4] = {

  {" ", air,  false, 4, 4},
  {"t",level1ground, true, 4,4},
  {"*", ring,  false, 4,4},
  {"=", solid_tile,  true, 4,4},

};

string gameObjects::getSymbol(int x, int y){

  return map1_data[y][x];


}

void gameObjects::drawTile(string spriteSymbol, int xpos, int ypos, N5110 &lcd){

  for (int i = 0; i < 4; i++) {

    if((SpriteSet+i)->symbol == spriteSymbol){

      Bitmap spriteBitmap((SpriteSet+i)->array, (SpriteSet+i)->rows, (SpriteSet+i)->columns);
      spriteBitmap.render(lcd, xpos, ypos);
      break;

    }


  }

}

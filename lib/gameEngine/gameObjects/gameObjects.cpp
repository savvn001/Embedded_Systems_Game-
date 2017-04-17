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

string gameObjects::map1_1[12][21] = {

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

string gameObjects::map1_2[12][21] = {

  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," ","t","t","t","t","t"," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {" "," "," "," "," ","*"," "," "," "," ","*"," ","*"," ","*"," ","*"," ","*"," ","*"},
  {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
  {"t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t","t"},
  {"=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","=","="},


};

string gameObjects::map1_data[NO_OF_SCREENS_DOWN*12][NO_OF_SCREENS_ACROSS*21] = {};




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
    bool bWall; //true if solid (cannot pass thru)
    int rows;
    int columns;

  };


spritePropertiesStruct mapSpriteSet [4] = {

  {" ", air,  false, 4, 4},
  {"t",level1ground, true, 4,4},
  {"*", ring,  false, 4,4},
  {"=", solid_tile,  true, 4,4},

};



////////////////////////////////************Functions*************//////////////////////////////////////

void gameObjects::init(){

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

string gameObjects::getSymbol(int x, int y){

  return map1_data[y][x];

}


void gameObjects::drawTile(string spriteSymbol, int xpos, int ypos, N5110 &lcd){

  for (int i = 0; i < 4; i++) {

    if((mapSpriteSet+i)->symbol == spriteSymbol){

      Bitmap spriteBitmap((mapSpriteSet+i)->array, (mapSpriteSet+i)->rows, (mapSpriteSet+i)->columns);
      spriteBitmap.render(lcd, xpos, ypos, false);
      break;

    }
  }
}

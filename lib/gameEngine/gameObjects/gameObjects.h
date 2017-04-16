/*

stores sprite data and maps


*/

#include <stdio.h>
#include <string>
#include <Bitmap.h>
#include <N5110.h>

#include <iostream>
#include <algorithm>
#include <iterator>

#define NO_OF_SCREENS_ACROSS 2
#define NO_OF_SCREENS_DOWN 1

using namespace std;



class gameObjects{

friend class maps;

public:

  gameObjects();
  ~gameObjects();


private:

  void init();
  void drawTile(string spriteSymbol, int xpos, int ypos, N5110 &lcd);

  static string map1_1[12][21];
  static string map1_2[12][21];

  static string map1_data[12][42];

  static int air[];
  static int level1ground[];
  static int ring[];
  static int solid_tile[];

  string getSymbol(int x, int y);




};

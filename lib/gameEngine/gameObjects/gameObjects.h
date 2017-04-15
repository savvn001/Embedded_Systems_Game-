/*

stores sprite data and maps


*/

#include <stdio.h>
#include <string>
#include <Bitmap.h>
#include <N5110.h>

using namespace std;



class gameObjects{

friend class maps;

public:

  gameObjects();
  ~gameObjects();


private:

  void drawTile(string spriteSymbol, int xpos, int ypos, N5110 &lcd);

  static string map1_data[12][21];

  static int air[];
  static int level1ground[];
  static int ring[];
  static int solid_tile[];

  string getSymbol(int x, int y);




};

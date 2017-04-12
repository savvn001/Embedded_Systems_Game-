#include "mbed.h"
#include <N5110.h>
#include <Bitmap.h>
#include <Gamepad.h>




class gameMenu{

public:

      gameMenu();
      ~gameMenu();

      void drawMenu(N5110 &lcd);
      void menuInput(Gamepad &pad);
      void loadMap();






private:






};

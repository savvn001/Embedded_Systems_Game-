#include "mbed.h"
#include <N5110.h>
#include <Bitmap.h>
#include <Gamepad.h>
#include <gameEngine.h>
#include <gameMenu.h>
//#include <gameObjects/graphics.h>
//#include <SDFileSystem.h>

//type this into cmd to push to github: git push --set-upstream Main master



//////////////Objects//////////////

N5110 lcd(PTC9,PTC0,PTC7,PTD2,PTD1,PTC11);
Gamepad pad;
gameEngine engine;
Serial serial(USBTX, USBRX);  // for debugging to PC
gameMenu menu;
sonicClass sonic;
maps Maps;

////////////Prototypes//////////////

void init_K64F();
void renderLCD();
void splashScreen();
void splashScreen2();
void menuScreen();

//////////////Functions//////////////

int main()
{

  serial.baud(115200);

  //initialise
  init_K64F();

  splashScreen();
  splashScreen2();
  menuScreen();

  //Main game loop when in a level
  //read input > update game state >  render display
  while(1){

      engine.read_input(pad);
      engine.update(sonic, Maps);
      renderLCD();
      wait(1.0f/60); //small delay, sets frame rate

  }


}

void init_K64F(){
  //initialise board and lcd
  lcd.init();
  pad.init();

  lcd.normalMode();      // normal colour mode
  lcd.setBrightness(0.5); // put LED backlight on 50%

  engine.init(Maps, sonic);

}

void renderLCD(){
  lcd.clear();
  engine.draw(lcd, Maps, sonic);
  lcd.refresh();
}

void splashScreen(){

    lcd.clear();
    lcd.printString(" Nicholas",15,1);
    lcd.printString(" Savva",15,2);
    lcd.printString(" ELEC2645",13,3);
    lcd.refresh();

    wait(2);

}

void splashScreen2(){

  lcd.clear();
  //splashScreenLogo.render(lcd,10,10);
  lcd.refresh();
  wait(2);

}

void menuScreen(){

  while(pad.check_event(Gamepad::B_PRESSED) == false){
    menu.drawMenu(lcd);
    menu.menuInput(pad);
  }
  //menu.loadMap();


}

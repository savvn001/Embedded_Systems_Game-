#include <gameMenu.h>

gameMenu::gameMenu(){

}

gameMenu::~gameMenu(){

}

int level_selector = 10;
int fsm[3] = {12,27,43}; //Simple finite state machine for y coordinate of level selector
int state = 0;

void gameMenu::drawMenu(N5110 &lcd){

    lcd.clear();
    lcd.drawCircle(4, level_selector, 2, 1);
    lcd.printString(" Green Hill Zone",7,1);
    lcd.printString(" Level2",7,3); //20 y value
    lcd.printString(" Level3",7,5);
    lcd.refresh();

}

void gameMenu::menuInput(Gamepad &pad){

    if(pad.check_event(Gamepad::A_PRESSED)){
      level_selector = fsm[state];
      switch(state) {
            case 0:
                state = 1;
                break;
            case 1:
                state = 2;
                break;
            case 2:
                state = 0;
                break;
        }
    }

    wait(0.1); //small delay

}

void gameMenu::loadMap(){


}

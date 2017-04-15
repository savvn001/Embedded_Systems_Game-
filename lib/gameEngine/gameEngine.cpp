#include "gameEngine.h"


Serial serial2(USBTX, USBRX);


gameEngine::gameEngine(){

}

gameEngine::~gameEngine(){

}

void gameEngine::init(){




}


void gameEngine::read_input(Gamepad &pad)
{

    pad_A = pad.check_event(Gamepad::A_PRESSED);
    pad_B = pad.check_event(Gamepad::B_PRESSED);
    pad_X = pad.check_event(Gamepad::X_PRESSED);
    pad_Y = pad.check_event(Gamepad::Y_PRESSED);
    pad_back = pad.check_event(Gamepad::BACK_PRESSED);
    pad_start = pad.check_event(Gamepad::START_PRESSED);
    joystick_mag = pad.get_mag();
    joystick_dir = pad.get_direction();

    //Testing buttons with printf
    // if(pad_A){
    //   serial2.printf ("%s \n", "A");
    // }
    // if(pad_B){
    //   serial2.printf ("%s \n", "B");
    // }
    // if(pad_X){
    //   serial2.printf ("%s \n", "X");
    // }
    // if(pad_Y){
    //   serial2.printf ("%s \n", "Y");
    // }
    // if(pad_start){
    //   serial2.printf ("%s \n", "start");
    // }
    // if(pad_back){
    //   serial2.printf ("%s \n", "back");
    // }
    // serial2.printf ("%s \n", joystick_dir);
    // serial2.printf ("%f \n", joystick_mag);

}

/*




*/

void gameEngine::draw(N5110 &lcd, maps &Maps){

  Maps.drawMap(lcd);


}

void gameEngine::update(sonicClass &sonic, maps &Maps){

  sonic.update(joystick_dir, joystick_mag);
  sonic_player_x = sonic.getPlayerPos();
  Maps.updateMap(sonic_player_x, sonic_player_y);

}





/////////////////private functions/////////////////////
/*
  Drawmap function
  Draw

*/

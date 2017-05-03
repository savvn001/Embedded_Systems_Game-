#include "gameEngine.h"

Serial serial2(USBTX, USBRX);

gameEngine::gameEngine(){

}

gameEngine::~gameEngine(){

}

/** init
*
*  Initialise the game engine, sets player x & y co ordinates and ring count.
*/
void gameEngine::init(ghzone &level, sonicClass &sonic, Gamepad &pad){

  level.init();
  sonic.init(pad);

  sonic_player_x = 40;
  sonic_player_y = 28;

  ringCount = 0;

  ringFX_play = false;
}

/** read_input
*
*  Simply to call input method from 'sonic' class
*/
void gameEngine::read_input(Gamepad &pad, sonicClass sonic)
{

  sonic.getInput(pad);
  ringFX(pad);
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

/** draw
*
*  Call level drawMap method and sonic draw method.
*  Displays ring count on screen.
*/
void gameEngine::draw(N5110 &lcd, ghzone &level, sonicClass &sonic){

  level.drawMap(lcd);
  sonic.draw(lcd); //Sonic is drawn after map (gets drawn ontop of map)

  //Converting ring count integer to string using c++ <sstream> lib
  stringstream convert;
  convert << ringCount;
  string s_ringCont = convert.str();

  //In game HUD
  lcd.drawCircle(3, 3, 2, 0);
  lcd.printString("=",8,0);
  lcd.printString(s_ringCont.c_str(),15,0);
}

/** update
*
* Updates sonic's x & y values, using values from collision functions
*/
void gameEngine::update(sonicClass &sonic, ghzone &level){


  last_sonic_player_x = sonic_player_x; //x & y co-ordinates before user input
  last_sonic_player_y = sonic_player_y;

  sonic.update(sonic_player_x, sonic_player_y); //input to sonic class, values get changed

  sonic_player_x = sonic.getPlayerX(); //Get X & Y values from sonic class
  sonic_player_y = sonic.getPlayerY();

  direction_x = sonic.getDirectionX(); //Get direction from sonic class

  collisionCheck(level);

  sonic.handleCollision(collision_top, collision_bottom);

  level.updateMap(sonic_player_x, sonic_player_y); //Offset camera, fix later
}


/** collisionCheck
*
* Calls functions for checking collisions on top, bottom, left and right.
*/
void gameEngine::collisionCheck(ghzone &level){

  //check for collisions across X
  collision_x = false;
  collision_y = false;
  collision_top = false;
  collision_bottom = false;

  switch(direction_x){

    case false:
    collisionRight(level);
    case true:
    collisionLeft(level);
  }

  collisionTop(level);
  collisionBottom(level);

}

/** collisionRight
*
*  Checks for collions right of sonic, (whilst moving right)
*
*  Each time user input changes X or Y position, function iterates through his previous position
*  up to his new position. When a collision with a solid tile is detected within sonic's 'hitbox',
*  along this path, a boolean is set to true, and his position set to just before where the solid tile
*  is in the map.
*
*/
void gameEngine::collisionRight(ghzone &level){

  //Iterate through x co-ordinates, from sonic's last X position to where his new X position is after user input
  for (int x_start = last_sonic_player_x; x_start <= sonic_player_x; x_start++) {
    //Defining co ordinates for sonic's 'hitbox'
    int hitbox_left =  (int)(x_start+1)/4; //X
    int hitbox_right = (int)(x_start+12)/4;//X

    int hitbox_top =  (int)(sonic_player_y+1)/4;//Y
    int hitbox_bttm = (int)(sonic_player_y+10)/4; //Y
    //Check tiles in hitbox
    collision_x = checkTiles(hitbox_left, hitbox_right, hitbox_top, hitbox_bttm, level);

    //When collision with solid tile detected
    if(collision_x){
      sonic_player_x = x_start-1;
      break;
    }
  }
}

/** collisionLeft
*
* Same as collisionLeft but for collisions whilst moving left (Iteration direction is negative).
*/
void gameEngine::collisionLeft(ghzone &level){

  for (int x_start = last_sonic_player_x; x_start >= sonic_player_x; x_start--) {

    int hitbox_left =  (int)(x_start-2)/4; //X
    int hitbox_right = (int)(x_start+12)/4;//X

    int hitbox_top =  (int)(sonic_player_y+1)/4;//Y
    int hitbox_bttm = (int)(sonic_player_y+10)/4; //Y

    collision_x = checkTiles(hitbox_left, hitbox_right, hitbox_top, hitbox_bttm, level);

    //When collision with solid tile detected
    if(collision_x){
      sonic_player_x = x_start+1;
      break;
    }
  }
}

/** collisionBottom
*
* For collisions below sonic, whilst falling for example.
*/
void gameEngine::collisionBottom(ghzone &level){

  for (int y_start = last_sonic_player_y; y_start <= sonic_player_y; y_start++) {

    int hitbox_left =  (int)(sonic_player_x-2)/4; //X
    int hitbox_right = (int)(sonic_player_x+12)/4;//X

    int hitbox_top =  (int)(y_start+1)/4;//Y
    int hitbox_bttm = (int)(y_start+12)/4; //Y

    collision_y = checkTiles(hitbox_left, hitbox_right, hitbox_top, hitbox_bttm, level);

    //When collision with solid tile detected
    if(collision_y){
      collision_bottom = true;
      sonic_player_y = y_start-1;
      break;
    }
  }

}

/** collisionTop
*
* For collisions above sonic.
*/
void gameEngine::collisionTop(ghzone &level){

  for (int y_start = last_sonic_player_y; y_start >= sonic_player_y; y_start--) {

    int hitbox_left =  (int)(sonic_player_x-2)/4; //X
    int hitbox_right = (int)(sonic_player_x+12)/4;//X

    int hitbox_top =  (int)(y_start+1)/4;//Y
    int hitbox_bttm = (int)(y_start+12)/4; //Y

    collision_y = checkTiles(hitbox_left, hitbox_right, hitbox_top, hitbox_bttm, level);

    //When collision with solid tile detected
    if(collision_y){
      collision_top = true;
      sonic_player_y = y_start+1;
      break;
    }
  }
}

/** checkTiles
*
*  Itterates through tiles in hitbox. If any solid tiles are detected, returns TRUE.
*
* @param boxleft - x value of left edge of hitbox
* @param boxright - x value of right edge of hitbox
* @param boxtop - y value of top edge of hitbox
* @param boxbottom - y value of bottom edge of hitbox
*/
bool gameEngine::checkTiles(int boxleft, int boxright, int boxtop, int boxbottom, ghzone &level){

  bool collision = false;

  //Collisions on left & right
  for(int i = boxleft; i<=boxright; i++)
  {
    for(int j = boxtop; j<=boxbottom; j++)
    {
      char symbol_check = level.getTile(i, j); //check symbol of tile in question

      if(level.checkSolid(symbol_check)){
        collision = true;
      }

      switch (symbol_check) {
        case '*':
        ringCount++;
        ringFX_play = true;
        level.setTile(i, j, ' ');
      }

    }
  }
  return collision;
}

/** ringFX
*
*  Plays sound effect when ring is collected
*/
void gameEngine::ringFX(Gamepad &pad){

  if(ringFX_play){

    pad.tone(4186.009, 0.2);
    wait_ms(30);
    pad.tone(5274.042, 0.2);
    wait_ms(30);
    pad.tone(6271.928, 0.2);
  }

  ringFX_play = false;

}

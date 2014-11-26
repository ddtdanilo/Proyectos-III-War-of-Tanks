
// --------Main Setups and Draws

void setup () {
  size (800, 640 );
  // define values for class Rectangle
  setup_serial();
  setup_audio();
  setup_camera();
  play_Intro();
  Font=loadFont("OCRAExtended-48.vlw");
  Background=loadImage("background.jpg");
  textFont(Font,40);
  textXPos = width/2-250;
  learnPos = textXPos+400;
  // define objects of class Rectangle
  rectButtonBoard1 = new Rectangle(textXPos, textYPos[0], 500, 100, chooseGameName[0], statusText[0], 0);
  rectButtonBoard2 = new Rectangle(textXPos, textYPos[1], 500, 100, chooseGameName[1], statusText[1], 1);  
  rectLearnmore    = new Rectangle(textXPos, textYPos[2], 500, 100, chooseGameName[2], statusText[2], 2);
}

void draw () {
  background(0);
  tint(255,255,255,150);
  image(Background,0,0);
  noTint();

  switch (state) {
  case stateWelcomeScreen:
    handleStateShowWelcomeScreen();
    break;
  case statePlay:
    handleStatePlay();
    break;
  case stateLearnMore:
    handleStateLearnMore();
    break;
  case stateAfterAGame:
    handleStateAfterAGame();
    break;
  case stateHistory:
    handleStateHistory();
    break;  
  case stateBattlefield:
    handleStateBattlefield();
    break;   
  default:
    // error 
    println("Estado indefinido, error: " 
      + state
      + ".");
    exit();
    break;
  } // switch
} // func 
//


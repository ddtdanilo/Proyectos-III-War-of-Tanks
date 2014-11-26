
// Inputs Mouse

// each state has an own mousePressed routine 

void mousePressed() {
  // depending on the state choose mousePressed routine
  switch (state) {
  case stateWelcomeScreen:
    mousePressedStateWelcomeScreen();
    break;
  case statePlay:
    mousePressedStatePlay();
    break;
  case stateLearnMore:
    state = stateWelcomeScreen;
    break;
  case stateAfterAGame:
    state = stateWelcomeScreen;
    break;
  case stateHistory:
    mousePressedStateHistory();
    break;
  case stateBattlefield:
    mousePressedStateBattlefield();
    break;    
  default:
    println("Unknown State (Error 18 in tab InputMouse): " 
      + state+ ".");
    exit();
    break;
  } // switch
} // func 

// ----------------------------------------------------------------------------

void mousePressedStateWelcomeScreen() {
  // Mouse pressed in state Welcome Screen / Main Screen.
  // Evaluate three main buttons. 
  if (rectButtonBoard1.overRect()) {
    currentGame = chooseGame1;    
    state = stateHistory; //
  }
  else if (rectButtonBoard2.overRect()) {
    currentGame = chooseInstructions;    
    state = statePlay;
  }  
  else if (rectLearnmore.overRect()) {
    printLearnMore();
    state = stateLearnMore;
  }
  else {
    // do nothing
  }
}
// When mouse pressed in history, we continue to setup the Battlefield
void mousePressedStateHistory(){
    state = stateBattlefield;  
   
}

void mousePressedStateBattlefield(){
  //User clicks on the vertices of the battlefield so we can determine if the robot is getting out
  //User clicks any key to continue to the actual game to select the colors of the robots
  BattlefieldClickCont++;
  switch(BattlefieldClickCont){
   case 1:
    Vertice1_X=mouseX;
    Vertice1_Y=mouseY;
    print("Vertice1 está en " + Vertice1_X+","+Vertice1_Y +"\n");
    break;
  case 2:
    Vertice2_X=mouseX;
    Vertice2_Y=mouseY;
    print("Vertice2 está en " + Vertice2_X+","+Vertice2_Y+"\n");
    break; 
  case 3:
    Vertice3_X=mouseX;
    Vertice3_Y=mouseY;
    print("Vertice3 está en " + Vertice3_X+","+Vertice3_Y+"\n");
    break; 
  case 4:
    Vertice4_X=mouseX;
    Vertice4_Y=mouseY;
    print("Vertice4 está en " + Vertice4_X+","+Vertice4_Y+"\n");
    break;
  case 5:
    state=statePlay;
    StartColorDetect=1;
    break;  
  default:
    println ("Error en Input Mouse "
      + currentGame);
    exit();
    break;  
  }
   
}
void mousePressedStatePlay() {
  switch (currentGame) {
  case chooseGame1: //Camera
    //Track Color Routine for each color
    ColorsToTrack++;
    switch(ColorsToTrack){
     case 1:
       clicked=1;
       int loc = mouseX + mouseY*video.width;
       trackColor = video.pixels[loc];
       break;
     case 2:
       clicked2=1;
       int loc2 = mouseX + mouseY*video.width;
       trackColor2 = video.pixels[loc2];  
       break;
     case 3:
       clicked3=1;
       int loc3 = mouseX + mouseY*video.width;
       trackColor3 = video.pixels[loc3];  
       break;
     case 4:
       clicked4=1;
       int loc4 = mouseX + mouseY*video.width;
       trackColor4 = video.pixels[loc4];  
       ColorsToTrack=0;
       break;
     default:
        println ("Error en Input Mouse "
        + currentGame);
        exit();
        break;    
    }
    
    
    break;
  case chooseInstructions: //Instructions
    state = stateWelcomeScreen; //Back to main Menu
    break;

  default:
    println ("Error en Input Mouse "
      + currentGame);
    exit();
    break;
  } // switch
}
//


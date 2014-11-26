

// Input key

void keyPressed() {
  //
  // Each state has its own Key Routine, each goes back to previous state
  switch (state) {
  case stateWelcomeScreen:
    //Do nothing avoid error
    break;
  case stateBattlefield:
    state=stateHistory;
    break;
  case stateLearnMore:
    state=stateWelcomeScreen;
    break;
  case statePlay:
    switch (currentGame) {
      case chooseGame1:
        state=stateBattlefield;
        BattlefieldClickCont=0;
        break;
      case chooseInstructions:
        state=stateWelcomeScreen;
        break;  
    }
    break;  
  case stateAfterAGame:
    //Do nothing avoid error
    break;
  case stateHistory:
    state=stateWelcomeScreen;
    break;  
  default:
    println("Estado indefinido: " + state+ ".");
    exit();
    break;
  } // switch
  //
} // func 
//






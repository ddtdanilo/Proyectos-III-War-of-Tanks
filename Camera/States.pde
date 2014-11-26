

// states for the program 

void handleStateShowWelcomeScreen() {
  // 
  // shows the main menu with the main game buttons 
  // 
  // headline 
  fill(255);  
  textSize(32);
  textAlign(CENTER);
  text (strConstTitel, width/2, 40);
  //
  // intro text below headline 
  textSize(19);
  textAlign(LEFT);
  text ("        El combate de Robots Tanque", textXPos, 80); 
  //
  // Game
  rectButtonBoard1.outputRect(); 
  // Instructions
  rectButtonBoard2.outputRect(); 
  // Team Description
  rectLearnmore.outputRect();
  //
}
//
void handleStatePlay() {
  //
  MainProgram();
}
//
void handleStateLearnMore() {
  //
  textLearnMoreOnScreen();
}

void handleStateBattlefield() {
   draw_camera();  
   textSize(19);
   textAlign(LEFT);
   text (" Haz click sobre los vértices del campo de batalla ", 50, 20);   
   text (" En orden secuencial y luego haga click para continuar ", 50, 40);  
   text (" 1 2", 50, 60); 
   text (" 3 4", 50, 80);  
}

void handleStateHistory() {
   background(0,0,0);
  // headline 
  fill(255);  
  textSize(32);
  textAlign(CENTER);
  text (strConstTitel, width/2, 40);
  //
  // intro text 
  textSize(19);
  textAlign(LEFT);
  text ("La Batalla de Kursk (Operación Ciudadela) tuvo lugar entre ", 50, 150);  
  text ("Julio y Agosto de 1943. Rusia y Alemania se enfrentaron en ", 50, 170); 
  text ("una de las más grandes batallas de la historia. ", 50, 190); 
  text ("Participaron más de 3 millones de soldados, 12.000 aviones ", 50, 230); 
  text ("y 13.000 tanques.", 50, 250); 
  text (" ¿Estás listo para entrar al campo de Batalla?", 100, 310);
  text("Presione algún botón del Mouse para continuar", 110, height-170);
  
}
//
void handleStateAfterAGame() {
  // After a game:
  // Wait for mousePressed 
  // to go to the Welcome Screen again. 
  background(0);
  // headline 
  fill(255);  
  textSize(32);
  textAlign(CENTER);
  text (strConstTitel, width/2, 40);
  //
  // intro text 
  textSize(19);
  textAlign(LEFT);
  text (" Fin del Juego ", textXPos, 80);  
  textSize(19);
  text(" Gracias por Jugar ", 
  textXPos, 230);
  text("Presione algún botón del Mouse", 500, height-30);
  //
} // func 
// 


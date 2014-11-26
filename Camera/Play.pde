
// the actual game play; your game logic would be here 

void MainProgram() {
  // depending on game chosen 
  switch (currentGame) {
  case chooseGame1:
    handleGame1();
    break;
  case chooseInstructions:
    handleGame2();
    break;

  default:
    // error 
    println ("Error "
      + currentGame 
      + ".");
    exit();
    break;
  } // switch
} // func 

// ------------------------------------------------------
//Game. Camera
void handleGame1() {
  background(0);
  draw_camera();
  textFont(Font,20);
  text ( "Intentos Equipo 1: " + Intentos1,30,40);
  text ( "Intentos Equipo 2: " + Intentos2,500,40);
  fill(255, 255, 255);
  
  //Draw Battlefield lines
  line(Vertice1_X,Vertice1_Y,Vertice2_X,Vertice2_Y);
  line(Vertice2_X,Vertice2_Y,Vertice4_X,Vertice4_Y);
  line(Vertice1_X,Vertice1_Y,Vertice3_X,Vertice3_Y);
  line(Vertice3_X,Vertice3_Y,Vertice4_X,Vertice4_Y);
  
  //Select the biggest/smallest of the vertices to check out of boundaries after
  if(Vertice2_X>Vertice4_X)
    RightX=Vertice2_X;
  else
    RightX=Vertice4_X;
  if(Vertice1_X>Vertice3_X)
    LeftX=Vertice3_X;
  else
    LeftX=Vertice1_X;  
  if(Vertice1_Y>Vertice2_Y)
    UpY=Vertice2_Y;
  else
    UpY=Vertice1_Y;  
  if(Vertice3_Y>Vertice4_Y)
    DownY=Vertice3_Y;
  else
    DownY=Vertice4_Y; 
  
  //Robot Team 1 Should move to the left to get back in
  if((closestX-SpriteSpace>RightX)||(closestX2-SpriteSpace>RightX)){
    println("Robot Equipo 1 Se sale por la derecha del campo");
    myPort.write(0x00)
    myPort.write(0x01)
  }
  //Robot Team 2 Should move to the left to get back in
  if((closestX3-SpriteSpace>RightX)||(closestX4-SpriteSpace>RightX)){
    println("Robot Equipo 2 Se sale por la derecha del campo");
    myPort.write(0x06)
    myPort.write(0x07)
  }
  //Robot Team 1 Should move to the right to get back in
  if((closestX+SpriteSpace<LeftX)||(closestX2+SpriteSpace<LeftX)){
    println("Robot Equipo 1 Se sale por la izquierda del campo");
    myPort.write(0x00)
    myPort.write(0x02)
  }
  //Robot Team 2 Should move to the right to get back in
  if((closestX3+SpriteSpace<LeftX)||(closestX4+SpriteSpace<LeftX)){
    println("Robot Equipo 2 Se sale por la izquierda del campo");
    myPort.write(0x06)
    myPort.write(0x08)
  }
  //Robot Team 1 Should move up to get back in
  if((closestY+SpriteSpace>DownY)||(closestY2+SpriteSpace>DownY)){
    println("Robot Equipo 1 Se sale por abajo del campo");
    myPort.write(0x00)
    myPort.write(0x03)
  }
  //Robot Team 2 Should move up to get back in
  if((closestY3+SpriteSpace>DownY)||(closestY4+SpriteSpace>DownY)){
    println("Robot Equipo 2 Se sale por abajo del campo");
    myPort.write(0x06)
    myPort.write(0x09)
  }
  //Robot Team 1 Should move down to get back in
  if((closestY-SpriteSpace<UpY)||(closestY2-SpriteSpace<UpY)){
    println("Robot Equipo 1 Se sale por arriba del campo");
    myPort.write(0x00)
    myPort.write(0x04)
  }
  //Robot Team 2 Should move down to get back in
  if((closestY3-SpriteSpace<UpY)||(closestY4-SpriteSpace<UpY)){
    println("Robot Equipo 2 Se sale por arriba del campo");
    myPort.write(0x06)
    myPort.write(0x10)
  }
    
    //Detect shot 
  

}

//Instructions
void handleGame2() {
  tint(255,255,255,100);
  image(Background,0,0);
  noTint();
  // headline 
  fill(255);  
  textSize(32);
  textAlign(CENTER);
  text (strConstTitel, width/2, 40);
  //
  // intro text 
  textSize(19);
  textAlign(LEFT);
  text ("-Coloque los robots en el campo de juego\n-Configure la interfaz haciendo click sobre \n los vértices del campo \n-Determine los colores de cada equipo haciendo click\n sobre ellos" + 

    "\n-Conecte el Arduino a la computadora para la\ncomunicación infrarroja", textXPos, 280);  

  text("Presione algún botón del Mouse o alguna tecla para continuar", 50, height-30);
  //
}



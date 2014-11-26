

void setup_camera() {
  

  video = new Capture(this, CameraHeight, CameraWidth);

  video.start();
  // Start off tracking for red
  //trackColor = color(0, 255, 0);
  
  Equipo10=loadImage("tanque.png");
  Equipo11=loadImage("tanque.png");
  Equipo20=loadImage("tanque.png");
  Equipo21=loadImage("tanque.png");
}

void draw_camera() {
  if(video.available()){
    video.read();
  } 
  video.loadPixels();
  background(0,0,0);
  tint(255, 100);
  image(video, 0, 0);
  //
  if(StartColorDetect==1){
  // Before we begin searching, the "world record" for closest color is set to a high number that is easy for the first pixel to beat.
  float worldRecord = 100;
  float worldRecord2 = 100;
  float worldRecord3 = 100;
  float worldRecord4 = 100;
  // XY coordinate of closest color
  closestX = 0;
  closestY = 0;
  closestX2 = 0;
  closestY2 = 0;
  closestX3 = 0;
  closestY3 = 0;
  closestX4 = 0;
  closestY4 = 0;
  int number=0;
  int cont=0;
  int cont2=0;
  int cont3=0;
  int cont4=0;
  float Brillo1 = 0;
  float Brillo2 = 0;
  float Brillo3 = 0;
  float Brillo4 = 0;
  color Color10 = 0;
  color Color11 = 0;
  color Color20 = 0;
  color Color21 = 0;
  // Begin loop to walk through every pixel
  for (int x = 0; x < video.width; x ++ ) {
    for (int y = 0; y < video.height; y ++ ) {
      int loc = x + y*video.width;
      // What is current color
      currentColor = video.pixels[loc];
      float r1 = red(currentColor);
      float g1 = green(currentColor);
      float b1 = blue(currentColor);
      float r2 = red(trackColor);
      float g2 = green(trackColor);
      float b2 = blue(trackColor);
      float r3 = red(trackColor2);
      float g3 = green(trackColor2);
      float b3 = blue(trackColor2);
      float r4 = red(trackColor3);
      float g4 = green(trackColor3);
      float b4 = blue(trackColor3);
      float r5 = red(trackColor4);
      float g5 = green(trackColor4);
      float b5 = blue(trackColor4);
      // Using euclidean distance to compare colors
      float d = dist(r1, g1, b1, r2, g2, b2); // We are using the dist( ) function to compare the current color with the color we are tracking.
      float d2= dist(r1, g1, b1, r3, g3, b3);
      float d3= dist(r1, g1, b1, r4, g4, b4);
      float d4= dist(r1, g1, b1, r5, g5, b5);
     
      // If current color is more similar to tracked color than
      // closest color, save current location and current difference
      if (d < worldRecord) {
        cont++;
        worldRecord = d;
        
        closestXOld=closestX;
        closestYOld=closestY;//Posición anterior de los puntos de color
        closestX = closestX+x; //nuevo=nuevapos+viejapos
        closestY = closestY+y;
        
      }
      if (d2 < worldRecord2) {
        cont2++;
        worldRecord2 = d2;
       
        closestXOld2=closestX2;
        closestYOld2=closestY2;//Posición anterior de los puntos de color
        closestX2 =closestX2+ x; //nuevo=nuevapos+viejapos
        closestY2 =closestY2+y;
        
      }
      if (d3 < worldRecord3) {
        cont3++;
        worldRecord3 = d3;
        
        closestXOld3=closestX3;
        closestYOld3=closestY3;//Posición anterior de los puntos de color
        closestX3 =closestX3+x; //nuevo=nuevapos+viejapos
        closestY3 =closestY3+y;
        
      }
      if (d4 < worldRecord4) {
        cont4++;
        worldRecord4 = d4;
        
        closestXOld4=closestX4;
        closestYOld4=closestY4;//Posición anterior de los puntos de color
        closestX4 =closestX4+x; //nuevo=nuevapos+viejapos
        closestY4 =closestY4+y;
        
      }
    }
  }
  // We only consider the color found if its color distance is less than 10.
  // This threshold of 10 is arbitrary and you can adjust this number depending on how accurate you require the tracking to be.
  if (worldRecord < 5) {
    // Draw a circle at the tracked pixel
    //fill(255,0,0);
    //strokeWeight(4.0);
    /*if(cont<11){
        promediocolores[cont-1]=currentColor;//va de 0 a 9
           if(cont==10){
             cont=0;
             int i=0;
             int promedio=0;
             for(i=0;i<10;i++)
               promedio=(promediocolores[i]+promedio)/(i+1);
             trackColor=promedio;//Promedio de los ultimos 10 current colors  
           }
        }*/
   
    noTint();
    image(Equipo10,(closestX)/cont,(closestY)/cont);
    int loc1 = closestX/cont + (closestY/cont)*video.width;
    Color10=get(closestX/cont,closestY/cont); //Check the color of the average found
    Brillo1=brightness (Color10);
    if(Brillo1>100){
      println("Led Disparo Equipo 1 Is On");
      Intentos2=Intentos2-1;
      if(Intentos2==0)
        state=stateAfterAGame;
    }  
   
    
  }
  //-------------------------------------------Second Color
  if (worldRecord2 < 5) {
    // Draw a circle at the tracked pixel
    //fill(255,0,0);
    //strokeWeight(4.0);
    /*if(cont2<11){
        promediocolores2[cont2-1]=currentColor;//va de 0 a 9
           if(cont2==10){
             cont2=0;
             int i=0;
             int promedio=0;
             for(i=0;i<10;i++)
               promedio=(promediocolores2[i]+promedio)/(i+1);
             trackColor2=promedio;//Promedio de los ultimos 10 current colors  
           }
        }*/
   
    noTint();
    image(Equipo11,closestX2/cont2,closestY2/cont2);
    int loc2 = closestX2/cont2 + (closestY2/cont2)*video.width;
    Color11=get(closestX2/cont2,closestY2/cont2);//Check the color of the average found
    Brillo2=brightness (Color11);
    if(Brillo2>100)
      println("Led Acknowledge Equipo 1 Is On");
    
    
  }
  //-------------------------------------------Third Color
  if (worldRecord3 < 5) {
    // Draw a circle at the tracked pixel
    //fill(255,0,0);
    //strokeWeight(4.0);
    /*if(cont3<11){
        promediocolores3[cont3-1]=currentColor;//va de 0 a 9
           if(cont3==10){
             cont3=0;
             int i=0;
             int promedio=0;
             for(i=0;i<10;i++)
               promedio=(promediocolores3[i]+promedio)/(i+1);
             trackColor3=promedio;//Promedio de los ultimos 10 current colors  
           }
        }*/
   
    noTint();
    image(Equipo20,closestX3/cont3,closestY3/cont3);
    
    Color20=get(closestX3/cont3,closestY3/cont3);
    Brillo3=brightness (Color20);
    if(Brillo3>100){
      println("Led Disparo Equipo 2 Is On");
      Intentos1=Intentos1-1;
      if(Intentos1==0)  
        state=stateAfterAGame;
    }
    
    
  }
  //-------------------------------------------Fourth Color
  if (worldRecord4 < 5) {
    // Draw a circle at the tracked pixel
    //fill(255,0,0);
    //strokeWeight(4.0);
    /*if(cont4<11){
        promediocolores4[cont4-1]=currentColor;//va de 0 a 9
           if(cont4==10){
             cont4=0;
             int i=0;
             int promedio=0;
             for(i=0;i<10;i++)
               promedio=(promediocolores4[i]+promedio)/(i+1);
             trackColor4=promedio;//Promedio de los ultimos 10 current colors  
           }
        }*/
   
    noTint();
    image(Equipo21,closestX4/cont4,closestY4/cont4);
     int loc4 = closestX4/cont4 + (closestY4/cont4)*video.width;
    Color21=get(closestX4/cont4,closestY4/cont4);//Check the color of the average found
    Brillo4=brightness (Color21);
    if(Brillo4>100)
      println("Led Acknowledge Equipo 2 Is On");
    
    
  }
  //println("Coordenada X:"+closestX);
 // println("Coordenada Y:"+closestY);
  }
}//Draw



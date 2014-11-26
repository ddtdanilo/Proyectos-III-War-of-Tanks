
// Rectangles for the menu buttons

class Rectangle {

  int x, y, w, h;   
  String textRect="";  
  String textStatusBar=""; 

  // constructor
  Rectangle( int _x, int _y, 
  int _w, int _h, 
  String _text, 
  String _textStatusBar, 
  int _associatedGameIcon ) {
    x=_x;
    y=_y;
    w=_w;
    h=_h;
    textRect=_text;
    textStatusBar=_textStatusBar;
   
  } // constructor
  //
  public void outputRect() {
    drawRectText(); 
    drawRect();
  
  } // method 

  void drawRect() {
    noFillOrLightColorDependingOnMouseOver();
    stroke(255);
    rect(x, y, w, h);
  
    // status bar 
    if (overRect()) {
     // menuselectcont++;
      
       // play_Select();
        //if(!Menu.isPlaying())
         // rewind_Select();
      
      fill(255);
      textSize(20); //Más información text     
      textAlign(LEFT);      
      text(textStatusBar, 15, height-15);
    }
    /*if (!overRect()){
      menuselectcont=0;
      //rewind_Select();
    }*/
  } // method 

  void drawRectText() {
    if (!textRect.equals("")) {
      fill(255);
      textSize(30);      
      textAlign(CENTER);  
      text(textRect, x, y+(h/2)-9, w, h);
    }
  } // method  

  boolean overRect() {
    if (mouseX>x && mouseX<x+w && 
      mouseY>y && mouseY<y+h) 
    {
      return true;
    } 
    else 
    {
      return false;
    } // if else
  } // method  
  //
  void noFillOrLightColorDependingOnMouseOver() {

    if (overRect()){ 
      fill(2, 255, 2, 50);
     
    }  
    else   {
      noFill();
      

    } 
  } // method
  //
} // class
//


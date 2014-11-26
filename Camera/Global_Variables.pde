import processing.video.*;
import ddf.minim.*;
import processing.serial.*;
import java.awt.Color; 
//---------Serial
Serial myPort;
//-------Audio

Minim minim;
AudioPlayer Intro;
AudioPlayer Menu;

//-------Video/Camera

Capture video;
int menuselectcont=0;
PFont fuente;

color trackColor;
color trackColor2;
color trackColor3;
color trackColor4;
color currentColor;
int closestX = 0;
int closestY = 0;
int closestX2 = 0;
int closestY2 = 0;
int closestX3 = 0;
int closestY3 = 0;
int closestX4 = 0;
int closestY4 = 0;
int Intentos1 = 3;
int Intentos2 = 3;
//int cont=0;
//int cont2=0;
//int cont3=0;
//int cont4=0;
int clicked=0;
int clicked2=0;
int clicked3=0;
int clicked4=0;
int closestXOld=0;
int closestYOld=0;
int closestXOld2=0;
int closestYOld2=0;
int closestXOld3=0;
int closestYOld3=0;
int closestXOld4=0;
int closestYOld4=0;
int[] promediocolores = new int[10];
int[] promediocolores2 = new int[10];
int[] promediocolores3 = new int[10];
int[] promediocolores4 = new int[10];
int ColorsToTrack=0;
//Battlefield
int Vertice1_X;
int Vertice1_Y;
int Vertice2_X;
int Vertice2_Y;
int Vertice3_X;
int Vertice3_Y;
int Vertice4_X;
int Vertice4_Y;
int BattlefieldClickCont=0;
int StartColorDetect=0;
int RightX;
int LeftX;
int UpY;
int DownY;
PFont Font;
PImage Background;
PImage Equipo10;
PImage Equipo11;
PImage Equipo20;
PImage Equipo21;
//------Menú

final String strConstTitel = "La Batalla de Kursk";
//
// Estados posibles
final int stateWelcomeScreen  = 0; // Menue at the beginning 
final int statePlay           = 1; // playing the game that has beeen chosen
final int stateLearnMore      = 2; // show help / learn more
final int stateAfterAGame     = 3; // after game, before returning to Welcome Screen
final int stateHistory        = 4; // Historic Intro for the game
final int stateBattlefield    = 5;

// current state 
int state = stateWelcomeScreen;
//
// Games: 
final int chooseGame1 = 0;
final int chooseInstructions = 1;

// their names 
final String [] chooseGameName = 
{ 
  "Inicio", 
  "Instrucciones", 
  "Más información"
};
final String [] statusText = 
{
  "Comenzar el juego", 
  "Reglas del juego", 
  "Descripción del equipo"
};
//
// current game
int currentGame = chooseGame1;
//
// the initial Main Menu
int textXPos;
int learnPos; 
int[] textYPos = { 
  230, 
  330, 
  430, 
};
//
// rectangles as buttons for main menu 
Rectangle rectButtonBoard1; 
Rectangle rectButtonBoard2; 
Rectangle rectLearnmore; 

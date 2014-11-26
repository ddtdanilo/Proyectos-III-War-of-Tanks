

void setup_audio()
{
 
  // we pass this to Minim so that it can load files from the data directory
  minim = new Minim(this);
  
  Intro = minim.loadFile("The Battle Of Kursk.mp3");
  Menu  = minim.loadFile("Menu.mp3");
  return;
}

void play_Intro(){
  Intro.loop();
  return;
}

void stop_Intro(){
  Intro.pause();
  return;
}

void play_Select(){
 
  Menu.play();
  //
  return;
}

void rewind_Select(){
  Menu.rewind();
  //Menu.pause();
  return;
}




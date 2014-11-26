

//Serial functions

// List all the available serial ports:
void setup_serial(){
println(Serial.list());
// Open the port you are using at the rate you want:
myPort = new Serial(this, Serial.list()[0], 1200);

}


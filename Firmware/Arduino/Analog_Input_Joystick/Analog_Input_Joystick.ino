
//firmware for reading a joysticking


//variables definition and initialization
#define Xpin 34 //GPIO 33 en entrée
#define Ypin 35 //GPIO 32 en sortie

int xvalue = 0;
int yvalue = 0;

void setup() 
{
Serial.begin(9600);
}

void loop() 
{
  //read value
xvalue = analogRead(Xpin);
yvalue = analogRead(Ypin);

  //print value
Serial.print(xvalue);
Serial.print("  ");
Serial.print(yvalue);
Serial. println();

delay(512);
}

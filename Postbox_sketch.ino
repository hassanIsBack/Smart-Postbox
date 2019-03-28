#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YOUR AUTH";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YOUR WIFI SSID";
char pass[] = "YOUR WIFI PASSWORD";
int flag=0;
//ADC_MODE(ADC_VCC); //define the analog pin
void notifyOnButtonPress()
{
  int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==1 && flag==0) {
    Serial.println("Post, Post!");
    
    //   We allow 1 notification per 15 seconds for now.
    //int voltage = ESP.getVcc()/10;
    Blynk.notify("Post: you got a post just now!");
    //String stringMail = "Got a post!";
    //Blynk.email("YOUR EMAIL ADDRESS", "From Blynk", stringMail);
    flag=1;
  }
  else if (isButtonPressed==0)
  {
    flag=0;
  }
  
 
}
void setup()
{
  // Debug console
  Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
  // Setup notification button on pin D1
  pinMode(D1,INPUT_PULLUP);
 timer.setInterval(16000L,notifyOnButtonPress);
 
}
void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}

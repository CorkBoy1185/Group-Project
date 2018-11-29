#define CUSTOM_SETTINGS
#define INCLUDE_INTERNET_SHIELD
#define INCLUDE_GPS_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#include <OneSheeld.h>

HttpRequest latitudeRequest("https://project-ID.firebaseio.com/latitude.json");
HttpRequest longitudeRequest("https://project-ID.firebaseio.com/longitude.json");

float latitude;
float longitude;
char latitude_char[10];
char longitude_char[10];

void setup() {
  // put your setup code here, to run once:
  OneSheeld.begin();
}
 
void loop()
{
  // put your main code here, to run repeatedly:
  latitude = GPS.getLatitude();
  longitude = GPS.getLongitude(); 

  dtostrf(latitude, 8, 4, latitude_char);
  dtostrf(longitude, 8, 4, longitude_char);

  latitudeRequest.addRawData(latitude_char);
  Internet.performPost(latitudeRequest);
  OneSheeld.delay(5000);
  Terminal.println(latitude_char);
  
  OneSheeld.delay(1000);
  
  longitudeRequest.addRawData(longitude_char);
  Internet.performPost(longitudeRequest);
  OneSheeld.delay(5000);
  Terminal.println(longitude_char);
}

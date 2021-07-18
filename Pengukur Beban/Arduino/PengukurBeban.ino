#include <HX711.h>

long rawdat;
long rawsck;

//nilai kalibrasi
float untukkalibrasi;
float refberat = 7000;
float scalenum;

//nilai scale
float scale1;
float scale2;

// HX711 pin
const int dout = 2;
const int sck = 3;

//nilai berat
long berat;

HX711 scale;

void setup() {
  Serial.begin(57600);
  //Serial.print("~~~~~TIMBANGAN~~~~~");
  scale.begin(dout, sck);

  //Kalibrasi
  /*scale.set_scale();
  Serial.print("~~~~~KALIBRASI~~~~~");
  Serial.print("\n");
  Serial.print("Tare");
  scale.tare();
  Serial.print("\n Tare Selesai");
  delay(3000);
  Serial.print("\n");
  Serial.println("taro beban");
  delay(15000);
  float untukkalibrasi = scale.get_units(50);
  Serial.print("catet nilai untuk kalibrasi: ");
  Serial.println(untukkalibrasi);
  Serial.print("berat: ");
  Serial.println(refberat);
  float scalenum = untukkalibrasi/refberat;
  Serial.print("input set_scale: ");
  Serial.println(scalenum);*/
  
  //nilai berat
  //nilai scale load cell 200 kg = 15.94
  float scale1 = 17;
  //nilai scale load cell 5 kg = 425.54
  float scale2 = 425.54;
  scale.set_scale(scale2);
  scale.tare();
  //Serial.print("\n Taruh Beban");
}

void loop() {
  //Serial.print("\n");
  //Serial.print("Berat: ");
  long berat = Serial.print(scale.get_units(2), 1);
  Serial.println(berat);
  //Serial.print(" Gram");
 
}

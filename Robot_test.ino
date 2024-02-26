String a = "";
String receive = "";
int x;
int y;
int d3;
int g1;
int d2;
int step1;
int step3;
int num_step;
float angle;
#define dir 3
#define stepp 2
#define dir2 5
#define stepp2 4
#define dir3 7
#define stepp3 6
#define ct1 38
#define ct2 36
#define ct3 37
void setup() {
 pinMode(dir, OUTPUT);
 pinMode (stepp, OUTPUT);
 pinMode(dir2, OUTPUT);
 pinMode (stepp2, OUTPUT);
 pinMode(dir3, OUTPUT);
 pinMode (stepp3, OUTPUT);
 pinMode (ct1, INPUT);
 pinMode (ct2, INPUT);
 pinMode (ct3, INPUT);
 Serial.begin (9600);
}
void loop() {
 
 
 if(Serial.available ())
 {
 a = Serial.readString();
 if (a.startsWith("x") == true)
 {
 receive = a.substring(1);
 x = receive.toInt();
 }
 
 if (a.startsWith("y") == true)
 {
 receive = a.substring(1);
 y = receive.toInt();
 
 }
 d3=sqrt(x*x+y*y);
 g1=atan2(-x, y);
 //d2=z-5;
 
 step1 = ((g1 * 8) / 1.8) * 4 * 3.53;
digitalWrite (dir, HIGH);
 
 for (int i = 0; i<22592; i ++)
 {
 digitalWrite (stepp, HIGH);
 delayMicroseconds(200);
 digitalWrite (stepp, LOW);
 delayMicroseconds(200);
 }
 if (ct1 == HIGH)
 {
 for (int i = 0; i<step1; i ++)
 {
 digitalWrite (stepp, HIGH);
 delayMicroseconds(200);
 digitalWrite (stepp, LOW);
 delayMicroseconds(200);
 }
 }
 //di len
 digitalWrite(dir2, LOW);
 for (int i = 0; i < 14000; i++) 
 {
 digitalWrite(stepp2, HIGH);
 delayMicroseconds(200);
 digitalWrite(stepp2, LOW);
 delayMicroseconds(200);
 }
 if (ct2 == HIGH)
 {
 digitalWrite(dir2, HIGH);
 for (int i = 0; i < 5000; i++) 
 {
 digitalWrite(stepp2, HIGH);
 delayMicroseconds(200);
 digitalWrite(stepp2, LOW);
 delayMicroseconds(200);
 }
 }
 
//di lui
 digitalWrite(dir3, LOW);
for (int i = 0; i < 8000; i++) {
 digitalWrite(stepp3, HIGH);
 delayMicroseconds(200);
 digitalWrite(stepp3, LOW);
 delayMicroseconds(200);
 }
 if (ct3 == HIGH)
 {
 digitalWrite(dir3, HIGH);
 for (int i = 0; i < step3; i++) 
 {
 digitalWrite(stepp3, HIGH);
 delayMicroseconds(200);
 digitalWrite(stepp3, LOW);
 delayMicroseconds(200);
 }
 }
 }
}

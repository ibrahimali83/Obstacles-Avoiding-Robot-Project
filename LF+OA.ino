#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define speedL 10
#define speedR 6
#define sensorL 7
#define sensorR 8
#define trig 9
#define echo 11
long duration,distance;
int sl=0;
int sr=0;

void setup() {
pinMode (IN1, OUTPUT);
pinMode (IN2, OUTPUT);
pinMode (IN3, OUTPUT);
pinMode (IN4, OUTPUT);
pinMode (speedR, OUTPUT);
pinMode (speedL, OUTPUT);
pinMode (sensorR, INPUT);
pinMode (sensorL, INPUT);
pinMode (trig,OUTPUT);
pinMode (echo,INPUT);
}
void Ultrasonic(){
digitalWrite(trig, LOW);
delayMicroseconds (2);
digitalWrite (trig, HIGH);
delayMicroseconds(10);
digitalWrite (trig, LOW);
duration = pulseIn (echo, HIGH);
distance = (duration/2) * 0.0343;
}
void forward()
{
digitalWrite (IN1, HIGH);
digitalWrite (IN2, LOW);
digitalWrite (IN3, HIGH);
digitalWrite (IN4, LOW);
analogWrite (speedL, 100);
analogWrite (speedR, 100);
}
void backward()
{
digitalWrite (IN1, LOW);
digitalWrite (IN2, HIGH);
digitalWrite (IN3, LOW);
digitalWrite (IN4, HIGH);
analogWrite (speedL, 150);
analogWrite (speedR, 150);
}
void left()
{
digitalWrite (IN1, LOW);
digitalWrite (IN2, LOW);
digitalWrite (IN3, HIGH);
digitalWrite (IN4, LOW);
analogWrite (speedL, 0);
analogWrite (speedR, 80);
}
void right()
{
digitalWrite (IN1, HIGH);
digitalWrite (IN2, LOW);
digitalWrite (IN3, LOW);
digitalWrite (IN4, LOW);
analogWrite (speedL, 80);
analogWrite (speedR, 0);
}
void stopp()
{
digitalWrite (IN1, LOW);
digitalWrite (IN2, LOW);
digitalWrite (IN3, LOW);
digitalWrite (IN4, LOW);
analogWrite (speedL, 0);
analogWrite (speedR, 0);
}

void loop() {
sl=digitalRead (sensorL);
sr=digitalRead (sensorR);
Ultrasonic();
if (sl==0&&sr==0&&distance>10) {
forward();}
else if (sl==0&&sr==1){
right();}
else if (sl==1&&sr==0){
left();}
else if (sl==1&&sr==1||distance<10){
stopp();}
}


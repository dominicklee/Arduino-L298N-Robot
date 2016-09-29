//Arduino Robotic Control Example
//By Dominick Lee for Purdue Mechatronics Club

int ENA = 6;  //PWM pin for Left Motor
int IN1 = 7;  //Left motor direction
int IN2 = 8;  //Left motor direction
int IN3 = 9;  //Right motor direction
int IN4 = 10; //Right motor direction
int ENB = 11;  //PWM pin for Right Motor

//Function to control motors
//mtr - 0 = left, 1 = right
//dir - 0 = forward, 1 = backward
//spd - Motor speed from 0 to 255
void setMotor(int mtr, int dir, int spd)
{
  if (mtr == 0)  //Left motor
  {
    if (dir == 0)
    {
      //Move forward
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }
    else
    {
      //Move backward
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }
    //Set speed
    analogWrite(ENA, constrain(spd, 0, 255));
  }
  else if (mtr == 1)  //Right motor
  {
    if (dir == 0)
    {
      //Move forward
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    else
    {
      //Move backward
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    //Set speed
    analogWrite(ENB, constrain(spd, 0, 255));
  }
}

void setup()
{
  //Set all pins to output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop()
{
  //Move forward
  setMotor(0, 0, 125);  //Set left motor, forward, 125 speed
  setMotor(1, 0, 125);  //Set right motor, forward, 125 speed
  delay(2000);
  
  //Stop
  setMotor(0, 0, 0);  //Set left motor, forward, 0 speed
  setMotor(1, 0, 0);  //Set right motor, forward, 0 speed
  delay(1000);
  
  //Move backward
  setMotor(0, 1, 125);  //Set left motor, forward, 125 speed
  setMotor(1, 1, 125);  //Set right motor, forward, 125 speed
  delay(2000);
  
  //Stop
  setMotor(0, 0, 0);  //Set left motor, forward, 0 speed
  setMotor(1, 0, 0);  //Set right motor, forward, 0 speed
  delay(1000);
  
  //Turn right
  setMotor(0, 0, 100);  //Set left motor, forward, 100 speed
  setMotor(1, 1, 100);  //Set right motor, backward, 100 speed
  delay(2000);
  
  //Turn left
  setMotor(0, 1, 100);  //Set left motor, backward, 100 speed
  setMotor(1, 0, 100);  //Set right motor, forward, 100 speed
  delay(2000);
}



/********************************************/
//      Filename:   meanmachine
//      Developers: Bryan Curneen
/********************************************/

/************  INCLUDE SECTION  *************/
#include "Servo.h"
/********************************************/


/************  DEFINE SECTION  **************/
#define LEFT_LIMIT 20
#define RIGHT_LIMIT 160

#define FOWARD_LIMIT  120
#define REVERSE_LIMIT 60
/********************************************/


/*********  IMPORTANT VARIABLES  ************/
String hostIP = "192.168.1.227";
String ssid = "linksys";
String password = "asteroid";
int sendPort = 5000;
int listenPort = 5001;

Servo motor;
Servo steer;
/********************************************/


/************************* SETUP & LOOP ************************/
void setup() 
{
	initializeCar();
	initializeWiFly();
	armESC();
	initializeServo();
}
 
void loop() 
{
	
}


/*****************************************************************/
void initializeCar()
{
	initializeMotor();
	initializeServo();
}

void initializeWiFly()
{

}


/************************* MOTOR CONTROL ************************/
void armESC()
{
	setThrottle(0);
	delay(2000);	// hopefully the right amount of time to arm the ESC...experiment with this delay
	setThrottle(90);
}

void coast()
{
	//motor.write(90);
}

void initializeMotor()
{
	//motor.attach(9);	// attach motor pin to PWM pin 9
	armESC(); 
}

void setThrottle(int throttle)
{
	if(throttle >= REVERSE_LIMIT && throttle <= FOWARD_LIMIT){
		//motor.write(dir);
	}else if(throttle < REVERSE_LIMIT){
		//motor.write(REVERSE_LIMIT);
	}else if(throttle > FOWARD_LIMIT){
		//motor.write(FOWARD_LIMIT);
	}
}


/************************* SERVO CONTROL ************************/
void initializeServo()
{
	steer.attach(8);	// attach steer pin to PWM pin 8
	steer.write(90);	// write "center" value to steering servo
}

void setDirection(int dir)
{
	if(dir >= LEFT_LIMIT && dir <= RIGHT_LIMIT){
		steer.write(dir);
	}else if(dir < LEFT_LIMIT){
		steer.write(LEFT_LIMIT);
	}else if(dir > RIGHT_LIMIT){
		steer.write(RIGHT_LIMIT);
	}
}

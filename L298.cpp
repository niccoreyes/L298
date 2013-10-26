#include "L298.h"

L298::L298(){
	mPins[0][0] = 9;
	mPins[0][1] = 10;
	mPins[1][0] = 5;
	mPins[1][1] = 6;
	pinSet();
}
L298::L298(unsigned char DIRA, unsigned char PWMA, unsigned char DIRB, unsigned char PWMB){ /*modify pins from default here*/
	mPins[0][0] = DIRA;
	mPins[0][1] = PWMA;
	mPins[1][0] = DIRB;
	mPins[1][1] = PWMB;
	pinSet();
}
void L298::pinSet(){
	for(unsigned char i =0; i <2; i++){
		for (unsigned char x=0; x<2;x++){
			pinMode(mPins[i][x], OUTPUT);
			digitalWrite(mPins[i][x], HIGH); /*breaks at start*/
		}
	}
}
void L298::setSpeed(int speed, int right){ /*speed is left, then becomes right later on*/
	for (int i=0; i<2; i++){
		if(i) speed = right;
		if(speed > 0){
			if(speed > 255) speed = 255;
			digitalWrite(mPins[i][0], LOW);
		}
		else if(speed < 0){
			speed = speed + 255;
			if(speed < 0) speed = 0;
			digitalWrite(mPins[i][0], HIGH);
		}
		else {
			digitalWrite(mPins[i][0], HIGH);
			speed = 255;
		}
		analogWrite(mPins[i][1], speed);
	}
}
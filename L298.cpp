#include "L298.h"

L298::L298(){
	mPins[0][0] = 9;
	mPins[0][1] = 10;
	mPins[1][0] = 5;
	mPins[1][1] = 6;
	for(int i =0; i <2; i++){
		for (int x=0; x<2;x++){
			pinMode(mPins[i][x], OUTPUT);
			digitalWrite(mPins[i][x], HIGH); /*breaks at start*/
		}
	}
}
L298::L298(unsigned char PWMA1, unsigned char PWMA2,
			 unsigned char PWMB1, unsigned char PWMB2){ /*modify pins from default here*/
	mPins[0][0] = PWMA1;
	mPins[0][1] = PWMA2;
	mPins[1][0] = PWMB1;
	mPins[1][1] = PWMB2;
	for(int i =0; i <2; i++){
		for (int x=0; x<2;x++){
			pinMode(mPins[i][x], OUTPUT);
			digitalWrite(mPins[i][x], HIGH); /*breaks at start*/
		}
	}
}
void L298::setSpeed(int speed, int right){ /*speed is left, then becomes right later on*/
	for (int i=0; i<2; i++){
		if(i) speed = right; /*if i != to 0 since 0 means false, any other value means true (aka '1')*/
		/*if(speed > 255) speed = 255; //if entered speed is more than 255
		else if (speed < -255) speed = -255;*/
		if(speed > 0){
			digitalWrite(mPins[i][0], LOW);
			analogWrite(mPins[i][1], speed);
		}
		else if(speed < 0){
			speed = -speed;
			digitalWrite(mPins[i][1], LOW);
			analogWrite(mPins[i][0], speed);
		}
		else {
			digitalWrite(mPins[i][0], HIGH);
			digitalWrite(mPins[i][1], HIGH);
		}
	}
}
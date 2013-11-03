#include "L298.h"

L298::L298(){
	L298(11,10,9,8);
}
L298::L298(unsigned char DIRA, unsigned char PWMA, unsigned char DIRB, unsigned char PWMB){ /*modify pins from default here*/
	mPins[0][0] = DIRA;
	mPins[0][1] = PWMA;
	mPins[1][0] = DIRB;
	mPins[1][1] = PWMB;
	for(unsigned char i =0; i <2; i++){
		for (unsigned char x=0; x<2;x++){
			pinMode(mPins[i][x], OUTPUT);
			digitalWrite(mPins[i][x], HIGH); /*breaks at start*/
		}
	}
}
void L298::setSpeed(int speed, int right){ /*speed is left, then becomes right later on*/
	for (unsigned char i=0; i<2; i++){
		if(i) speed = right;
		if(!speed){
			digitalWrite(mPins[i][0], LOW);
			digitalWrite(mPins[i][1], LOW);
		}
		else {
			if(speed >=0){
				digitalWrite(mPins[i][0], LOW);
			}
			else {
				speed = speed + 255;
				digitalWrite(mPins[i][0], HIGH);
			}
			analogWrite(mPins[i][1], speed);
		}
		
	}
}
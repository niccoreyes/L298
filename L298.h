#ifndef L298_h
#define L298_h

#include <Arduino.h>
class L298 {
	public:
		L298(); /*default pin arrangement*/
		L298(unsigned char PWMA1, unsigned char PWMA2,
			 unsigned char PWMB1, unsigned char PWMB2);
		void setSpeed(int speed, int right);
	private:
		unsigned char mPins[2][2];
		void pinSet();
};

#endif
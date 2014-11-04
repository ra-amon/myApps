#include <stdio.h>
#include "ofMain.h" 

class Ardiono{
public:
	Ardiono(){ //constructor prototype.
	};
	void setup(string port);
	void setupArd(const int  &version);
	void update();
	void draw();
	void testLed();
	ofArduino ard;
};
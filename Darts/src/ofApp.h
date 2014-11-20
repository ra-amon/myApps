#pragma once

#include "ofMain.h"
#include <iostream>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//functions for arduino
		void setupArduino();
		void updateArduino();
		// will only be false when the code first runs the arduino
		bool bSetupArduino;

		//veriabels for arduino
		ofSerial serial; //allows for serial output 
		//an arduino object
		ofArduino myArduino;
		
		int counter;
		int check;
		float Rightvolt, Leftvolt,Right, Left; 

};

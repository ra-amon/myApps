#pragma once

#include "ofMain.h"
#include <iostream>
using namespace std;
struct Player {
	int playerRadius;
	//---------------------location----------------------------//
	//player posistion
	int XposPlayer; 
	int YposPlayer;
	int XLoaction;
	int YLoaction; 
	//weapon Pos
	float XposWeapon;
	float YposWeapon; 

	//controls
	bool up;
	bool down;
	bool left;
	bool right;
	bool playerHit;
	//bounce is the trigger to pull the weapon back
	int bounce;
	int playerScore;
	float newLocX, newLocY;// give force
};
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
		//math function
		void pullToPlayer();

		//functions for arduino
		void setupArduino();
		void updateArduino();
		// will only be false when the code first runs the arduino
		bool bSetupArduino;
		//variables for game
		//radius weapon
		float WeaponRadius;

		float retreat; //distance of the pullback
		int Hitvalue1; //the variable that counts up when hit by the weapon
		int Hitvalue2;//the variable that counts up when hit by the weapon
		bool hasLostGame;
		float playerSpeed;
		//discance between the weapon and the player
		float Yspeed1, Yspeed2;
		float Xspeed1, Xspeed2;
	
		float Weapon1SpeedX, Weapon2SpeedX; 
		float Weapon1SpeedY, Weapon2SpeedY;
		
		//images
		ofImage weapon;
		ofImage player1;
		ofImage player2;
		//sounds
		ofSoundPlayer Hit;
		ofSoundPlayer backgroundSound;

		//fonts
		ofTrueTypeFont Font;

		//veriabels for arduino
		ofSerial serial; //allows for serial output 
		//an arduino object
		ofArduino myArduino;
		//players
		vector<Player>players; 
};

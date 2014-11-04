#pragma once

#include "ofMain.h"
#include <iostream>
using namespace std;
struct Player {
	int playerRadius;
	//location
	int XposPlayer; 
	int YposPlayer;
	int XLoaction;
	int YLoaction; 
	//controls
	bool up;
	bool down;
	bool left;
	bool right;
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
		float XposWeapon1;
		float YposWeapon1;
		//float XposPlayer2;
		//float YposPlayer2;
		//float X2Loaction;
		//float Y2Loaction; 
		// weapon player 1 position
		float XposWeapon2;
		float YposWeapon2;

		float retreat; //distance of the pullback
		int scorePlayer1;
		int Hitvalue1; //the variable that counts up when hit by the weapon
		int scorePlayer2;
		int Hitvalue2;//the variable that counts up when hit by the weapon
		int bounce1;
		int bounce2;
		bool hasLostGame;
		bool player1Hit;
		bool player2Hit;

		float playerSpeed;
		//discance between the weapon and the player
		float Yspeed1, Yspeed2;
		float Xspeed1, Xspeed2;

		float Weapon1SpeedX, Weapon2SpeedX; 
		float Weapon1SpeedY, Weapon2SpeedY;
		float WeaponRadius; // radius of the weapon
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

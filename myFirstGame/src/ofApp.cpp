#include "ofApp.h"
float playerRadius;
float enemyRadius;
float enemyX;
float enemyY;
int score;
int speed;
bool hasLostGame;
int enemySpeed; //speed of the falling circles


//--------------------------------------------------------------
void ofApp::setup(){
	enemyRadius = 20;
	playerRadius = 60;
	//show the enemy off screen, to start
	enemyY = 0 - enemyRadius;
	enemyX = ofRandom(ofGetWidth());
	hasLostGame = false;
	score = 0;
	ofSetVerticalSync(true);
	enemySpeed = 1;	

}

//--------------------------------------------------------------
void ofApp::update(){
	//all math stuff
	//check if we didn't lose the game
	if(hasLostGame==false){
		if(enemyY > ofGetHeight() + enemyRadius)
		{
			score++;
			enemyRadius += 2;
			enemyX = ofRandom(ofGetWidth());
			enemyY = 0 - enemyRadius;
		}
		enemyY += enemySpeed; 
		//check if the player hit the circle
		if(ofDist(mouseX, mouseY, enemyX, enemyY)<=enemyRadius + playerRadius){
			hasLostGame = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0,0,0);
	//this is the enemy
	ofSetColor(255,0,0);
	ofCircle(enemyX,enemyY,enemyRadius);

	//this is the player
	ofSetColor(0,0,255);
	ofCircle(mouseX,mouseY, playerRadius);
	ofSetColor(255,255,255);
	ofDrawBitmapString("Score : "+ofToString(score), 20, 20);
	if(hasLostGame){
		ofDrawBitmapString("\nGame over! Press any key to restart", 20,20);
		
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//listeners 
	if(key== 359){
			ofSetColor(213,80,38);
			ofCircle(100,100,100);
		}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(hasLostGame){
		enemyX = ofRandom(ofGetWidth());
		enemyY = 0 - enemyRadius;
		enemyRadius =20;
		ofBackground(255,0,0);
		hasLostGame=false;
		score =0;
	
	}
		cout << key; 
		
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

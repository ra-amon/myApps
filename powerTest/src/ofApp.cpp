#include "ofApp.h"
float x, y ;
float playerX, playerY;
float delayX, delayY;
float newLocX, newLocY;
//--------------------------------------------------------------
void ofApp::setup(){
	playerX=ofGetMouseX();
	playerY=ofGetMouseY();
	x=ofGetMouseX();
	y=ofGetMouseY();
}

//--------------------------------------------------------------
void ofApp::update(){
	
	delayX =(ofGetMouseX()-x)*0.01;
	delayY=(ofGetMouseY()-y)*0.01;
	x = x+delayX;
	y= y+delayY;
	playerX=ofGetMouseX();
	playerY=ofGetMouseY();
	if(ofDist(playerX,playerY,x,y)>50){
	  newLocX=(x-playerX)*0.3;
	  newLocY=(y-playerY)*0.3;
	}
	
}


//--------------------------------------------------------------
void ofApp::draw(){
	ofEllipse(playerX,playerY,90,90);
	ofEllipse(x,y,30,30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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

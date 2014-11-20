#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	setupArd("COM4");
}

//--------------------------------------------------------------
void ofApp::update(){
	testLed();

}

//-------------------------------------------------------------
void ofApp::draw(){
	
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

void ofApp::setupArd(string port){
	ard.connect(port,57600);
	ofAddListener(ard.EInitialized, this, &ofApp::connectedArd);
	
	
}
void ofApp::connectedArd(const int &version){
	ofRemoveListener(ard.EInitialized, this, &ofApp::connectedArd);
	ard.sendDigitalPinMode(9, ARD_OUTPUT);
	testLed();

}
void ofApp::testLed(){
	ard.sendDigital(9, ARD_HIGH);
	
	
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

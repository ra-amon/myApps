#include "ofApp.h"
float irSensor;
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate( 60 );
	serial.enumerateDevices();
	serial.setup(0, 9600);

	irSensor = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
		if(serial.available()){  
   irSensor = serial.readByte();  
    cout << irSensor << endl;  
}

	
}

//--------------------------------------------------------------
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

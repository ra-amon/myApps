#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	numBalls=1000;
	for(int i=0; i<numBalls;i++){
		mover *m = new mover(ofRandom(0.1,3),ofRandom(0,ofGetWidth()),ofRandom(0,200)); 
		 balls.push_back(*m);
	}

	wind = ofVec2f (0.001,0);
	gravity = ofVec2f(0, 0.001);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	for(int i=0; i<numBalls;i++){
	balls[i].applyForce(wind);
	balls[i].applyForce(gravity);
	balls[i].update();
	balls[i].checkEdges();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i=0; i<numBalls;i++){
	balls[i].display();
	}
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

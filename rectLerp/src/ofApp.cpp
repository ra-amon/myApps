#include "ofApp.h"

class Rect_2{ 
	public:
	ofPoint pos;
	ofPoint posa;
	ofPoint posb;
	float shaper;
	float pct;

	Rect_2(){
	shaper = 1.0;
	}

	void interp(float myPct){
	pct = powf(myPct,shaper);
	


	

		cout << pct << endl;
	if(pct < 0.5){
	pos.x = (1-pct)* posa.x + (pct) * posb.x;
	pos.y = (1-pct)* posa.y + (pct)* posb.y;
	}else{
	pos.x = (1-pct)* posa.x + (pct) * posb.x;
	pos.y = (1-pct)* posb.y + (pct)* posa.y;
	}

	}
	void draw(){
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofRect(pos.x,pos.y, 20,20);
	}
};
Rect_2 myRect; 
float pct;
bool returnRect;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(30,30,30);
	diraction=0.0005;
	myRect.posa.x=10;
	myRect.posa.y= 300;
	myRect.posb.x=900;
	myRect.posb.y=100;
	myRect.shaper = 0.2;
	myRect.interp(0);
	pct =0;
	returnRect=true;

	
}

//--------------------------------------------------------------
void ofApp::update(){
	pct += diraction;
	

	if(pct>1) {
		pct=0;


	}


	myRect.interp(pct);
  
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(10,255,20);
	myRect.draw();

	
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

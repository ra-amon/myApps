#include "ofApp.h"
float distanceRight;
float distanceLeft;
float diraction;


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
	


	

	
	if(pct < 0.5){
	pos.x = (1-pct)* posa.x + (pct) * posb.x;
	pos.y = (1-pct)* posa.y + (pct)* posb.y;
	}else{
	pos.x = (1-pct)* posa.x + (pct) * posb.x;
	pos.y = (1-pct)* posb.y + (pct)* posa.y;
	}

	}
	void draw(){
		ofColor(0,0,255);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofRect(pos.x,pos.y, 20,20);
	}
};
Rect_2 myRect; 
float pct;
bool returnRect;



//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(30,30,30);
	diraction=0.0005;
	myRect.posa.x=10;
	myRect.posa.y= 300;

	myRect.shaper = 0.2;
	myRect.interp(0);
	pct =0;
	returnRect=true;


	ofSetBackgroundColor(255);




	ofSetColor(255);
	ofSetVerticalSync(true);
	ofSetCircleResolution(200);


		//make the connection
	myArduino.connect("COM4",57600);
	//to see if the arduino has been setup.
	bSetupArduino = false;
	counter = 500;
	
}



//--------------------------------------------------------------
void ofApp::update(){
	
			if(myArduino.isArduinoReady()){
		//when bsetupArduino is false it will run the setupArdiono to define the in and output of the arduiono
		if(bSetupArduino==false){
			setupArduino();
	//		we started running arduino, so no need to start setup again. 
			bSetupArduino=true;
		}
		//2nd run the update
		updateArduino();
	}
	check= ofGetElapsedTimeMillis();
		if(check>=counter){
			distanceRight=myArduino.getAnalog(0); //analog pin A0
			distanceLeft=myArduino.getAnalog(1); //analog pin A1
			// change 0-1023 to centimeters
			Rightvolt=ofMap(distanceRight, 0, 1023, 0, 5000); //5 volts
			Leftvolt=ofMap(distanceLeft, 0, 1023, 0, 5000); 
			Right=(21.61/(Rightvolt-0.1696))*1000;
			Left=(21.61/(Leftvolt-0.1696))*1000;
			counter=check+500; 
		}
		if(Right>50){
			Right=50;
		}
		if(Left>50){
			Left=50;
		}
		if(Right<8){
			Right=8;
		}
		if(Left<8){
			Left=7;
			}

		myRect.posb.x=ofMap(Right,8,50,0,ofGetWidth());
	myRect.posb.y=ofMap(Left,8,50,0,ofGetHeight());
		cout << distanceRight << endl;
	pct += diraction;
	

	if(pct>1) {
		pct=0;
		myRect.posa.x=myRect.posb.x;
		myRect.posa.y= myRect.posb.y;

	}


	myRect.interp(pct);



}


void ofApp::updateArduino(){
	//a call to update the arduino data ins and outs
	myArduino.update();
}
//this will setup all of my arduino pins. Difine the in and output of the arduino.
void ofApp::setupArduino(){
	
	myArduino.sendAnalogPinReporting(0, ARD_ANALOG);
	myArduino.sendAnalogPinReporting(1, ARD_ANALOG);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(255);
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

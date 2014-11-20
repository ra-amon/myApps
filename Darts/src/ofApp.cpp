#include "ofApp.h"
float distanceRight;
float distanceLeft;


//--------------------------------------------------------------
void ofApp::setup(){
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

		cout << Right << endl;

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

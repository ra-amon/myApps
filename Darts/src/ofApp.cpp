#include "ofApp.h"
float x,y;

//the target where you have to go.
ofPoint Target;

//points and balls
int points;
int maxPoints= 40;
//rect Size
int rectSize;


class Mover{
public:
	ofPoint location;
	ofPoint velocity;
	ofPoint accel;
	ofPoint Hands;
	ofPoint dir;
	//hitsound
	ofSoundPlayer hitsound;

	float maxspeed;
	Mover(){
		//hitsound
		hitsound.loadSound("HitSound.wav");
		maxspeed= ofRandom(1,2); //maxspeed and different for aal circles
		accel = ofPoint(-.001, .01);
		location = ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));  //random start of the circle
		velocity = ofPoint(ofRandom(-2.0,2.0), ofRandom(-2.0,2.0)); // random speed

		ofSetColor(100, ofRandom(255),100);
	}
	void update(){

		Hands= ofPoint(x,y); //location of the hands in the air  ( ir sensors)
		dir= ofPoint(Hands - location); 

		dir.normalize();
		dir *=0.01;
		accel= dir;

		velocity += accel; //speed
		location += velocity; // where is + the movement speed
		velocity.limit(maxspeed); //verctor doesnt get bigger then 3

		//collision target
		if(ofDist(Target.x,Target.y, location.x, location.y)<rectSize){
			points ++;
			Target=ofPoint(ofRandom(20,ofGetWidth()-20), ofRandom(20,ofGetHeight()-20));
			hitsound.play();
		}

	}
	//draw the circles
	void display(){
		ofFill();
		ofSetColor(255,10,50);
		ofCircle(location, 10);
	}
	// makes sure the balls wont fly out
	void checkEdges(){
		if(location.x > ofGetWidth()){
			velocity.x *=-1;
		}
		if(location.y > ofGetHeight()){
			velocity.y *=-1;
		}
		if(location.x <1 ){
			velocity.x *=-1;
		}
		if(location.y<0){
			velocity.y *=-1;
		}
	}
	
};

vector<Mover> player;


//--------------------------------------------------------------
void ofApp::setup(){
	//gamestate
	GameStart=true;
	//font
	Font.loadFont("Comenia Sans.otf", 18);
	//image
	target.loadImage("target.jpg");
	//sound
	
	backgroundSound.loadSound("background.mp3");
	backgroundSound.setLoop(true);

	//setup Balls;
	for(int i=0; i<maxPoints; i++){
		Mover *c = new Mover();
		player.push_back(*c);
	}

	//background
	ofBackground(30,30,30);
	ofSetBackgroundColor(255);

	//points
	points=0;

	//rect size
	rectSize=40;

	//set color;
	ofSetColor(255);
	ofSetVerticalSync(true);
	ofSetCircleResolution(200);


		//make the connection
	myArduino.connect("COM4",57600);
	//to see if the arduino has been setup.
	bSetupArduino = false;
	counter = 500;

	//target location
	Target=ofPoint(ofRandom(20,ofGetWidth()-20), ofRandom(20,ofGetHeight()-20));

	//playsound
	backgroundSound.play();
	
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
			
	if(GameStart==true){
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

		//map the variables of the ir sensor to the width and hight of the screen.
		x=ofMap(Right,8,30,ofGetWidth(),0);
		y=ofMap(Left,8,30,ofGetHeight(),0);

		// if the value of the sensors is higher then 50 set player in center of the screen.
	if(Right>30){
		x=ofGetWidth()/2;
	}
	if(Left>30){
		y=ofGetHeight()/2;
	}

	//make target smaller;
	for(int i=0; i<points; i++){
		rectSize= 40 - i*2;
	}
	

	//player code
	for(int i=0; i<1+points; i++){
	player[i].update();
	player[i].checkEdges();
	}

	if(rectSize<1){
		GameStart=false;
		time=check;
	}

	
	}else{
		
		rectSize=40;
	
	}
	cout<<check/1000<< endl;


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

	if(GameStart==true){

	ofBackground(0,0,0);
	for(int i=0; i<1+points; i++){
	player[i].display();
	}
	ofSetColor(255);
	target.draw(Target.x-rectSize/2,Target.y-rectSize/2 ,rectSize,rectSize);
		
	}
	else{
		ofSetColor(235,235,220);
		ofBackground(0,0,0);
		//text for the end of the game
		Font.drawString("Score Player 1 : "+ofToString(time/1000) ,200,200);;
		Font.drawString("\nGame over! Press any Space to restart", 200,220);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	//reset game
		GameStart=true;
		points = 0;
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

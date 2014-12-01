#include "ofApp.h"
//mouse things
//ofPoint mouse;
//ofPoint center;
//float m;


// douncing ball 3d
//ofPoint location;
//ofVec3f velocity;
//ofVec3f loc3D;

class Mover{
public:
	ofPoint location;
	ofPoint velocity;
	ofPoint accel;
	ofPoint mouse;
	ofPoint dir;
	Mover(){


		accel = ofPoint(-.001, .01);
		location = ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
		velocity = ofPoint(ofRandom(-2.0,2.0), ofRandom(2.0,2.0));

		ofSetColor(100, ofRandom(255),100);
	}
	void update(){

		mouse= ofPoint(ofGetMouseX(),ofGetMouseY());
		dir= ofPoint(mouse - location);

		dir.normalize();
		dir *=0.1;
		accel= dir;

		velocity += accel;
		location += velocity;
		velocity.limit(3); //verctor doesnt get bigger then 3
	}
	void display(){
		ofFill();
		ofCircle(location, 50);
	}
	void checkEdges(){
		if(location.x > ofGetWidth()) location.x =0;
		else if(location.y > ofGetHeight()) location.y=0;
		if(location.x<0) location.x=ofGetWidth();
	}

	static ofPoint add(ofPoint a, ofPoint b){
		return a+b;
	}
	
};
Mover *m;

//--------------------------------------------------------------
void ofApp::setup(){
	m = new Mover();

	//ofSetColor(255);
	//center = ofPoint(ofGetWidth()/2, ofGetHeight()/2);

	//ball bounce thing --------------------------------------------
	//location = ofPoint(100,100,5);
	//velocity =  ofVec3f(0.5,0.5, 0.2);
	//loc3D =  ofVec3f(100, 100, 20);

	//ofSetColor(255);
	//ofSetVerticalSync(true);
	//ofSetCircleResolution(200);
}

//--------------------------------------------------------------
void ofApp::update(){
m-> update();
m->checkEdges();

	//
	//mouse = ofPoint(mouseX, mouseY);
	//mouse -= center;
	////mouse = mouse /2;
	//m = mouse.length();
	//mouse.normalize();
	//mouse*=50;

	// ball bounce thing-----------------------------------------------
	//loc3D += velocity;
	//if((loc3D.x > ofGetWidth()) || loc3D.x <0){
	//	velocity.x = velocity.x * -1;
	//}
	//if((loc3D.y > ofGetHeight()) || loc3D.y <0){
	//	velocity.y *=-1;
	//}
	//if((loc3D.z>100)|| (loc3D.z <0)){
	//	velocity.z *=-1;
	//}
	//cout << loc3D.z << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
	m->display();
	//ofRect(0,0,m,10);
	//ofTranslate(center);
	//ofLine(0,0, mouse.x, mouse.y);

	//ofFill();
	//ofEllipse(loc3D.x, loc3D.y, loc3D.z, 50,50);
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

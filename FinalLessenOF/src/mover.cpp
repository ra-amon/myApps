#include "mover.h"

mover::mover(float m, float x, float y){
	location= ofVec2f(x,y);
	velocity = ofVec2f(0,0);
	accel = ofVec2f(0,0);
	mass =m;
	ofSetColor(255,3,20);
	ofSetBackgroundColor(0);
	ofSetCircleResolution(200);
	xEllipse=ofRandom(10,30);

}

void mover::update(){
	velocity += accel;
	location += velocity;
	accel *=0;

}

void mover::display(){
	ofFill();
	ofEllipse(location.x, location.y, xEllipse,xEllipse);
}


void mover::checkEdges(){
	if(location.x> ofGetWidth()){
		location.x= ofGetWidth();
		velocity.x *=-1;
	}else if(location.x<0){
		velocity.x *=-1;
		location.x=0;
}

	if(location.y > ofGetHeight()){
		location.y = ofGetHeight();
		velocity.y *= -1;
	}else if(location.y < 0){
		location.y = 0;
		velocity.y *=-1;
	} 
}


void mover::applyForce(ofVec2f force){
	ofVec2f f = force/mass;
	accel +=f; 
}
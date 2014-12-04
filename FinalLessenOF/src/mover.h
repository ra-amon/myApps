
#pragma once
#include "ofMain.h"

class mover{
public:
	mover(float m, float x, float y);
	void update();
	void display();
	void checkEdges();
	void applyForce(ofVec2f force);
	float mass;
	ofVec2f accel;
	ofVec2f velocity;
	ofVec2f location;
	int xEllipse, yEllipse;

};

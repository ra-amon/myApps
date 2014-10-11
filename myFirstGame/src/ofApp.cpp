#include "ofApp.h"
//Player1 variables
float player1Radius;
float XposPlayer1;
float YposPlayer1;
float X1Loaction;
float Y1Loaction; 
// weapon player 1 position
float XposWeapon1;
float YposWeapon1;
bool player1Up, player1Down, player1Left,player1Right;
bool player2Up, player2Down, player2Left, player2Right;

float XposPlayer2;
float YposPlayer2;
float X2Loaction;
float Y2Loaction; 
// weapon player 1 position
float XposWeapon2;
float YposWeapon2;

float retreat;
int scorePlayer1;
int scorePlayer2;
int bounce;
bool hasLostGame;

float playerSpeed;
float Yspeed;
float Xspeed;
float WeaponSpeedX; //speed of the moving weapon
float WeaponSpeedY;
float WeaponRadius; // radius of the weapon


//--------------------------------------------------------------
void ofApp::setup(){
	WeaponRadius = 20;
	player1Radius = 30;
	//player1 start pos
	XposPlayer1=500;
	YposPlayer1=500;
	//posision player1 weapon
	YposWeapon1 =300;
	XposWeapon1=300;
	//player2 start pos
	XposPlayer2=600;
	YposPlayer2=200;
	//posision player2 weapon
	YposWeapon2 =400;
	XposWeapon2=200;
	//starting speed weapons
	Xspeed=0;
	Yspeed=0;
	//playerspeed
	playerSpeed=0.8;
	//player1 activated direction
	player1Up=false;
	player1Down=false;
	player1Left=false;
	player1Right=false;
	//player2 activated direction
	player2Up=false;
	player2Left=false;
	bounce = 0;
	//the distance to trigger the weapon
	retreat = 350;
	hasLostGame = false;
	scorePlayer1 = 0;
	scorePlayer2 = 0;
	ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
	//all math stuff
	if(hasLostGame==false){
	 //player1 direction
	  if(player1Up==true){//up
		  YposPlayer1 +=playerSpeed;
	  }else{
		  YposPlayer1+=0;
	  }
	  if(player1Down==true){//down
		  YposPlayer1 -=playerSpeed;
	  }else{
		  YposPlayer1+=0;
	  }
	  if(player1Left==true){//left
		  XposPlayer1 -=playerSpeed;
	  }else{
		  XposPlayer1 +=0;
	  }
	   if(player1Right==true){//right
		  XposPlayer1 +=playerSpeed;
	  }else{
		  XposPlayer1 +=0;
	  }
	  //player2 direction
	   if(player2Up==true){ //up
		  YposPlayer2 +=playerSpeed;
	  }else{
		  YposPlayer2 +=0;
	  }
	   if(player2Down==true){//down
		  YposPlayer2 -=playerSpeed;
	  }else{
		  YposPlayer2 +=0;
	  }
	  if(player2Left==true){//left
		  XposPlayer2 -=playerSpeed;
	  }else{
		  XposPlayer1 +=0;
	  }
	  if(player2Right==true){//right
		  XposPlayer2 +=playerSpeed;
	  }else{
		  XposPlayer1 +=0;
	  }

		//sees when the player2 is to far away
		if(ofDist(XposPlayer1,YposPlayer1,XposWeapon1,YposWeapon1)>retreat){
			bounce ++;
			//give the X and Y posistion of the player2
		for(int i=0; i<bounce; i++){
			X1Loaction=XposPlayer1;
			Y1Loaction=YposPlayer1;
			}
		}
		// if c>0 c/a=x, if c<0 c/b=x  x=position of the player2 can be X or Y
	    //c          a       b   
		Xspeed =X1Loaction-XposWeapon1;
		Yspeed= Y1Loaction-YposWeapon1;
			
		if(Xspeed<0){
			WeaponSpeedX =Xspeed/XposWeapon1;
		}else{
			WeaponSpeedX= Xspeed/X1Loaction;
		}

		if(Xspeed<0){
			WeaponSpeedY =Yspeed/YposWeapon1;
		}else{
			WeaponSpeedY= Yspeed/Y1Loaction;
				}
		//give the speed to the weapon
		XposWeapon1 += WeaponSpeedX*2;
		YposWeapon1 += WeaponSpeedY*2;
	
		// player1 cant leave the playfield
		if(XposWeapon1<0){
			XposWeapon1=0+WeaponRadius;
		}
		if(XposWeapon1 > ofGetWidth()){
			XposWeapon1=ofGetWidth()-WeaponRadius;
		}
		if(YposWeapon1<0){
			YposWeapon1=0+WeaponRadius;	;
		}
		if(YposWeapon1 > ofGetHeight()){
			YposWeapon1=ofGetHeight()-WeaponRadius;
		}

		if(YposPlayer1<0){
			YposPlayer1=ofGetHeight()-player1Radius;	;
		}
		if(YposPlayer1 > ofGetHeight()){
			YposPlayer1=0+player1Radius;
		}
		if(XposPlayer1<0){
			XposPlayer1=ofGetWidth()-player1Radius;	;
		}
		if(XposPlayer1 > ofGetWidth()){
			XposPlayer1=0+player1Radius;
		}

	//sees when the player2 is to far away
		if(ofDist(XposPlayer2,YposPlayer2,XposWeapon2,YposWeapon2)>retreat){
			bounce ++;
			//give the X and Y posistion of the player2
			for(int i=0; i<bounce; i++){
				X2Loaction=XposPlayer2;
				Y2Loaction=YposPlayer2;
			}
  
		}
	    // if c>0 c/a=x, if c<0 c/b=x  x=position of the player can be X or Y
	    //c          a       b   
		Xspeed =X2Loaction-XposWeapon2;
		Yspeed= Y2Loaction-YposWeapon2;
			
		if(Xspeed<0){
			WeaponSpeedX =Xspeed/XposWeapon2;
		}else{
			WeaponSpeedX= Xspeed/X2Loaction;
		}

		if(Xspeed<0){
			WeaponSpeedY =Yspeed/YposWeapon2;
		}else{
			WeaponSpeedY= Yspeed/Y2Loaction;
		}
		//give the speed to the weapon
		XposWeapon2 += WeaponSpeedX*2;
		YposWeapon2 += WeaponSpeedY*2;
		
		//make sure the player doesnt fall of the screen
		if(XposWeapon2 < 0){
		XposWeapon2=0+WeaponRadius;
		}
		if(XposWeapon2 > ofGetWidth()){
		XposWeapon2=ofGetWidth()-WeaponRadius;
		}
		if(YposWeapon2<0){
		YposWeapon2=0+WeaponRadius;	;
		}
		if(YposWeapon2 > ofGetHeight()){
		YposWeapon2=ofGetHeight()-WeaponRadius;
		}

		if(YposPlayer2<0){
		YposPlayer2=ofGetHeight()-player1Radius;	;
		}
		if(YposPlayer2 > ofGetHeight()){
		YposPlayer2=0+player1Radius;
		}
		if(XposPlayer2<0){
			XposPlayer2=ofGetWidth()-player1Radius;	;
		}
		if(XposPlayer2 > ofGetWidth()){
			XposPlayer2=0+player1Radius;
		}
	
		//makes sure player can't go through eachother.
		if(ofDist(XposPlayer1,YposPlayer1,XposPlayer2,YposPlayer2)<=player1Radius+player1Radius){
		//checks where the players X are to make sure they bounce in the right direction.
			if(XposPlayer1>XposPlayer2){
			XposPlayer1=XposPlayer1+2;
			YposPlayer1=YposPlayer1+2;
			XposPlayer2=XposPlayer2-2;
			YposPlayer2=YposPlayer2-2;
			}else{
			XposPlayer1=XposPlayer1-2;
			YposPlayer1=YposPlayer1-2;
			XposPlayer2=XposPlayer2+2;
			YposPlayer2=YposPlayer2+2;
			}
		}

		if(ofDist(XposPlayer1,YposPlayer1,XposWeapon2,YposWeapon2) < player1Radius+WeaponRadius){
		scorePlayer2++;
			}
			if(ofDist(XposPlayer2,YposPlayer2,XposWeapon1,YposWeapon1) < player1Radius+WeaponRadius){
			scorePlayer1++;
			}
			if(scorePlayer1>=1000 || scorePlayer2==1000){
				hasLostGame=true;
			}
	}
}


//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0,0,0);
	//this is the weapon player 1
	ofSetColor(255,0,0);
	ofCircle(XposWeapon1,YposWeapon1,WeaponRadius);
	ofLine(XposPlayer1,YposPlayer1,XposWeapon1,YposWeapon1);
	//this is the player1
	ofSetColor(0,0,255);
	ofCircle(XposPlayer1,YposPlayer1, player1Radius);
	ofSetColor(255,255,255);
	
	//this is the weapon player 2
	ofSetColor(255,0,0);
	ofCircle(XposWeapon2,YposWeapon2,WeaponRadius);
	ofLine(XposPlayer2,YposPlayer2,XposWeapon2,YposWeapon2);
	//this is the player2
	ofSetColor(0,255,0);
	ofCircle(XposPlayer2,YposPlayer2, player1Radius);
	ofSetColor(255,255,255);

	//show score players
	ofDrawBitmapString("Score Player 1 : "+ofToString(scorePlayer1), 20, 20);
	ofDrawBitmapString("\nScore Player 2 : "+ofToString(scorePlayer2), 20, 20);
	//when game is over display score and option to restart
	if(hasLostGame){
		ofSetColor(255,0,0);
		ofBackground(0,0,0);
	ofDrawBitmapString("Score Player 1 : "+ofToString(scorePlayer1),ofGetWidth()/2-200,ofGetHeight()/2);
	ofDrawBitmapString("\nScore Player 2 : "+ofToString(scorePlayer2),ofGetWidth()/2-200,ofGetHeight()/2);
		ofDrawBitmapString("\nGame over! Press any Space to restart", ofGetWidth()/2-200,ofGetHeight()/2+20);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//listeners 
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
		//controls player1 "arrows
	if(key== 359 && player1Up==false){ //up
		player1Up=true;
		player1Down=false;
		player1Right=false;
		player1Left=false;
		}

	if(key== 357){ //down
		player1Up=false;
		player1Down=true;
		player1Right=false;
		player1Left=false;
		}
	if(key== 356){ //left
		player1Left=true;
		player1Right=false;
		player1Up=false;
		player1Down=false;
		}
	if(key== 358){ //right
		player1Left=false;
		player1Up=false;
		player1Down=false;
		player1Right=true;
		}
	//space to stop all movemend
	if(key==32){ //space
		player1Left=false;
		player1Right=false;
		player1Up=false;
		player1Down=false;
	}

	//controls player2
	if(key== 115){ //up "w"
		player2Up=true;
		player2Down=false;
		player2Left=false;
		player2Right=false;
		}
	if(key== 119){ //down "s"
		player2Up=false;
		player2Down=true;
		player2Left=false;
		player2Right=false;
		}
	if(key== 97){ // left "a"
		player2Left=true;
		player2Right=false;
		player2Up=false;
		player2Down=false;
		}
	if(key== 100){ // right "d"
		player2Left=false;
		player2Right=true;
		player2Up=false;
		player2Down=false;
	}
	if(key==116){ //"t"
		player2Left=false;
		player2Right=false;
		player2Up=false;
		player2Down=false;
	}
	
	
	//resets the game
	if(hasLostGame && key==32){
		WeaponRadius =20;
		ofBackground(255,0,0);
		hasLostGame=false;
		scorePlayer1 =0;
		scorePlayer2=0;
		XposPlayer1=500;
		YposPlayer1=500;
		//posision player1 weapon
		YposWeapon1 =300;
		XposWeapon1=300;
		//player2 start pos
		XposPlayer2=600;
		YposPlayer2=200;
		//posision player2 weapon
		YposWeapon2 =400;
		XposWeapon2=200;
		}
		cout<<key;
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

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	//images
	weapon.loadImage("weapon_01.png");
	//player images
	player1.loadImage("player1.png");
	player2.loadImage("player2.png");
	//sounds
	Hit.loadSound("Hit.mp3");
	Hit.setVolume(0.02);
	backgroundSound.loadSound("background.mp3");
	backgroundSound.setLoop(true);
	//fonts
	Font.loadFont("Comenia Sans.otf", 12);
	//make the connection
	myArduino.connect("COM4",57600);
	//to see if the arduino has been setup.
	bSetupArduino = false;

	//gamecode
	WeaponRadius = 30;
	playerRadius = 30;
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
	Xspeed1=0;
	Yspeed1=0;
	//playerspeed
	playerSpeed=0.5;
	//player1 activated direction
	player1Atteck=false;
	player1Up=false;
	player1Down=false;
	player1Left=false;
	player1Right=false;
	//player2 activated direction
	player2Up=false;
	player2Left=false;
	bounce1 = 0;
	bounce2= 0;
	//the distance to trigger the weapon
	retreat = 350;
	hasLostGame = false;
	//weapon 1 speed
	Weapon1SpeedX=0;
	Weapon1SpeedY=0;
	//weapon 2 speed
	Weapon2SpeedX=0;
	Weapon2SpeedY=0;
	//check if the player is hit by the weapon
	player1Hit=false;
	player2Hit=false;
	//playerscore
	scorePlayer1 = 0;
	scorePlayer2 = 0;
	Hitvalue2=0;
	ofSetVerticalSync(true);

	backgroundSound.play();
}

void ofApp::updateArduino(){
	//a call to update the arduino data ins and outs
	myArduino.update();
}
//this will setup all of my arduino pins. Difine the in and output of the arduino.
void ofApp::setupArduino(){
	myArduino.sendDigitalPinMode(9, ARD_OUTPUT); //output pin 9
}

//--------------------------------------------------------------
void ofApp::update(){
	//all math stuff
	
	//first step
	//if my arduino is ready ---> its a must to make openframworks to run with the arduino
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


	if(hasLostGame==false){
		//playbackgrondsound
		
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
	  pullToPlayer();

		if(ofDist(XposPlayer1,YposPlayer1,XposWeapon2,YposWeapon2) < playerRadius+WeaponRadius){
			player2Hit=true;
			Hitvalue2++;
			if(player2Hit==true && Hitvalue2==1){
			scorePlayer2++;
			Hit.play();
			
			}
		}else{
			player2Hit=false;
			Hitvalue2=0;
		}
		
		

		if(ofDist(XposPlayer2,YposPlayer2,XposWeapon1,YposWeapon1) < playerRadius+WeaponRadius){
			player1Hit=true;
			Hitvalue1++;
			if(player1Hit==true && Hitvalue1==1){
			scorePlayer1++;
			Hit.play();
			
			}
		}else{
			player1Hit=false;
			Hitvalue1=0;
		}
		if(scorePlayer1>=5 || scorePlayer2==5){
			hasLostGame=true;
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw(){

	//turn th 9th pin on the arduino on
	if(hasLostGame==false){

		myArduino.sendDigital(7, ARD_HIGH);
	   myArduino.sendDigital(9, ARD_LOW);
	   
	   
	ofBackground(0,0,0);

	//playerlines
	   ofSetColor(255,0,0);
	ofLine(XposPlayer1,YposPlayer1,XposWeapon1,YposWeapon1);
	ofLine(XposPlayer2,YposPlayer2,XposWeapon2,YposWeapon2);
	//this is the weapon player 1
	ofSetColor(255,255,255);
	weapon.draw(XposWeapon1-WeaponRadius,YposWeapon1-WeaponRadius);
	//this is the player1
	player1.draw(XposPlayer1-playerRadius,YposPlayer1-playerRadius);
	//this is the weapon player 2
	weapon.draw(XposWeapon2-WeaponRadius,YposWeapon2-WeaponRadius);
	//this is the player2
	player2.draw(XposPlayer2-playerRadius,YposPlayer2-playerRadius);
	ofSetColor(255,255,255);



	//show score players
	Font.drawString("Score Player 1 : "+ofToString(scorePlayer1), 20, 20);
	Font.drawString("\nScore Player 2 : "+ofToString(scorePlayer2), 20, 20);
	}
	//when game is over display score and option to restart
	if(hasLostGame){
		//turn of the led off
		myArduino.sendDigital(9, ARD_HIGH);
		myArduino.sendDigital(7, ARD_LOW);

		ofSetColor(255,0,0);
		ofBackground(0,0,0);
	Font.drawString("Score Player 1 : "+ofToString(scorePlayer1),ofGetWidth()/2-200,ofGetHeight()/2);
	Font.drawString("\nScore Player 2 : "+ofToString(scorePlayer2),ofGetWidth()/2-200,ofGetHeight()/2);
		Font.drawString("\nGame over! Press any Space to restart", ofGetWidth()/2-200,ofGetHeight()/2+20);
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
	
}


//the math to make sure the player pulls the weapon
void ofApp::pullToPlayer(){
	//------------------------------------------------------------ player1------------------------------//
	//sees when the player1 is to far away
		if(ofDist(XposPlayer1,YposPlayer1,XposWeapon1,YposWeapon1)>retreat){
			bounce1 ++;
			//give the X and Y posistion of the player2
		for(int i=0; i<bounce1; i++){
			X1Loaction=XposPlayer1;
			Y1Loaction=YposPlayer1;
			}
		}
		// if c>0 c/a=x, if c<0 c/b=x  x=position of the player2 can be X or Y
	    //c          a       b   
		Xspeed1 = X1Loaction-XposWeapon1;
		Yspeed1 = Y1Loaction-YposWeapon1;
			
		if(Xspeed1<0){
			Weapon1SpeedX =0+Xspeed1/XposWeapon1;
		}else{
			Weapon1SpeedX=Xspeed1/X1Loaction;
		}

		if(Yspeed1<0){
			Weapon1SpeedY =0+Yspeed1/YposWeapon1;
		}else{
			Weapon1SpeedY= Yspeed1/Y1Loaction;
				}


		//give the speed to the weapon
		XposWeapon1 += Weapon1SpeedX*2;
		YposWeapon1 += Weapon1SpeedY*2;

		
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
		//player spawn on the other side of the screen
		if(YposPlayer1<0){
			YposPlayer1=ofGetHeight()-playerRadius;	;
		}
		if(YposPlayer1 > ofGetHeight()){
			YposPlayer1=0+playerRadius;
		}
		if(XposPlayer1<0){
			XposPlayer1=ofGetWidth()-playerRadius;	;
		}
		if(XposPlayer1 > ofGetWidth()){
			XposPlayer1=0+playerRadius;
		}
		//------------------------------------------------- player 2 -----------------------------------------//
	//sees when the player2 is to far away
		if(ofDist(XposPlayer2,YposPlayer2,XposWeapon2,YposWeapon2)>retreat){
			bounce2 ++;
			//give the X and Y posistion of the player2
			for(int i=0; i<bounce2; i++){
				X2Loaction=XposPlayer2;
				Y2Loaction=YposPlayer2;
			}
  
		}
	    // if c>0 c/a=x, if c<0 c/b=x  x=position of the player can be X or Y
	    //c          a       b   
		Xspeed2 =X2Loaction-XposWeapon2;
		Yspeed2= Y2Loaction-YposWeapon2;
			
		if(Xspeed2<0){
			Weapon2SpeedX =Xspeed2/XposWeapon2;
		}else{
			Weapon2SpeedX= Xspeed2/X2Loaction;
		}

		if(Yspeed2<0){
			Weapon2SpeedY =Yspeed2/YposWeapon2;
		}else{
			Weapon2SpeedY= Yspeed2/Y2Loaction;
		}
		//give the speed to the weapon
		XposWeapon2 += Weapon2SpeedX*2;
		YposWeapon2 += Weapon2SpeedY*2;
		
		//make sure the weapon doesnt fall of the screen
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
		//player can spawn on the other side.
		if(YposPlayer2<0){
		YposPlayer2=ofGetHeight()-playerRadius;	;
		}
		if(YposPlayer2 > ofGetHeight()){
		YposPlayer2=0+playerRadius;
		}
		if(XposPlayer2<0){
			XposPlayer2=ofGetWidth()-playerRadius;	;
		}
		if(XposPlayer2 > ofGetWidth()){
			XposPlayer2=0+playerRadius;
		}
	
		//makes sure player can't go through eachother.
		if(ofDist(XposPlayer1,YposPlayer1,XposPlayer2,YposPlayer2)<=playerRadius+playerRadius){
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

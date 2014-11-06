#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	for(int x = 0; x< 3; x++){
		Player c;
		c.playerRadius=30;
		c.XposPlayer=ofRandom(ofGetWidth()); //spawn
		c.YposPlayer=ofRandom(ofGetHeight()); //spawn
		c.XLoaction;
		c.YLoaction;
		//force
		c.newLocX;
		c.newLocY;
		//controls
		c.up=false;
		c.down=false;
		c.left=false;
		c.right=false;
		c.playerHit=false;// weapon hit
		c.bounce=0; // makes players bounce of,off eatchother
		c.playerScore=0; //player score
		//weapon location
		c.XposWeapon=ofRandom(ofGetWidth());
		c.YposWeapon=ofRandom(ofGetWidth());
		players.push_back(c);

	}
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
	//radius weapon
	WeaponRadius=33;


	Xspeed1=0;
	Yspeed1=0;
	//playerspeed
	playerSpeed=0.5;
	//the distance to trigger the weapon
	retreat = 350;
	hasLostGame = false;
	//weapon 1 speed
	Weapon1SpeedX=0;
	Weapon1SpeedY=0;
	//weapon 2 speed
	Weapon2SpeedX=0;
	Weapon2SpeedY=0;
	Hitvalue2=0;
	ofSetVerticalSync(true);
	//playbackgrondsound
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
		//playerspeed


		//player one controls
		if(players[1].up==true){
			players[1].YposPlayer --;
		}
		if(players[1].down==true){
			players[1].YposPlayer++;
		}
		if(players[1].left==true){
			players[1].XposPlayer --;
		}
		if(players[1].right==true){
			players[1].XposPlayer++;
		}
		//player 2 controls
		if(players[2].up==true){
			players[2].YposPlayer --;
		}
		if(players[2].down==true){
			players[2].YposPlayer++;
		}
		if(players[2].left==true){
			players[2].XposPlayer --;
		}
		if(players[2].right==true){
			players[2].XposPlayer++;
		}

	  pullToPlayer();
	 // //player score counter. player 1
		if(ofDist(players[1].XposPlayer,players[1].YposPlayer,players[2].XposWeapon,players[2].YposWeapon) < players[1].playerRadius+WeaponRadius){
			players[2].playerHit=true;
			Hitvalue2++;
			if(players[2].playerHit==true && Hitvalue2==1){
			players[2].playerScore++;
			Hit.play();
			
			}
		}else{
			players[2].playerHit=false;
			Hitvalue2=0;
		}
		
		
		//player score 2
		if(ofDist(players[2].XposPlayer,players[2].YposPlayer,players[1].XposWeapon,players[1].YposWeapon) < players[1].playerRadius+WeaponRadius){
			players[1].playerHit=true;
			Hitvalue1++;  //counts up when true
			if(players[1].playerHit==true && Hitvalue1==1){ //when it is 1 score will go +1
			players[1].playerScore++;
			Hit.play();
			
			}
			//when false the counter will reset so when it hits again you add 1 to the score again.
		}else{
			players[1].playerHit=false;
			Hitvalue1=0;
		}
		if(players[1].playerScore>=5 || players[2].playerScore==5){
			hasLostGame=true;
		}

	}

}


//--------------------------------------------------------------
void ofApp::draw(){

	//turn th 9th pin on the arduino on
	if(hasLostGame==false){
			ofBackground(0,0,0);
		myArduino.sendDigital(7, ARD_HIGH);
	   myArduino.sendDigital(9, ARD_LOW);
	   	//this is the weapon player 1


	   for(int i=0; i<players.size(); i++){
		   ofSetColor(255);
		   //lines connecting the players to the weapon
	ofLine(players[1].XposPlayer,players[1].YposPlayer,players[1].XposWeapon,players[1].YposWeapon);
	ofLine(players[2].XposPlayer,players[2].YposPlayer,players[2].XposWeapon,players[2].YposWeapon);
			weapon.draw(players[1].XposWeapon-WeaponRadius,players[1].YposWeapon-WeaponRadius);

	//this is the weapon player 2
	weapon.draw(players[2].XposWeapon-WeaponRadius,players[2].YposWeapon-WeaponRadius);
	//players
	player1.draw(players[1].XposPlayer-players[1].playerRadius,players[1].YposPlayer-players[1].playerRadius);
	player2.draw(players[2].XposPlayer-players[2].playerRadius,players[2].YposPlayer-players[2].playerRadius);

	   }

	  



	//show score players
	Font.drawString("Score Player 1 : "+ofToString(players[1].playerScore), 20, 20);
	Font.drawString("\nScore Player 2 : "+ofToString(players[2].playerScore), 20, 20);
	}
	//when game is over display score and option to restart
	if(hasLostGame){
		//turn of the led off
		myArduino.sendDigital(9, ARD_HIGH);
		myArduino.sendDigital(7, ARD_LOW);

		ofSetColor(255,0,0);
		ofBackground(0,0,0);
	Font.drawString("Score Player 1 : "+ofToString(players[1].playerScore),ofGetWidth()/2-200,ofGetHeight()/2);
	Font.drawString("\nScore Player 2 : "+ofToString(players[2].playerScore),ofGetWidth()/2-200,ofGetHeight()/2);
		Font.drawString("\nGame over! Press any Space to restart", ofGetWidth()/2-200,ofGetHeight()/2+20);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//listeners 

		if(key== 357 ){ //up	
			players[1].up=true;
		}

	if(key== 359){ //down
		players[1].down=true;
		}
	if(key== 356){ //left
		players[1].left=true;
		}
	if(key== 358){ //right
		players[1].right=true;
		}
	
	//player2
	if(key== 119 ){ //up	
		players[2].up=true;
		}

	if(key== 115){ //down
		players[2].down=true;
		}
	if(key== 97){ //left
		players[2].left=true;
		}
	if(key== 100){ //right
		players[2].right=true;
		}
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(key== 357 ){ //up
		players[1].up=false;
		}

	if(key== 359){ //down
		players[1].down=false;
		}
	if(key== 356){ //left
		players[1].left=false;
		}
	if(key== 358){ //right
		players[1].right=false;
		}
		//player2
		if(key== 119 ){ //up	
		players[2].up=false;
		}

	if(key== 115){ //down
		players[2].down=false;
		}
	if(key== 97){ //left
		players[2].left=false;
		}
	if(key== 100){ //right
		players[2].right=false;
		}
	//resets the game
	if(hasLostGame && key==32){
		ofBackground(255,0,0);
		hasLostGame=false;
		players[1].playerScore =0;
		players[2].playerScore=0;
		players[1].XposPlayer=ofRandom(ofGetWidth());
		players[1].YposPlayer=ofRandom(ofGetHeight());
		//posision player1 weapon
		players[1].YposWeapon =ofRandom(ofGetHeight());
		players[1].XposWeapon=ofRandom(ofGetWidth());
		//player2 start pos
		players[2].XposPlayer=ofRandom(ofGetWidth());
		players[2].YposPlayer=ofRandom(ofGetHeight());
		//posision player2 weapon
		players[2].YposWeapon =ofRandom(ofGetHeight());
		players[2].XposWeapon=ofRandom(ofGetWidth());
		//reset bounce
		players[1].bounce=0;
		players[2].bounce=0;
		}
	
}


//the math to make sure the player pulls the weapon
void ofApp::pullToPlayer(){
	//------------------------------------------------------------ player1------------------------------//
	//sees when the player1 is to far away
	
		if(ofDist(players[1].XposPlayer,players[1].YposPlayer,players[1].XposWeapon,players[1].YposWeapon)>retreat){
			players[1].bounce ++;
			//give force to the weapon
			players[1].newLocX=(players[1].XposPlayer-players[1].XposWeapon)*0.5; //distance * 1/3 as the force
			players[1].newLocY=(players[1].YposPlayer-players[1].YposWeapon)*0.5;
	//give the X and Y posistion of the player2
		for(int i=0; i<players[1].bounce; i++){
			players[1].XLoaction=players[1].XposPlayer+players[1].newLocX;
			players[1].YLoaction=players[1].YposPlayer+players[1].newLocY;
			}
		}
		// if c>0 c/a=x, if c<0 c/b=x  x=position of the player2 can be X or Y
	    //c          a       b   
		Xspeed1 = players[1].XLoaction-players[1].XposWeapon;
		Yspeed1 = players[1].YLoaction-players[1].YposWeapon;
			
		if(Xspeed1<0){
			Weapon1SpeedX =0+Xspeed1/players[1].XposWeapon;
		}else{
			Weapon1SpeedX=Xspeed1/players[1].XLoaction;
		}

		if(Yspeed1<0){
			Weapon1SpeedY =0+Yspeed1/players[1].YposWeapon;
		}else{
			Weapon1SpeedY= Yspeed1/players[1].YLoaction;
				}


		//give the speed to the weapon
		players[1].XposWeapon += Weapon1SpeedX;
		players[1].YposWeapon += Weapon1SpeedY;

		
		//player spawn on the other side of the screen
		if(players[1].XposWeapon<0){
			players[1].XposWeapon=0+WeaponRadius;
		}
		if(players[1].XposWeapon > ofGetWidth()){
			players[1].XposWeapon=ofGetWidth()-WeaponRadius;
		}
		if(players[1].YposWeapon<0){
			players[1].YposWeapon=0+WeaponRadius;	;
		}
		if(players[1].YposWeapon > ofGetHeight()){
			players[1].YposWeapon=ofGetHeight()-WeaponRadius;
		}
		//player spawn on the other side of the screen
		if(players[1].YposPlayer<0){
			players[1].YposPlayer=ofGetHeight()-players[1].playerRadius;	;
		}
		if(players[1].YposPlayer > ofGetHeight()){
			players[1].YposPlayer=0+players[1].playerRadius;
		}
		if(players[1].XposPlayer<0){
			players[1].XposPlayer=ofGetWidth()-players[1].playerRadius;	;
		}
		if(players[1].XposPlayer > ofGetWidth()){
			players[1].XposPlayer=0+players[1].playerRadius;
		}

		//------------------------------------------------- player 2 -----------------------------------------//
	//sees when the player2 is to far away
		if(ofDist(players[2].XposPlayer,players[2].YposPlayer,players[2].XposWeapon,players[2].YposWeapon)>retreat){
			players[2].bounce ++;
			//give the weapon force
			players[2].newLocX=(players[2].XposPlayer-players[2].XposWeapon)*0.33;
			players[2].newLocY=(players[2].YposPlayer-players[2].YposWeapon)*0.33;
			//give the X and Y posistion of the player2
			for(int i=0; i<players[2].bounce; i++){
				players[2].XLoaction=players[2].XposPlayer+players[2].newLocX;
				players[2].YLoaction=players[2].YposPlayer+players[2].newLocY;
			}
  
		}
	    // if c>0 c/a=x, if c<0 c/b=x  x=position of the player can be X or Y
	    //c          a       b   
		Xspeed2 =players[2].XLoaction-players[2].XposWeapon;
		Yspeed2= players[2].YLoaction-players[2].YposWeapon;
			
		if(Xspeed2<0){
			Weapon2SpeedX =Xspeed2/players[2].XposWeapon;
		}else{
			Weapon2SpeedX= Xspeed2/players[2].XLoaction;
		}

		if(Yspeed2<0){
			Weapon2SpeedY =Yspeed2/players[2].YposWeapon;
		}else{
			Weapon2SpeedY= Yspeed2/players[2].YLoaction;
		}
		//give the speed to the weapon
		players[2].XposWeapon += Weapon2SpeedX;
		players[2].YposWeapon += Weapon2SpeedY;
		
		//make sure the weapon doesnt fall of the screen
		if(players[2].XposWeapon < 0){
		players[2].XposWeapon=0+WeaponRadius;
		}
		if(players[2].XposWeapon > ofGetWidth()){
		players[2].XposWeapon=ofGetWidth()-WeaponRadius;
		}
		if(players[2].YposWeapon<0){
		players[2].YposWeapon=0+WeaponRadius;	;
		}
		if(players[2].YposWeapon > ofGetHeight()){
		players[2].YposWeapon=ofGetHeight()-WeaponRadius;
		}
		//player can spawn on the other side.
		if(players[2].YposPlayer<0){
		players[2].YposPlayer=ofGetHeight()-players[1].playerRadius;	;
		}
		if(players[2].YposPlayer > ofGetHeight()){
		players[2].YposPlayer=0+players[1].playerRadius;
		}
		if(players[2].XposPlayer<0){
			players[2].XposPlayer=ofGetWidth()-players[1].playerRadius;	;
		}
		if(players[2].XposPlayer > ofGetWidth()){
			players[2].XposPlayer=0+players[1].playerRadius;
		}
	
		//makes sure player can't go through eachother.
		if(ofDist(players[1].XposPlayer,players[1].YposPlayer,players[2].XposPlayer,players[2].YposPlayer)<=players[1].playerRadius+players[1].playerRadius){
		//checks where the players X are to make sure they bounce in the right direction.
			if(players[1].XposPlayer>players[2].XposPlayer){
			players[1].XposPlayer=players[1].XposPlayer+2;
			players[1].YposPlayer=players[1].YposPlayer+2;
			players[2].XposPlayer=players[2].XposPlayer-2;
			players[2].YposPlayer=players[2].YposPlayer-2;
			}else{
			players[1].XposPlayer=players[1].XposPlayer-2;
			players[1].YposPlayer=players[1].YposPlayer-2;
			players[2].XposPlayer=players[2].XposPlayer+2;
			players[2].YposPlayer=players[2].YposPlayer+2;
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

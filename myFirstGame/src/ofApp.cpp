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
		//controls
		c.up=false;
		c.down=false;
		c.left=false;
		c.right=false;
		c.playerHit=false;// weapon hit
		c.bounce=0; // makes players bounce of,off eatchother
		c.playerScore=0; //player score
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
	WeaponRadius = 30;
	//posision player1 weapon
	YposWeapon1 =300;
	XposWeapon1=300;
	//posision player2 weapon
	YposWeapon2 =400;
	XposWeapon2=200;
	//starting speed weapons
	Xspeed1=0;
	Yspeed1=0;
	//playerspeed
	playerSpeed=0.8;
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
		if(ofDist(players[1].XposPlayer,players[1].YposPlayer,XposWeapon2,YposWeapon2) < players[1].playerRadius+WeaponRadius){
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
		if(ofDist(players[2].XposPlayer,players[2].YposPlayer,XposWeapon1,YposWeapon1) < players[1].playerRadius+WeaponRadius){
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
	   for(int i=0; i<players.size(); i++){
	ofLine(players[1].XposPlayer,players[1].YposPlayer,XposWeapon1,YposWeapon1);
	ofLine(players[2].XposPlayer,players[2].YposPlayer,XposWeapon2,YposWeapon2);
	player1.draw(players[1].XposPlayer-players[1].playerRadius,players[1].YposPlayer-players[1].playerRadius);
	player2.draw(players[2].XposPlayer-players[2].playerRadius,players[2].YposPlayer-players[2].playerRadius);
	   }
	   


	//playerlines
	   ofSetColor(255,0,0);
	//ofLine(players[1].XposPlayer,players[1].YposPlayer,XposWeapon1,YposWeapon1);
	//ofLine(players[2].XposPlayer,players[2].YposPlayer,XposWeapon2,YposWeapon2);
	//this is the weapon player 1
	ofSetColor(255,255,255);
	weapon.draw(XposWeapon1-WeaponRadius,YposWeapon1-WeaponRadius);
	//this is the player1
	/*player1.draw(players[1].XposPlayer-playerRadius,players[1].YposPlayer-playerRadius);*/
	//this is the weapon player 2
	weapon.draw(XposWeapon2-WeaponRadius,YposWeapon2-WeaponRadius);
	//this is the player2
	/*player2.draw(players[2].XposPlayer-playerRadius,players[2].YposPlayer-playerRadius);*/
	ofSetColor(255,255,255);



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
	cout<<key;
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
		WeaponRadius =20;
		ofBackground(255,0,0);
		hasLostGame=false;
		players[1].playerScore =0;
		players[2].playerScore=0;
		players[1].XposPlayer=500;
		players[1].YposPlayer=500;
		//posision player1 weapon
		YposWeapon1 =300;
		XposWeapon1=300;
		//player2 start pos
		players[2].XposPlayer=600;
		players[2].YposPlayer=200;
		//posision player2 weapon
		YposWeapon2 =400;
		XposWeapon2=200;
		}
	
}


//the math to make sure the player pulls the weapon
void ofApp::pullToPlayer(){
	//------------------------------------------------------------ player1------------------------------//
	//sees when the player1 is to far away
	
		if(ofDist(players[1].XposPlayer,players[1].YposPlayer,XposWeapon1,YposWeapon1)>retreat){
			players[1].bounce ++;
			//give the X and Y posistion of the player2
		for(int i=0; i<players[1].bounce; i++){
			players[1].XLoaction=players[1].XposPlayer;
			players[1].YLoaction=players[1].YposPlayer;
			}
		}
		// if c>0 c/a=x, if c<0 c/b=x  x=position of the player2 can be X or Y
	    //c          a       b   
		Xspeed1 = players[1].XLoaction-XposWeapon1;
		Yspeed1 = players[1].YLoaction-YposWeapon1;
			
		if(Xspeed1<0){
			Weapon1SpeedX =0+Xspeed1/XposWeapon1;
		}else{
			Weapon1SpeedX=Xspeed1/players[1].XLoaction;
		}

		if(Yspeed1<0){
			Weapon1SpeedY =0+Yspeed1/YposWeapon1;
		}else{
			Weapon1SpeedY= Yspeed1/players[1].YLoaction;
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
		if(ofDist(players[2].XposPlayer,players[2].YposPlayer,XposWeapon2,YposWeapon2)>retreat){
			players[2].bounce ++;
			//give the X and Y posistion of the player2
			for(int i=0; i<players[2].bounce; i++){
				players[2].XLoaction=players[2].XposPlayer;
				players[2].YLoaction=players[2].YposPlayer;
			}
  
		}
	    // if c>0 c/a=x, if c<0 c/b=x  x=position of the player can be X or Y
	    //c          a       b   
		Xspeed2 =players[2].XLoaction-XposWeapon2;
		Yspeed2= players[2].YLoaction-YposWeapon2;
			
		if(Xspeed2<0){
			Weapon2SpeedX =Xspeed2/XposWeapon2;
		}else{
			Weapon2SpeedX= Xspeed2/players[2].XLoaction;
		}

		if(Yspeed2<0){
			Weapon2SpeedY =Yspeed2/YposWeapon2;
		}else{
			Weapon2SpeedY= Yspeed2/players[2].YLoaction;
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

//ramon sloos 
// contact ramonsloos@msn.com
// versie 7
//datum: 15-05-2014
// code free to use,  sound contact me!


import ddf.minim.*;


Minim       minim;
AudioPlayer basedrum, snaredrum, highhat, hightom, Crash2, right, lowtom, midtom;
int[] xPosEllipse, xPosSnare, xPosHighHat, xPosHighTom, xPosMidTom, xPosLowTom, xPosCrash, xPosRight, Kross, musicLine;
int aantalMusicLine;
int maxAantalKross;
int maxAantalellipse=20;
int maxAantalSnare=20;
int maxAantalHighHat=50;
int maxAantalHighTom=20;
int maxAantalLowTom=20;
int maxAantalMidTom=20;
int maxAantalCrash=20;
int MaxAantalRight=20;
int aantalEllipsen, aantalSnare, aantalHighHat, aantalHighTom, aantalMidTom, aantalLowTom, aantalCrash, aantalRight;
int start=0;
int ritme=30;


float xpos, ypos, ellipsecount;



void setup () {

  maxAantalKross=10; // verander dit getal om de hulplijnen uit te breiden
  aantalMusicLine=9; // aantal instrumenten
  xPosEllipse= new int[maxAantalellipse];
  xPosSnare=new int[maxAantalSnare];
  xPosHighHat=new int[maxAantalHighHat];
  xPosHighTom=new int[maxAantalHighTom];
  xPosMidTom=new int[maxAantalMidTom];
  xPosLowTom=new int[maxAantalLowTom];
  xPosCrash=new int[maxAantalCrash];
  xPosRight=new int[MaxAantalRight];
  Kross=new int[maxAantalKross];
  musicLine=new int[aantalMusicLine];
  minim = new Minim(this);
  basedrum = minim.loadFile("base.MP3", 2048);
  snaredrum=minim.loadFile("snare.MP3", 2048);
  highhat=minim.loadFile("highhat.MP3", 2048);
  hightom=minim.loadFile("higTom.MP3", 2048);
  Crash2=minim.loadFile("crash2.MP3", 2048);
  right=minim.loadFile("right.MP3", 2048);
  lowtom=minim.loadFile("lowtom.MP3", 2048);
  midtom=minim.loadFile("midtom.MP3", 2048); 




  size(500, 650);
  smooth();
  xpos=0;
  ypos=0;
}


void draw () {
  background(255);
  pushMatrix();
  fill(0, 102, 153, 204);
  textSize(20);
  text("Hulplijnen "+ maxAantalKross, 100, 30);
  textSize(10);
  text("Druk een toets en ga over de rondjes om het geluid te wissen", 100, 45);
  popMatrix();

  //-----------------tracking line---------------------//
  line(xpos, height, ypos, 0);
   int m = millis()-start;
   if (millis() > start+ritme) {  // om de 50mil beweeg line +2
    start = millis();     //start wordt gelijk aan milliseconden waardoor aftrekbaar
  xpos=xpos+2;
  ypos =ypos+2;
   }
  if (xpos > width ) {
    xpos=width/maxAantalKross;
    ypos=width/maxAantalKross;
  }
  //--------------------music lines + text--------------------//
  strokeWeight(2);
 
    for (int y=0; y<musicLine.length;y++) { // horizontale lijnen
      musicLine[y]=y*(height-100)/aantalMusicLine+100;
      line(0, musicLine[y], width, musicLine[y]);
    }
  

  textSize(14);
  text("Basedrum "+ aantalEllipsen, 10, musicLine[1]-10);
  text("Snare "+ aantalSnare, 10, musicLine[2]-10);
  text("HighHat "+ aantalHighHat, 10, musicLine[3]-10);
  text("HighTom "+ aantalHighTom, 10, musicLine[4]-10);
  text("MidTom "+ aantalMidTom, 10, musicLine[5]-10);
  text("LowTom "+ aantalLowTom, 10, musicLine[6]-10);
  text("Crash "+ aantalCrash, 10, musicLine[7]-10);
  text("Right "+ aantalRight, 10, musicLine[8]-10);

 for (int j=0; j<Kross.length;j++) { //vertikale lijnen
    Kross[j]=j*(width/maxAantalKross);
    line(Kross[j], 50, Kross[j], height);
 }
  //-------------------sound triggers-------------------//
  //basedrum
  strokeWeight(1);
  for (int i=0; i<xPosEllipse.length; i++) { 
    ellipse(xPosEllipse[i], musicLine[1], 20, 20);
    if (dist(xpos, musicLine[1], xPosEllipse[i], musicLine[1])<2 && xpos>20) {
      basedrum.play(0);
 
    }else{
      
    }
    if (dist(xPosEllipse[i], musicLine[1], mouseX, mouseY) < 20 && keyPressed) {
      xPosEllipse[i] = 0;
      aantalEllipsen=aantalEllipsen-1;
    }
  }
  //snaredrum
  for (int i=0; i<xPosSnare.length; i++) {

    ellipse(xPosSnare[i], musicLine[2], 20, 20);
    if (dist(xpos, musicLine[2], xPosSnare[i], musicLine[2])<2 && xpos>20) {
      snaredrum.play(0);
    }
    if (dist(xPosSnare[i], musicLine[2], mouseX, mouseY) < 20 && keyPressed) {
      xPosSnare[i] = 0;
      aantalSnare=aantalSnare-1;
    }
  }
  //highhat
  for (int i=0; i<xPosHighHat.length; i++) {

    ellipse(xPosHighHat[i], musicLine[3], 20, 20);
    if (dist(xpos, musicLine[3], xPosHighHat[i], musicLine[3])<2 && xpos>20) {
      highhat.play(0);
    }
    if (dist(xPosHighHat[i], musicLine[3], mouseX, mouseY) < 20 && keyPressed) {
      xPosHighHat[i] = 0;
      aantalHighHat=aantalHighHat-1;
    }
  }
  //hightom
  for (int i=0; i<xPosHighTom.length; i++) {

    ellipse(xPosHighTom[i], musicLine[4], 20, 20);
    if (dist(xpos, musicLine[4], xPosHighTom[i], musicLine[4])<2 && xpos>20) {
      hightom.play(0);
    }
    if (dist(xPosHighTom[i], musicLine[4], mouseX, mouseY) < 20 && keyPressed) {
      xPosHighTom[i] = 0;
      aantalHighTom=aantalHighTom-1;
    }
  }
  //midTom
  for (int i=0; i<xPosMidTom.length; i++) {

    ellipse(xPosMidTom[i], musicLine[5], 20, 20);
    if (dist(xpos, musicLine[5], xPosMidTom[i], musicLine[5])<2 && xpos>20) {
      midtom.play(0);
    }
    if (dist(xPosMidTom[i], musicLine[5], mouseX, mouseY) < 20 && keyPressed) {
      xPosMidTom[i] = 0;
      aantalMidTom=aantalMidTom-1;
    }
  }
  //lowTom
  for (int i=0; i<xPosLowTom.length; i++) {

    ellipse(xPosLowTom[i], musicLine[6], 20, 20);
    if (dist(xpos, musicLine[6], xPosLowTom[i], musicLine[6])<2 && xpos>20) {
      lowtom.play(0);
    }

    if (dist(xPosLowTom[i], musicLine[6], mouseX, mouseY) < 20 && keyPressed) {
      xPosLowTom[i] = 0;
      aantalLowTom=aantalLowTom-1;
    }
  }
  //Crash
  for (int i=0; i<xPosCrash.length; i++) {

    ellipse(xPosCrash[i], musicLine[7], 20, 20);
    if (dist(xpos, musicLine[7], xPosCrash[i], musicLine[7])<2 && xpos>20) {
      Crash2.play(0);
    }

    if (dist(xPosCrash[i], musicLine[7], mouseX, mouseY) < 20 && keyPressed) {
      xPosCrash[i] = 0;
      aantalCrash=aantalCrash-1;
    }
  }
  //Right
  for (int i=0; i<xPosRight.length; i++) {

    ellipse(xPosRight[i], musicLine[8], 20, 20);
    if (dist(xpos, musicLine[8], xPosRight[i], musicLine[8])<2 && xpos>20) {
      right.play(0);
    }

    if (dist(xPosRight[i], musicLine[8], mouseX, mouseY) < 20 && keyPressed) {
      xPosRight[i] = 0;
      aantalRight=aantalRight-1;
    }
  }
 
}


//---------------------------------mouseinput------------------------------------------------//
void mousePressed() {
  //base
  if (aantalEllipsen<19 && dist(mouseX, musicLine[1], mouseX, mouseY)<10 ) {
    xPosEllipse[aantalEllipsen] = mouseX;
    aantalEllipsen += 1;
  } 
  else if (aantalEllipsen>=19) {
    aantalEllipsen=0;
  }
  //snare
  if (aantalSnare<19 && dist(mouseX, musicLine[2], mouseX, mouseY)<10) {
    xPosSnare[aantalSnare] = mouseX;
    aantalSnare += 1;
  } 
  else if (aantalSnare>=19) {
    aantalSnare=0;
  }
  //highhat
  if (aantalHighHat<50 && dist(mouseX, musicLine[3], mouseX, mouseY)<10) {
    xPosHighHat[aantalHighHat] = mouseX;
    aantalHighHat += 1;
  } 

  //hightom
  if (aantalHighTom<19 && dist(mouseX, musicLine[4], mouseX, mouseY)<10) {
    xPosHighTom[aantalHighTom] = mouseX;
    aantalHighTom += 1;
  } 
  else if (aantalHighTom>=19) {
    aantalHighTom=0;
  }
  //Midtom
  if (aantalMidTom<19 && dist(mouseX, musicLine[5], mouseX, mouseY)<10) {
    xPosMidTom[aantalMidTom] = mouseX;
    aantalMidTom += 1;
  } 
  else if (aantalMidTom>=19) {
    aantalMidTom=0;
  }
  //lowtom
  if (aantalLowTom<19 && dist(mouseX, musicLine[6], mouseX, mouseY)<10) {
    xPosLowTom[aantalLowTom] = mouseX;
    aantalLowTom += 1;
  } 
  else if (aantalLowTom>=19) {
    aantalLowTom=0;
  }
  //Crash
  if (aantalCrash<19 && dist(mouseX, musicLine[7], mouseX, mouseY)<10) {
    xPosCrash[aantalCrash] = mouseX;
    aantalCrash += 1;
  } 
  else if (aantalCrash>=19) {
    aantalCrash=0;
  }
  //Right
  if (aantalRight<19 && dist(mouseX, musicLine[8], mouseX, mouseY)<10) {
    xPosRight[aantalRight] = mouseX;
    aantalRight += 1;
  } 
  else if (aantalRight>=19) {
    aantalRight=0;
  }
}


//ramon sloos 
// versie 5
//datum: 14-05-2014



import ddf.minim.*;


Minim       minim;
AudioPlayer basedrum, snaredrum, highhat, hightom, Crash2, right, lowtom, midtom;
int[] xPosEllipse, xPosSnare, xPosHighHat, xPosHighTom, xPosMidTom, xPosLowTom, xPosCrash, xPosRight, Kross;
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


float xpos, ypos, ellipsecount;
int baseline=70;
int snareline=140;
int highhatline=210;
int hightomline=280;
int midtomline=340;
int lowtomline=410;
int crashline=480;
int rightline=540;


void setup () {

  maxAantalKross=10; // verander dit getal om de hulplijnen uit te breiden

  xPosEllipse= new int[maxAantalellipse];
  xPosSnare=new int[maxAantalSnare];
  xPosHighHat=new int[maxAantalHighHat];
  xPosHighTom=new int[maxAantalHighTom];
  xPosMidTom=new int[maxAantalMidTom];
  xPosLowTom=new int[maxAantalLowTom];
  xPosCrash=new int[maxAantalCrash];
  xPosRight=new int[MaxAantalRight];
  Kross=new int[maxAantalKross];
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
  text("Druk een toets en ga over de rondjes om het geluid te wissen",100,45);
  popMatrix();

  //-----------------tracking line---------------------//

  line(xpos, height, ypos, 0);
  xpos=xpos+2;
  ypos = ypos+2;

  if (xpos > width ) {
    xpos=width/maxAantalKross;
    ypos=width/maxAantalKross;
  }
  //--------------------music lines + text--------------------//
  strokeWeight(2);
  for (int j=0; j<Kross.length;j++) {
    Kross[j]=j*(width/maxAantalKross);
    line(Kross[j], 50, Kross[j], height);
  }
  textSize(14);
  text("Basedrum "+ aantalEllipsen, 10, baseline-10);
  line(0, baseline, width, baseline); 
  
  text("Snare "+ aantalSnare, 10, snareline-10);
  line(0, snareline, width, snareline); 
  
  text("HighHat "+ aantalHighHat, 10, highhatline-10);
  line(0, highhatline, width, highhatline); 
  
  text("HighTom "+ aantalHighTom, 10, hightomline-10);
  line(0, hightomline, width, hightomline); 
  
  text("MidTom "+ aantalMidTom, 10, midtomline-10);
  line(0, midtomline, width, midtomline); 
  
  text("LowTom "+ aantalLowTom, 10, lowtomline-10);
  line(0, lowtomline, width, lowtomline); 
  
  text("Crash "+ aantalCrash, 10, crashline-10);
  line(0, crashline, width, crashline); 
  
  text("Right "+ aantalRight, 10, rightline-10);
  line(0, rightline, width, rightline); 

  //-------------------sound triggers-------------------//
  //basedrum
 strokeWeight(1);
  for (int i=0; i<xPosEllipse.length; i++) { 
    ellipse(xPosEllipse[i], baseline, 20, 20);
    if (dist(xpos, baseline, xPosEllipse[i], baseline)<2 && xpos>20) {
      basedrum.play(0);
    }
    if (dist(xPosEllipse[i], baseline, mouseX, mouseY) < 20 && keyPressed) {
      xPosEllipse[i] = 0;
      aantalEllipsen=aantalEllipsen-1;
    }
  }
  //snaredrum
  for (int i=0; i<xPosSnare.length; i++) {

    ellipse(xPosSnare[i], snareline, 20, 20);
    if (dist(xpos, snareline, xPosSnare[i], snareline)<2 && xpos>20) {
      snaredrum.play(0);
    }
    if (dist(xPosSnare[i], snareline, mouseX, mouseY) < 20 && keyPressed) {
      xPosSnare[i] = 0;
      aantalSnare=aantalSnare-1;
    }
  }
  //highhat
  for (int i=0; i<xPosHighHat.length; i++) {

    ellipse(xPosHighHat[i], highhatline, 20, 20);
    if (dist(xpos, highhatline, xPosHighHat[i], highhatline)<2 && xpos>20) {
      highhat.play(0);
    }
    if (dist(xPosHighHat[i], highhatline, mouseX, mouseY) < 20 && keyPressed) {
      xPosHighHat[i] = 0;
      aantalHighHat=aantalHighHat-1;
    }
  }
  //hightom
  for (int i=0; i<xPosHighTom.length; i++) {

    ellipse(xPosHighTom[i], hightomline, 20, 20);
    if (dist(xpos, hightomline, xPosHighTom[i], hightomline)<2 && xpos>20) {
      hightom.play(0);
    }
    if (dist(xPosHighTom[i], hightomline, mouseX, mouseY) < 20 && keyPressed) {
      xPosHighTom[i] = 0;
      aantalHighTom=aantalHighTom-1;
    }
  }
  //midTom
  for (int i=0; i<xPosMidTom.length; i++) {

    ellipse(xPosMidTom[i], midtomline, 20, 20);
    if (dist(xpos, midtomline, xPosMidTom[i], midtomline)<2 && xpos>20) {
      midtom.play(0);
    }
    if (dist(xPosMidTom[i], midtomline, mouseX, mouseY) < 20 && keyPressed) {
      xPosMidTom[i] = 0;
      aantalMidTom=aantalMidTom-1;
    }
  }
  //lowTom
  for (int i=0; i<xPosLowTom.length; i++) {

    ellipse(xPosLowTom[i], lowtomline, 20, 20);
    if (dist(xpos, lowtomline, xPosLowTom[i], lowtomline)<2 && xpos>20) {
      lowtom.play(0);
      
    }

    if (dist(xPosLowTom[i],lowtomline,mouseX,mouseY) < 20 && keyPressed) {
      xPosLowTom[i] = 0;
      aantalLowTom=aantalLowTom-1;
    }
  }
  //Crash
  for (int i=0; i<xPosCrash.length; i++) {

    ellipse(xPosCrash[i], crashline, 20, 20);
    if (dist(xpos, crashline, xPosCrash[i], crashline)<2 && xpos>20) {
      Crash2.play(0);
    }

    if (dist(xPosCrash[i],crashline,mouseX,mouseY) < 20 && keyPressed) {
      xPosCrash[i] = 0;
      aantalCrash=aantalCrash-1;
    }
  }
    //Right
  for (int i=0; i<xPosRight.length; i++) {

    ellipse(xPosRight[i], rightline, 20, 20);
    if (dist(xpos, rightline, xPosRight[i], rightline)<2 && xpos>20) {
      right.play(0);
    }

    if (dist(xPosRight[i],rightline,mouseX,mouseY) < 20 && keyPressed) {
      xPosRight[i] = 0;
      aantalRight=aantalRight-1;
    }
  }
}


//---------------------------------mouseinput------------------------------------------------//
void mousePressed() {
  //base
  if (aantalEllipsen<19 && dist(mouseX, baseline, mouseX, mouseY)<10 ) {
    xPosEllipse[aantalEllipsen] = mouseX;
    aantalEllipsen += 1;
  } 
  else if (aantalEllipsen>=19) {
    aantalEllipsen=0;
  }
  //snare
  if (aantalSnare<19 && dist(mouseX, snareline, mouseX, mouseY)<10) {
    xPosSnare[aantalSnare] = mouseX;
    aantalSnare += 1;
  } 
  else if (aantalSnare>=19) {
    aantalSnare=0;
  }
  //highhat
  if (aantalHighHat<50 && dist(mouseX, highhatline, mouseX, mouseY)<10) {
    xPosHighHat[aantalHighHat] = mouseX;
    aantalHighHat += 1;
  } 

  //hightom
  if (aantalHighTom<19 && dist(mouseX, hightomline, mouseX, mouseY)<10) {
    xPosHighTom[aantalHighTom] = mouseX;
    aantalHighTom += 1;
  } 
  else if (aantalHighTom>=19) {
    aantalHighTom=0;
  }
  //Midtom
  if (aantalMidTom<19 && dist(mouseX, midtomline, mouseX, mouseY)<10) {
    xPosMidTom[aantalMidTom] = mouseX;
    aantalMidTom += 1;
  } 
  else if (aantalMidTom>=19) {
    aantalMidTom=0;
  }
  //lowtom
  if (aantalLowTom<19 && dist(mouseX, lowtomline, mouseX, mouseY)<10) {
    xPosLowTom[aantalLowTom] = mouseX;
    aantalLowTom += 1;
  } 
  else if (aantalLowTom>=19) {
    aantalLowTom=0;
  }
  //Crash
  if (aantalCrash<19 && dist(mouseX, crashline, mouseX, mouseY)<10) {
    xPosCrash[aantalCrash] = mouseX;
    aantalCrash += 1;
  } 
  else if (aantalCrash>=19) {
    aantalCrash=0;
  }
   //Right
  if (aantalRight<19 && dist(mouseX, rightline, mouseX, mouseY)<10) {
    xPosRight[aantalRight] = mouseX;
    aantalRight += 1;
  } 
  else if (aantalRight>=19) {
    aantalRight=0;
  }
  
}


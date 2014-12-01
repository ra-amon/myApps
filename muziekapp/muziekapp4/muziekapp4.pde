//ramon sloos 
// versie 1



import ddf.minim.*;


Minim       minim;
AudioPlayer basedrum, snaredrum, highhat, hightom, Crash2, right, lowtom, midtom;
int[] xPosEllipse, xPosSnare, xPosHighHat, xPosHighTom, xPosMidTom, xPosLowTom, xPosCrash, xPosRight,Kross;
int maxAantalKross=20;
int maxAantalellipse=20;
int maxAantalSnare=20;
int maxAantalHighHat=20;
int maxAantalHighTom=20;
int maxAantalLowTom=20;
int maxAantalMidTom=20;
int maxAantalCrash=3;
int MaxAantalRight=20;
int aantalEllipsen, aantalSnare, aantalHighHat, aantalHighTom, aantalMidTom, aantalLowTom, aantaCrash, aantalRight,aantalKross;


float xpos, ypos, ellipsecount;
int baseline=100;
int snareline=200;
int highhatline=300;
int hightomline=400;
int midtomline=500;
int lowtomline=600;
int crashline=700;
int rightline=800;


void setup () {
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




  size(1000, 810);
  smooth();
  xpos=0;
  ypos=0;
}


void draw () {
  background(255);
  //-----------------tracking line---------------------//
  line(xpos, height, ypos, 0);
  xpos=xpos+2;
  ypos = ypos+2;
  if (xpos == width ) {
    xpos=0;
    ypos=0;
  }
  //--------------------music lines--------------------//
   for (int j=0; j<Kross.length;j++) {
     Kross[j]=j*50;
    line(Kross[j],0,Kross[j], height);
   }
  line(0, baseline, width, baseline); 
  line(0, snareline, width, snareline); 
  line(0, highhatline, width, highhatline); 
  line(0, hightomline, width, hightomline); 
  line(0, midtomline, width, midtomline); 
  line(0, lowtomline, width, lowtomline); 
  line(0, crashline, width, crashline); 
  line(0, rightline, width, rightline); 

  //-------------------sound triggers-------------------//
  //basedrum

    
  for (int i=0; i<xPosEllipse.length; i++) {  
    ellipse(xPosEllipse[i], baseline, 20, 20);
    if (dist(xpos, baseline, xPosEllipse[i], baseline)<2 && xpos>20) {
      basedrum.play();
      basedrum.play(0);
    }
    if (abs(xPosEllipse[i]-mouseX) < 20 && keyPressed) {
      xPosEllipse[i] = 0;
    }
  }
  //snaredrum
  for (int i=0; i<xPosSnare.length; i++) {

    ellipse(xPosSnare[i], snareline, 20, 20);
    if (dist(xpos, snareline, xPosSnare[i], snareline)<2 && xpos>20) {
      snaredrum.play();
      snaredrum.play(0);
    }
    if (abs(xPosSnare[i]-mouseX) < 20 && keyPressed) {
      xPosSnare[i] = 0;
    }
  }
  //highhat
  for (int i=0; i<xPosHighHat.length; i++) {

    ellipse(xPosHighHat[i], highhatline, 20, 20);
    if (dist(xpos, highhatline, xPosHighHat[i], highhatline)<2 && xpos>20) {
      highhat.play();
      highhat.play(0);
    }
    if (abs(xPosHighHat[i]-mouseX) < 20 && keyPressed) {
      xPosHighHat[i] = 0;
    }
  }
  //hightom
  for (int i=0; i<xPosHighTom.length; i++) {

    ellipse(xPosHighTom[i], hightomline, 20, 20);
    if (dist(xpos, hightomline, xPosHighTom[i], hightomline)<2 && xpos>20) {
      hightom.play();
      hightom.play(0);
    }
    if (abs(xPosHighTom[i]-mouseX) < 20 && keyPressed) {
      xPosHighTom[i] = 0;
    }
  }
    //midTom
  for (int i=0; i<xPosMidTom.length; i++) {

    ellipse(xPosMidTom[i], midtomline, 20, 20);
    if (dist(xpos, midtomline, xPosMidTom[i], midtomline)<2 && xpos>20) {
      midtom.play();
      midtom.play(0);
    }
    if (abs(xPosMidTom[i]-mouseX) < 20 && keyPressed) {
      xPosMidTom[i] = 0;
    }
  }
      //lowTom
  for (int i=0; i<xPosLowTom.length; i++) {

    ellipse(xPosLowTom[i], lowtomline, 20, 30);
    if (dist(xpos, lowtomline, xPosLowTom[i], lowtomline)<2 && xpos>20) {
     
      lowtom.play(0);
    }
    
    if (abs(xPosLowTom[i]-mouseX) < 20 && keyPressed) {
      xPosLowTom[i] = 0;
    }
  }
   
}


//---------------------------------mouseinput------------------------------------------------//
void mousePressed() {
  //base
  if (aantalEllipsen<19 && dist(mouseX, baseline, mouseX, mouseY)<10 ){
    xPosEllipse[aantalEllipsen] = mouseX;
    aantalEllipsen += 1;
  } 
  else {
    aantalEllipsen=0;
  }
  //snare
  if (aantalSnare<19 && dist(mouseX, snareline, mouseX, mouseY)<10) {
    xPosSnare[aantalSnare] = mouseX;
    aantalSnare += 1;
  } 
  else {
    aantalSnare=0;
  }
  //highhat
  if (aantalHighHat<19 && dist(mouseX, highhatline, mouseX, mouseY)<10) {
    xPosHighHat[aantalHighHat] = mouseX;
    aantalHighHat += 1;
  } 
  else {
    aantalHighHat=0;
  }
  //hightom
  if (aantalHighTom<19 && dist(mouseX, hightomline, mouseX, mouseY)<10) {
    xPosHighTom[aantalHighTom] = mouseX;
    aantalHighTom += 1;
  } 
  else {
    aantalHighTom=0;
  }
    //Midtom
  if (aantalMidTom<19 && dist(mouseX, midtomline, mouseX, mouseY)<10) {
    xPosMidTom[aantalMidTom] = mouseX;
    aantalMidTom += 1;
  } 
  else {
    aantalMidTom=0;
  }
      //lowtom
  if (aantalLowTom<19 && dist(mouseX, lowtomline, mouseX, mouseY)<10) {
    xPosLowTom[aantalLowTom] = mouseX;
    aantalLowTom += 1;
  } 
  else {
    aantalLowTom=0;
  }
}


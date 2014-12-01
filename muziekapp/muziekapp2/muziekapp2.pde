//ramon sloos 
// versie 1



import ddf.minim.*;


Minim       minim;
AudioPlayer basedrum, snaredrum, Hihat, hightom, Crash2, right,lowtom,midtom;
int[] xPosEllipse;
int maxAantalellipse=10;
int aantalEllipsen;

boolean  snair, hihat, highTom, crash2, Right,lowTom,midTom=false;
float xpos, ypos, ellipsecount;
int baseline=100;
float mousePosX;
void setup () {
  xPosEllipse= new int[maxAantalellipse];
  minim = new Minim(this);
  basedrum = minim.loadFile("base.MP3", 2048);
  snaredrum=minim.loadFile("snare.MP3", 2048);
  Hihat=minim.loadFile("highhat.MP3", 2048);
  hightom=minim.loadFile("higTom.MP3", 2048);
  Crash2=minim.loadFile("crash2.MP3", 2048);
  right=minim.loadFile("right.MP3", 2048);
  lowtom=minim.loadFile("lowtom.MP3",2048);
  midtom=minim.loadFile("midtom.MP3",2048); 


   
  
 size(1000,800);
 smooth();
  xpos=0;
  ypos=0;
  baseline=100;
}


void draw () {
 background(255);
 //--------------------------------------//
 line(xpos, height, ypos, 0);
  xpos=xpos+2;
  ypos = ypos+2;
  if (xpos == width ) {
    xpos=0;
    ypos=0;
  }
  //----------------------------------------//
   line(0, baseline, width, baseline); //exact op de line :)
  
  
  //--------------------------------------//
  for(int i=0; i<xPosEllipse.length; i++){
    ellipse(xPosEllipse[i], baseline, 20, 20);
    if(dist(xpos,baseline,xPosEllipse[i],baseline)<2){
      basedrum.play();
      basedrum.play(0);
    }
  }
}

void mousePressed(){
  if(aantalEllipsen<9 && dist(mouseX,baseline,mouseX,mouseY)<10){

  xPosEllipse[aantalEllipsen] = mouseX;
  println(xPosEllipse[aantalEllipsen]);
  aantalEllipsen += 1;
  }else{
    aantalEllipsen=0;
  }
}

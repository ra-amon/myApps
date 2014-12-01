//ramon sloos 
// versie 1



import ddf.minim.*;


Minim       minim;
AudioPlayer basedrum, snaredrum, highhat, hightom, Crash2, right,lowtom,midtom;
int[] xPosEllipse,xPosSnare,xPosHighHat;
int maxAantalellipse=20;
int maxAantalSnare=20;
int maxAantalHighHat=20;
int aantalEllipsen,aantalSnare,aantalHighHat;

boolean  snair, hihat, highTom, crash2, Right,lowTom,midTom=false;
float xpos, ypos, ellipsecount;
int baseline=100;
int snareline=200;
int highhatline=300;
float mousePosX;
void setup () {
  xPosEllipse= new int[maxAantalellipse];
  xPosSnare=new int[maxAantalSnare];
  xPosHighHat=new int[maxAantalHighHat];
  minim = new Minim(this);
  basedrum = minim.loadFile("base.MP3", 2048);
  snaredrum=minim.loadFile("snare.MP3", 2048);
  highhat=minim.loadFile("highhat.MP3", 2048);
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
 //-----------------tracking line---------------------//
 line(xpos, height, ypos, 0);
  xpos=xpos+2;
  ypos = ypos+2;
  if (xpos == width ) {
    xpos=0;
    ypos=0;
  }
  //--------------------music lines--------------------//
  for(int i=0; i<width;i=i+50){
   line(i,0,i,height); 
  }
  
  
  
   line(0, baseline, width, baseline); //exact op de line :)
   line(0, snareline, width, snareline); //exact op de line :)
   line(0, highhatline, width, highhatline); //exact op de line :)
  
  //-------------------sound triggers-------------------//
  for(int i=0; i<xPosEllipse.length; i++){
    ellipse(xPosEllipse[i], baseline, 20, 20);
    if(dist(xpos,baseline,xPosEllipse[i],baseline)<2 && xpos>20){
      basedrum.play();
      basedrum.play(0);
        
    }
    
  }
  for(int i=0; i<xPosSnare.length; i++){
 
    ellipse(xPosSnare[i],snareline,20,20);
     if(dist(xpos,snareline,xPosSnare[i],snareline)<2 && xpos>20){
      snaredrum.play();
      snaredrum.play(0);
    }
  }
  for(int i=0; i<xPosHighHat.length; i++){
 
    ellipse(xPosHighHat[i],highhatline,20,20);
     if(dist(xpos,highhatline,xPosHighHat[i],highhatline)<2 && xpos>20){
      highhat.play();
      highhat.play(0);
    }
  }
}

void mousePressed(){
  if(aantalEllipsen<19 && dist(mouseX,baseline,mouseX,mouseY)<10){
  xPosEllipse[aantalEllipsen] = mouseX;
  aantalEllipsen += 1;
  } else{
    aantalEllipsen=0;
  }
   if(aantalSnare<19 && dist(mouseX,snareline,mouseX,mouseY)<10){
  xPosSnare[aantalSnare] = mouseX;
  aantalSnare += 1;
  } else{
    aantalSnare=0;
  }
   if(aantalHighHat<19 && dist(mouseX,highhatline,mouseX,mouseY)<10){
  xPosHighHat[aantalHighHat] = mouseX;
  aantalHighHat += 1;
  } else{
    aantalHighHat=0;
  }
}


void keyPressed(){
  
  if(key=='b'){
    aantalEllipsen=0;
  }
}

/* version 1.0
    by ramon sloos
    Email. ramonsloos@msn.com
    name: drumkit
    date: 08-05-2014 */



import ddf.minim.*;


Minim       minim;
AudioPlayer basedrum, snaredrum, Hihat, hightom, Crash2, right,lowtom,midtom;
boolean base, snair, hihat, highTom, crash2, Right,lowTom,midTom=false;
float ex= 250;
float rij1pos=125;         // y positie rij 1
float rij2pos = 375;       // y positie rij 2


void setup() {
  minim = new Minim(this);
  basedrum = minim.loadFile("base.MP3", 2048);
  snaredrum=minim.loadFile("snare.MP3", 2048);
  Hihat=minim.loadFile("highhat.MP3", 2048);
  hightom=minim.loadFile("higTom.MP3", 2048);
  Crash2=minim.loadFile("crash2.MP3", 2048);
  right=minim.loadFile("right.MP3", 2048);
  lowtom=minim.loadFile("lowtom.MP3",2048);
  midtom=minim.loadFile("midtom.MP3",2048);


  size(1000, 500);
  smooth();
}

void draw() {

  fill(0, 0, 255);
  if (dist(mouseX, mouseY, 125, rij1pos) < ex/2) {
    base=true;
  }
  else {
    base=false;
  }
  ellipseMode(CENTER);
  ellipse(125, rij1pos, ex, ex);

  //-------------------------------------------------------------------------//

  if (dist(mouseX, mouseY, 375, rij1pos) < ex/2) {
    snair=true;
  }
  else {
    snair=false;
  }
  ellipse(375, rij1pos, ex, ex);

  //-----------------------------------------------------------------//

  if (dist(mouseX, mouseY, 625, rij1pos) < ex/2) {
    hihat=true;
  }
  else {
    hihat=false;
  }
  ellipse(625, rij1pos, ex, ex);
  //--------------------------------------------------------------/
  if (dist(mouseX, mouseY, 875, rij1pos) < ex/2) {
    crash2=true;
  }
  else {
    crash2=false;
  }
  ellipse(875, rij1pos, ex, ex);
  //------------------------------------------------------------------//
  if (dist(mouseX, mouseY, 125, rij2pos) < ex/2) {
    highTom =true;
  }
  else {
    highTom=false;
  }
  ellipse(125, rij2pos, ex, ex);
  //----------------------------------------------------------------------//
 if (dist(mouseX, mouseY, 375, rij2pos) < ex/2) {
   midTom =true;
  }
  else {
    midTom=false;
  }
  ellipse(375, rij2pos, ex, ex);
  //-------------------------------------------------------------//
   if (dist(mouseX, mouseY, 625, rij2pos) < ex/2) {
    lowTom =true;
  }
  else {
    lowTom=false;
  }
  ellipse(625, rij2pos, ex, ex);
  //-----------------------------------------------------------------//
  if (dist(mouseX, mouseY, 875, rij2pos) < ex/2) {
    Right =true;
  }
  else {
    Right=false;
  }
  ellipse(875, rij2pos, ex, ex);
}

void mousePressed() {
  if (base) {
    basedrum.play();
    basedrum.play(0);
  }
  if (snair) {
    snaredrum.play();
    snaredrum.play(0);
  }
  if (hihat) {
    Hihat.play();
    Hihat.play(0);
  }
  if (crash2) {
    Crash2.play();
    Crash2.play(0);
  }
  if (highTom) {
    hightom.play();
    hightom.play(0);
  }
   if (midTom) {
    midtom.play();
    midtom.play(0);
  }
   if (lowTom) {
    lowtom.play();
    lowtom.play(0);
  }
  if (Right) {
    right.play();
    right.play(0);
  }
}
void keyPressed() {
  if (key=='q') {
    basedrum.play();
    basedrum.play(0);
  }
  if (key=='w') {
    snaredrum.play();
    snaredrum.play(0);
  }
  if (key=='e') {
    Hihat.play();
    Hihat.play(0);
  }
  if (key=='r') {
    Crash2.play();
    Crash2.play(0);
  }
  if (key=='a') {
    hightom.play();
    hightom.play(0);
  }
   if (key=='s') {
    midtom.play();
    midtom.play(0);
  }
   if (key=='d') {
    lowtom.play();
    lowtom.play(0);
  }
  if (key=='f') {
    right.play();
    right.play(0);
  }
}
void stop()
{
  basedrum.close();

  super.stop();
}


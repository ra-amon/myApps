#include "ofApp.h"
#define NUMBER_OF_KEYS 10


//--------------------------------------------------------------
void ofApp::setup(){
	//makes audio go out of openframeworks
	//ofSoundStreamSetup(2,0,this,44100,256,4);

	////these will be the nods and we name them.
	//ControlGenerator midiNote= 
	//	synth.addParameter("midiNumber");
	////convert a midi note to a frequincy
	//ControlGenerator noteFreq = ControlMidiToFreq().input(midiNote);
	//
	//Generator tone = SawtoothWave().freq(noteFreq);
	////create a tone
	//tone= LPF12().input(tone).Q(2).cutoff((noteFreq*2) +SineWave().freq(3) *0.5* noteFreq);

	////trigger
	//ControlGenerator envelopeTrigger = synth.addParameter("trigger");
	//Generator toneWithEnvelope =  tone * ADSR().attack(0.01).decay(1.5).sustain(0).release(0).trigger(envelopeTrigger).legato(true);

	//Generator toneWithDelay= StereoDelay(0.5,.7).input(toneWithEnvelope).wetLevel(0.1).feedback(0.2);
	//synth.setOutputGen(toneWithDelay);

	//arduino bit
	ard.connect("COM4", 57600);
	ofAddListener(ard.EInitialized, this, &ofApp::setupArd);
	
}

void ofApp::trigger(){
	static int twoOctavePentatonicScale[10] = {0,2,4,7,9,12,14,16,19,21};
	int degreeToTrigger = floor(ofClamp(scaleDegree,0,9));

	//set a parameter that we created when we difned the synth
	synth.setParameter("midiNumber", 44 + twoOctavePentatonicScale[degreeToTrigger]);
	//simply setting the value of a parameter cause that parameters to send a "trigger" any
	//using them as trigger
	synth.setParameter("trigger", 1);
}
//setup the arduino
void ofApp::setupArd(const int &version){
	
	ofRemoveListener(ard.EInitialized, this, &ofApp::setupArd);
	ard.sendAnalogPinReporting(0, ARD_ANALOG);
	ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
	cout << "fired" << endl;
	
	
}
//--------------------------------------------------------------
void ofApp::update(){
	ard.update();
	
}

void ofApp::analogPinChanged(const int &pinNum){

	float value= ard.getAnalog(pinNum);
	trigger();
	int newScaleDegree = value * NUMBER_OF_KEYS / ofGetWindowWidth();
	scaleDegree = newScaleDegree;
	trigger();
		

}

void ofApp::audioRequested(float * output, int bufferSize, int nChannels){
	synth.fillBufferOfFloats(output, bufferSize, nChannels);
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
		
	int newScaleDegree = 600 * NUMBER_OF_KEYS / ofGetWindowWidth();
	scaleDegree = newScaleDegree;
	trigger();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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

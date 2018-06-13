#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	string s1="loopMI";
	for (int i = 0; i < midiOut.getNumPorts(); i++) {
		string s(midiOut.getPortName(i));
		if (s.compare(0, 6, s1) == 0) {
			midiOut.openPort(i);
			cout << "Connected to " << s << ". Sending melodies to channel 1 and arpeggios to Channel 2\n";
	
			break;
		}
	}

	tangle = TWO_PI / 15.f;
	ofSetFrameRate(1000);
}

//--------------------------------------------------------------
void ofApp::update(){
	/*for (int i = 0; i < 10000000; i++)
		;*/
	/*timeU = ofGetSystemTime();*/
	//cout << timeU  << '\t';
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	for (int i = 0; i < 15; i++) {

		ofSetColor(i * 15, i * 10, i * 10);

		ofBeginShape();
		ofVertex(ofGetWidth() / 2, ofGetHeight() / 2);
		
		for (float c = 0; c <= 1.0f; c += 0.2f) {
			ofVertex(ofGetWidth() / 2 - cos((i+c)*tangle)*ofGetHeight() / 2, ofGetHeight() / 2 + sin((i+c)*tangle)*ofGetHeight() / 2);

		}
		
		ofVertex(ofGetWidth() / 2 - cos((i+1)*tangle)*ofGetHeight() / 2, ofGetHeight() / 2 + sin((i+1) * tangle)*ofGetHeight() / 2);
		ofEndShape(TRUE);

	}

	ofSetColor(255);
	ofCircle(mouse, 5);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

	mouse.x = x;
	mouse.y = y;

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	float angle = atan2(-y + ofGetHeight()/2, x - ofGetWidth()/2) + TWO_PI / 2;
	
	int midiNote = 60+ (int)floor(angle / TWO_PI * 15) % 15; //integer: note;
	midiOut.sendNoteOn(1, midiNote, 100);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	float angle = atan2(-y + ofGetHeight() / 2, x - ofGetWidth() / 2) + TWO_PI / 2;

	int midiNote = 60 + (int)floor(angle / TWO_PI * 15) % 15; //integer: note;
	midiOut.sendNoteOff(1, midiNote, 0);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

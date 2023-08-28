#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofColor color, line_color;
	for (int i = 0; i < 1200; i++) {

		auto x = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.0025), 0, 1, -320, 320);
		auto y = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.0025), 0, 1, -320, 320);
		auto size = ofRandom(5, 20);
		
		auto hue = ofRandom(180, 230);
		color.setHsb(hue, 255,  ofMap(i, 0, 1200, 0, 255));
		line_color.setHsb(hue, ofMap(i, 0, 1200, 255, 0), 255);

		ofFill();
		ofSetColor(color);
		ofDrawCircle(glm::vec2(x, y), size);

		ofNoFill();
		ofSetColor(line_color);
		ofDrawCircle(glm::vec2(x, y), size);
	}
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
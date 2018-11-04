#include "ofApp.h"

void ofApp::osc208() {
	bang = 0;
	while (receiver.hasWaitingMessages()) {

		ofxOscMessage m;
		receiver.getNextMessage(&m);

		for (int i = 0; i < m.getNumArgs(); i++) {
			if (m.getArgType(i) == OFXOSC_TYPE_FLOAT) {
				bang = m.getArgAsFloat(0);
			}
		}
	}

	if (mbangsw == 1) {
		bang = 1;
	}

	if (abb == 1) {
		abbco += 1;
		if (abbco > 300) {
			abb = 0; abbco = 0;
		}
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
	// tag receiver setting and initialize the signal.
	receiver.setup(PORT);
	abb = 0;
	bang = 0;
	// hide cursor.
	ofHideCursor();

	for (int i = 0; i <= 9; i++) {
		number[i].load("img/" + to_string(i) + ".png");
		number[i].resize(275, 370);
	}
	// setup background
	background_bottom.load("img/background_bottom.png");
	tag_image.load("img/video_bg.jpg");
	
	// setup videos
	interview_video.load("video/interview.mp4");
	interview_video.setLoopState(OF_LOOP_NORMAL);
	tag_video.load("video/tag.mp4");
	tag_video.setLoopState(OF_LOOP_NONE);

	// open log file and counting.
	ifstream is;
	is.open(ofToDataPath("tag_counter.txt").c_str());
	string str;
	getline(is, str);
	tag_counter = atoi(str.c_str());
	std::cout << tag_counter;
	is.close();
}

//--------------------------------------------------------------
void ofApp::update(){
	osc208();
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);
	if (bang != 0 && abb == 0) {
		abb = 1;
		// Log the check-time in the ~/bin/data/log.txt
		time(&rawTime);
		logFile.open("log.txt", ofFile::Append);
		logFile << ctime(&rawTime);
		logFile.close();

		tag_counter++;
		ofstream of;
		of.open(ofToDataPath("tag_counter.txt").c_str());
		of << tag_counter;
		of.close();
	}
	if (abbco > 0) {
		interview_video.setVolume(0.0f);
	} else {
		interview_video.setVolume(1.0f);
	}
	//Decrease video volume from 20:00 to 08:00
	if (curr_tm->tm_hour >= 20 || curr_tm->tm_hour < 8)
		interview_video.setVolume(0.3f);
	tag_video.update();
	interview_video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetHexColor(0xffffff);
	ofRotateZ(-90);
	ofTranslate(-1080 + tx, 0 + ty, 0);
	interview_video.play();
	interview_video.draw(0, 0, 1080, 1920);
	if (abbco > 0) {
		tag_video.play();
		tag_image.draw(0, 1920);
		tag_video.draw((1080 - VIDEO_W) / 2, 1920 + (1920 - VIDEO_H) / 2, VIDEO_W, VIDEO_H);
	}
	else {
		background_bottom.draw(0, 1920);
		number[tag_counter % 10].draw(700, 1920 + 1220);
		if (tag_counter >= 10) {
			number[(tag_counter / 10) % 10].draw(405, 1920 + 1220);
		}
		if (tag_counter >= 100) {
			number[(tag_counter / 100) % 10].draw(117, 1920 + 1220);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_UP) {
		tx += 40;
	}
	if (key == OF_KEY_DOWN) {
		tx -= (40);
	}
	if (key == OF_KEY_RIGHT) {
		ty += 40;
	}
	if (key == OF_KEY_LEFT) {
		ty -= 40;
	}
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
	mbangsw = 1;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	mbangsw = 0;
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

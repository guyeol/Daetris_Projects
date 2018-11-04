#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofVideoPlayer.h"
#include <iostream>
#include <fstream>
#define PORT    5001

const int VIDEO_W = 800;
const int VIDEO_H = 1000;

class ofApp : public ofBaseApp {

public:
	/* Tag signal
	*/
	float bang;
	int mbangsw;
	int abb;
	int abbco;
	int completeCounter = -1;
	int tx = 0;
	int ty = 0;

	// Tag count
	int tag_counter;

	// Log file.
	ofFile logFile;

	// interviw video.
	ofVideoPlayer interview_video;

	// background_bottom image
	ofImage background_bottom;

	// tag video & image
	ofVideoPlayer tag_video;
	ofImage tag_image;

	ofxOscReceiver receiver;

	time_t rawTime;
	time_t curr_time;
	struct tm *curr_tm;

	ofImage number[10];

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void osc208();

};

#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#define PORT 5001

class ofApp : public ofBaseApp{

	public:
        int count;  // the number of donations
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void osc208();
    
        ofFile myTextFile;  // log file

        ofxOscReceiver receiver;
        float bang;
        int mbangsw;
        int abb;
        int abbco;
        int t;
        int frame_r = 0;
        int completeCounter = -1;
        bool word_writing = false;
        int c_endIndex = -1;
        int c_index = 0;
        void writingWord();
        bool test=false;
    
        ofEasyCam cam;

        ofImage background_up;
        ofImage background_down;

};

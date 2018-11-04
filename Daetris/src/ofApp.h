#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "CntNum.hpp"

#define PORT 5001

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void osc208();
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
		
        ofxOscReceiver receiver;
        ofEasyCam cam;
        ofImage bgTop;
        ofImage bgBottom;
        ofImage cnt_margin;
        ofFile mTxtFile;
        ofSoundPlayer bgm, success;
        CntNum mCntNum;
        ofVideoPlayer video;
        float bang;
        int mbangsw;
        int x = -1500, y = 500, z=1000;
        int t;
        bool isAvailable;
        int margin;
        int delayCounter;
        time_t rawTime;
        time_t curr_time;
        struct tm *curr_tm;
};

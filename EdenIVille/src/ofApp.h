#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "TagCount.hpp"
#include "Items.hpp"
#include "GiftBox.hpp"

class ofApp : public ofBaseApp{

	public:
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
    
    ofxOscReceiver receiver;
    ofEasyCam cam;
    ofImage bgTop;
    ofImage bgBottom;
    ofImage bgTagBoy;
    ofImage bgTagGirl;
    ofImage bgTagTop;
    ofImage curBgBottom;
    ofImage curBgTop;
    
    ofSoundPlayer bgm, success;
    ofFile mTxtFile;
    
    TagCount tagCount;
    Items mItem;
    GiftBox giftBox;
    
    int x = -1500, y = 500, z=1000;
    float bang;
    int mbangsw;
    int delaytime = 270;
    bool isAvailable;
    int delayCounter;
    time_t rawTime;
    time_t curr_time;
    struct tm *curr_tm;
    
};

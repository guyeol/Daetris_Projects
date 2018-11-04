#include "ofApp.h"
#include <ctime>

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
        margin = 60;

    }
    
    
    if (!isAvailable) {
        delayCounter += 1;
        if (delayCounter > 200) {
            isAvailable = true; delayCounter = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    cam = ofEasyCam();
    
    receiver.setup(PORT);
    bang = 0;
    ofHideCursor();
    mCntNum.setup();
    
    bgTop.load("images/bg_top.png");
    bgBottom.load("images/bg_bottom.png");
    cnt_margin.load("images/cnt_margin.png");
    video.load("images/bg_top.mp4");
    
    bgm.load("sounds/back.mp3");
    success.load("sounds/success.mp3");

    bgm.setLoop(true);
    bgm.play();
    isAvailable = true;
    margin = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    osc208();
    curr_time = time(NULL);
    curr_tm = localtime(&curr_time);
    
    if (bang != 0 && isAvailable) {
        success.play();
        isAvailable = false;
        // Log the check-time in the ~/bin/data/log.txt
        time(&rawTime);
        mTxtFile.open("log.txt", ofFile::Append);
        mTxtFile << ctime(&rawTime);
        mTxtFile.close();
        mCntNum.countUp();
    }
    if (curr_tm -> tm_hour >= 18 || curr_tm -> tm_hour < 8)
        bgm.setVolume(0.0f);
    else
        bgm.setVolume(0.3f);
    
    video.update();
    mCntNum.update();
    if(margin > 0)
        margin--;
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    cam.setPosition(ofVec3f(x, y, z));  // x, y, z (240,1920,4000)
    ofRotateZ(90);
    //bgTop.draw(0, 1920, 1080, 1920);
    bgBottom.draw(0, 0, 1080, 1920);
    video.draw(0, 1920, 1080, 1920);
    video.play();
    mCntNum.draw();
    if(margin % 10 >= 5)
        cnt_margin.draw(50, 1965, 378, 188);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 119) {
        y++;
    }
    else if (key == 97) {
        x--;
    }
    else if (key == 115) {
        y--;
    }
    else if (key == 100) {
        x++;
    }
    else if (key == 113) {
        z--;
    }
    else if (key == 101) {
        z++;
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
void ofApp::mouseReleased(int x, int y, int button){
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

#include "ofApp.h"

#define PORT 5001

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
    if (!isAvailable) {
        delayCounter += 1;
        if (delayCounter > delaytime) {
            isAvailable = true; delayCounter = 0;
            curBgTop = bgTop;
            curBgBottom = bgBottom;
            giftBox.countUp();
            giftBox.update();
        }
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    cam = ofEasyCam();
    
    receiver.setup(PORT);
    bang = 0;
    ofHideCursor();
    tagCount.setup();
    mItem.setup();
    giftBox.setup();
    
    bgTop.load("images/bg_top.png");
    bgBottom.load("images/bg_bottom.png");
    bgTagBoy.load("images/bg_tag_boy.png");
    bgTagGirl.load("images/bg_tag_girl.png");
    bgTagTop.load("images/bg_tag_top.png");
    
    curBgTop = bgTop;
    curBgBottom = bgBottom;
    
    bgm.load("sounds/back.mp3");
    success.load("sounds/success.mp3");
    
    bgm.setLoop(true);
    bgm.play();
    isAvailable = true;
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
        tagCount.checked = true;
        tagCount.countState = 1;
        mItem.isChecked = true;
        curBgTop = bgTagTop;
        int idx = mItem.currentItemIdx;
        switch(idx) {
            case 1 ... 4: delaytime = 270; break;
            case 5 ... 8: delaytime = 240; break;
            case 9 ... 12: delaytime = 210; break;
        }
        if(idx == 1 | idx == 2 | idx == 7 | idx == 8 | idx == 9 | idx == 10)
            curBgBottom = bgTagBoy;
        else
            curBgBottom = bgTagGirl;
    }
    if (curr_tm -> tm_hour >= 18 || curr_tm -> tm_hour < 8)
        bgm.setVolume(0.0f);
    else
        bgm.setVolume(0.3f);
    
    tagCount.update();
    mItem.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    cam.setPosition(ofVec3f(x, y, z));  // x, y, z (240,1920,4000)
    ofRotateZ(90);
    curBgTop.draw(0, 1920, 1080, 1920);
    curBgBottom.draw(0, 0, 1080, 1920);
    tagCount.draw();
    mItem.draw();
    giftBox.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 119) {
        y+=10;
    }
    else if (key == 97) {
        x-=10;
    }
    else if (key == 115) {
        y-=10;
    }
    else if (key == 100) {
        x+=10;
    }
    else if (key == 113) {
        z-=10;
    }
    else if (key == 101) {
        z+=10;
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

#include "ofApp.h"
#include <ctime> //for logging
int x = -1500, y = 500, z=1000;
time_t rawtime;

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
        if (abbco > 200) {
            abb = 0; abbco = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    cam = ofEasyCam();
    // Here you set up a object of classes (such as load(), setup(),..
    
    std::cout << "\n ";
    std::cout << " > 위에 화면 보기 (1)\n";
    std::cout << " > 아래 화면 보기 (2)\n";
    std::cout << " > 입력 : ";
    std::cin  >> t;
    //std::cout << " > Frame  rate (max for 0)\n";
    //std::cout << " > 입력 :";
    //std::cin  >> frame_r;
    
    receiver.setup(PORT);
    bang = 0;
    ofHideCursor();
    
    count=0;
}

//--------------------------------------------------------------
void ofApp::update(){
    osc208();
    if (bang != 0 && abb == 0 &&completeCounter==-1) {
        abb = 1;
        if (word_writing)return;
        if (c_index <= c_endIndex)return;
        test = true;
        
        count++;
        // Log the check-time in the ~/bin/data/log.txt
        time(&rawtime);
        myTextFile.open("log.txt", ofFile::Append);
        myTextFile << ctime(&rawtime);
        myTextFile.close();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    cam.setPosition(ofVec3f(240, 1920, 4000));  // x, y, z (240,1920,4000)
    //ofRotateZ(90);
    background_up.draw(0, 0, 1080, 1920);
    background_down.draw(0, 1920);

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

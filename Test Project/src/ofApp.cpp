#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam=ofEasyCam();
    background.load("images/background.png");
    kimchi.setup();
    isClicked = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    kimchi.update(isClicked);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    cam.setPosition(ofVec3f(240, 1920, 4000));  // x, y, z (240,1920,4000)
    background.draw(0, 0);
    background.resize(1080, 3840);
    kimchi.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    isClicked = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

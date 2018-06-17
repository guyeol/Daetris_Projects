#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  bg_top.load("images/Refurday_1.png");
  bg_bottom.load("images/Refurday_2.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetHexColor(0xffffff);
  ofRotateZ(90);
  ofTranslate(-1080 + tx, 0 + ty, 0);
  bg_bottom.draw(0, 0, 1080, 1920);
  bg_top.draw(0, 1920, 1080, 1920);
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

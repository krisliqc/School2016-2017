#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    art1.setup("artone.jpg",50,300);
    art2.setup("arttwo.jpg",500, 300);
    art3.setup("artthree.jpg",980, 250);
}

//--------------------------------------------------------------
void ofApp::update(){
    art1.update();
    art2.update();
    art3.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 50);
    art1.draw();
    art2.draw();
    art3.draw();
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

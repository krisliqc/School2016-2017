#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    oneppl = "You are alone";
    twoppl = "Friend A comes to help";
    threeppl = "Friend B alsocomes to help";
    
    onepplx = "First person let go";
    twopplx = "Second person let go";
    threepplx = "Third person let go";
}

//--------------------------------------------------------------
void ofApp::update(){
    countdown = "Time passed = " + ofToString(ofGetElapsedTimeMillis()*0.001);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawCircle(200, 200, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 'a' || key == 'A'){
        ofSetColor(0, 0, 255);
        ofDrawBitmapString(oneppl, 200,500);
        ofDrawCircle(200, 200, 100);
        
        if (key == 'b' || key == 'B'){
            
            ofDrawBitmapString(twoppl, 400,500);
            ofDrawCircle(200, 400, 100);
        } else {
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == '1'){
        ofDrawBitmapString(onepplx, 100,100);
    }
    
    //else if (key == ' '){
        ; // do something else
    //}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    ofSetColor(0, 0, 255);
    ofDrawBitmapString(oneppl, 100,100);
    ofDrawCircle(200, 200, 100);
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

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    background.load("google.jpg");
    
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    
    res = 500;
    radius = 200;
    
    height = radius*0.05;
    loop = 24;
    
    pct = 0.6;
    
    //-------------------
    
    angle2 = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    circle.clear();
    speed = ofGetElapsedTimef()*0.5;
    
    for(int i = 0; i < res; i++){
        angle = ofMap(i, 0, res, 0, 2*PI);
        rise = height*sin((angle+speed)*loop);
        
        float x, y;
        
        if(i < res*pct){
            x = cos(angle)*(radius+rise);
            y = sin(angle)*(radius+rise);
            //            x = cos(angle)*(radius+rise);
            //            y = sin(angle)*(radius+rise);
        } else {
            x = cos(angle)*(radius);
            y = sin(angle)*(radius);
        }
        
        circle.addVertex(ofPoint(x,y));
    }

    //---------
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    background.draw(0,0,ofGetWidth(),ofGetHeight());
    
    //--------
    
    ofPushMatrix();
//    ofSetColor(32,54,111);
    //    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255,50);
    ofSetLineWidth(4);
//    ofRotate(ofGetElapsedTimef());
    ofTranslate(pos);
    circle.draw();
    
//    ofSetColor(255, 0, 0);
    
    ofPopMatrix();
    ofDrawEllipse(ofGetMouseX(), ofGetMouseY(), 10, 10);
    
    //--------------
    
    ofPushMatrix();
    
    ofTranslate(pos);
    for(int i = 0; i < 360; i++){
        float length = 350* ofNoise(ofGetElapsedTimef()/4,i*0.001);
        ofSetColor(255-0.2*i, 255 - 0.1*i, 230,50);
        ofSetLineWidth(2);
        ofDrawLine(0, 0, cos(i)*length, sin(i)*length);
    }
    ofPopMatrix();
    
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

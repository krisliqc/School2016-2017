#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    num = 50;
    
    for(int i = 0; i< num; i++){
        
        
        float x = ofRandom(ofGetWidth());
        float y = ofRandom(ofGetHeight());
        
        Particle tempP;
        tempP.setInitialCondition(ofPoint(x,y), ofPoint(0,0));
        particles.push_back(tempP);
        
    }
    
    wall.load("images/wall.jpg");
    
    gui.setup();
    gui.add(attField.setup("Attraction Field", 600, 300,1000));
    gui.add(attStrength.setup("Attraction Strength",0.001,0,0.1));
    gui.add(repField.setup("Repelsion Field", 200, 0,1000));
    gui.add(repStrength.setup("Repelsion Strength",0.015,0,0.1));
    gui.add(gravity.setup("Gravity", 0.1, 0,10));

}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < num; i++){
        
        particles[i].resetForce();
        particles[i].addAttractionForce(ofPoint(mouseX, mouseY), attField, attStrength);
        particles[i].addRepulsionForce(ofPoint(mouseX, mouseY), repField, repStrength);
        
        particles[i].update(&particles);
        particles[i].gravity(gravity);
        particles[i].bound();
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    wall.draw(0,0,ofGetWidth(),ofGetHeight());
//    ofBackground(180,120,0);
    
    gui.draw();
    ofSetColor(0);
    for(int i =0; i<num; i++){
        particles[i].draw();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for(int i = 0; i < num; i++){

    float x = ofRandom(ofGetWidth());
    float y = ofRandom(ofGetHeight());
    
    particles[i].setInitialCondition(ofPoint(x,y), ofPoint(0,0));
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

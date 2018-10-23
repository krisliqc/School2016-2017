#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    background.load("ins.png");
    //
//    ofSetBackgroundAuto(false);
//    ofSetVerticalSync(true); // don't go too fast
//    ofEnableAlphaBlending();
    
    // randomly allocate the points across the screen
//    points.resize(nPoints);
//    for(int i = 0; i < nPoints; i++) {
//        points[i] = ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
//    }
//    
//    // we'll be drawing the points into an ofMesh that is drawn as bunch of points
//    cloud.clear();
//    cloud.setMode(OF_PRIMITIVE_POINTS);
    noise.setup();
}
//
////--------------------------------------------------------------
////--------------------------------------------------------------
//ofVec2f ofApp::getField(ofVec2f position) {
//    float normx = ofNormalize(position.x, 0, ofGetWidth());
//    float normy = ofNormalize(position.y, 0, ofGetHeight());
//    float u = ofNoise(t + phase, normx * complexity + phase, normy * complexity + phase);
//    float v = ofNoise(t - phase, normx * complexity - phase, normy * complexity + phase);
//    return ofVec2f(u, v);
//}


void ofApp::update(){
    
    noise.update();
//    width = ofGetWidth(), height = ofGetHeight();
//    t = ofGetFrameNum() * timeSpeed;
//    for(int i = 0; i < nPoints; i++) {
//        float x = points[i].x, y = points[i].y;
//        ofVec2f field = getField(points[i]); // get the field at this position
//        // use the strength of the field to determine a speed to move
//        // the speed is changing over time and velocity-space as well
//        float speed = (1 + ofNoise(t, field.x, field.y)) / pollenMass;
//        // add the velocity of the particle to its position
//        x += ofLerp(-speed, speed, field.x);
//        y += ofLerp(-speed, speed, field.y);
//        // if we've moved outside of the screen, reinitialize randomly
//        if(x < 0 || x > width || y < 0 || y > height) {
//            x = ofRandom(0, width);
//            y = ofRandom(0, height);
//        }
//        // save the changes we made to the position
//        points[i].x = x;
//        points[i].y = y;
//        // add the current point to our collection of drawn points
//        cloud.addVertex(ofVec2f(x, y));
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(100);
    background.draw(0,0,ofGetWidth(), ofGetHeight());
    noise.draw();
//    ofBackground(255);
//    if(debugMode) {
//        ofSetColor(0);
//        // draw a vector field for the debug screen
//        for(int i = 0; i < width; i += step) {
//            for(int j = 0; j < height; j += step) {
//                ofVec2f field = getField(ofVec2f(i, j));
//                ofPushMatrix();
//                ofTranslate(i, j);
//                ofSetColor(0);
//                ofDrawLine(0, 0, ofLerp(-windSpeed, windSpeed, field.x), ofLerp(-windSpeed, windSpeed, field.y));
//                ofPopMatrix();
//            }
//        }
//        // draw the points as circles
//        ofSetColor(ofColor::red);
//        for(int i = 0; i < nPoints; i++) {
//            ofDrawCircle(points[i], 2);
//        }
//    } else {
//        // when not in debug mode, draw all the points to the screen
//        ofSetColor(0, 10);
//        cloud.draw();
//    }
//    
//    ofDrawBitmapStringHighlight("click to reset\nhit any key for debug", 10, 10, ofColor::white, ofColor::black);
    
}

//--------------------------------------------------------------

void ofApp::keyPressed(int key){
//    debugMode = !debugMode;
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

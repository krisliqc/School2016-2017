#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetSmoothLighting(true);
    img.load("1.gif");
    img.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);
    
    //gui
    gui.setup();
    gui.add(size.setup("BOXSIZE",150,1,300) );
    gui.add(addRotation.setup("Add Rotation",false));
    gui.add(addTexture.setup("Add Texture",true));
    gui.add(addLight.setup("Add Light", true));
    
    light1.setDiffuseColor(ofColor(0,200,235));
    light1.setSpecularColor(ofColor(255));
    light2.setDiffuseColor(ofColor(180,80,140));
    light2.setSpecularColor(ofColor(255));
    
    material.setShininess(128);
    material.setSpecularColor(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    light1.setPosition(sin(ofGetElapsedTimef())*500, cos(ofGetElapsedTimef())*200, 500);
    light2.setPosition(sin(ofGetElapsedTimef())*200, cos(ofGetElapsedTimef())*500, 300);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    
    cam.begin();
    
    ofGetElapsedTimef();
    float sinTime = sin(ofGetElapsedTimef());
    
    if(addRotation){
    box.rotate(sinTime, 1, 1, 1);
    }
    
    
    box.set(size);
    box.setPosition(-100, 0,0);
    //    box.drawWireframe();
    
    if(!addLight){
        
        if(addTexture){
            img.getTexture().bind();
            box.mapTexCoordsFromTexture(img.getTexture());
            box.draw();
        } else {
            box.drawWireframe();
        }
    } else {
        
        sphere.set(size*0.5, 16);
        sphere.setPosition(100, 20, 0);
        
        ofEnableLighting();
        light1.enable();
        light2.enable();
        
        material.begin();
        sphere.draw();
        box.draw();
        material.end();
        
    }
    
    
    cam.end();
    ofDisableDepthTest();
    ofDisableLighting();
    
    gui.draw();
    
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

//
//  image.cpp
//  is_final
//
//  Created by Kris Li on 5/8/17.
//
//

#include "image.hpp"

image::image(){
    
}

void image::setup(string _name, int _xPos, int _yPos){
    original.load(_name);
    xPos = _xPos;
    yPos = _yPos;
}

void image::update(){
    
    float dist = ofDist(xPos, 0, ofGetMouseX(), 0);
    size = ofMap(dist, 0,500, 2, 20);
}

void image::draw(){
//    original.draw();
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    ofRectMode(CENTER);
    int w = original.getWidth();
    int h = original.getHeight();
    
    for (int i = 0; i < w; i+=size){
        
        for (int j = 0; j < h; j+=size){
            ofColor orig = original.getColor(i,j);
            ofSetColor(orig);
            ofDrawRectRounded(i, j, size, size, size*0.5);
//            cout << "drawing" << endl;
        }
    }
    ofPopMatrix();
}

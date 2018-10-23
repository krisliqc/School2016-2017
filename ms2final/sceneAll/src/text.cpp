//
//  text.cpp
//  sceneAll
//
//  Created by Kris Li on 4/22/17.
//
//

#include "text.hpp"

text::text(){
    
}

void text::setup(string _name){
    ofSetFrameRate(30);
    adiSans.load("AdiSans-Regular.otf", ofRandom(10,15));
    
    nextLetterTime = ofGetElapsedTimeMillis();
    lineCount      = 0;
    letterCount    = 0;
    
    // this is our buffer to stroe the text data
    ofBuffer buffer = ofBufferFromFile(_name + ".txt");
    
    if(buffer.size()) {
        
        for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
            
            string line = *it;
            
            // copy the line to draw later
            // make sure its not a empty line
            if(line.empty() == false) {
                seussLines.push_back(line);
            }
            
            // print out the line
//            cout << line << endl;
        }
    }
//    
    lineCount = floor(ofRandom(seussLines.size()));
    
}

void text::update(ofPoint _pos, ofPoint _rotate){
    // the total width on the line
    strWidth = (seussLines[lineCount].length()*8) + 5;
    
    pos = _pos;
    
//    float rotAmt = atan2( vel.y,vel.x);
    rotate = ofRadToDeg(atan2( _rotate.y,_rotate.x));
    
}

void text::draw(){
    
    ofSetDrawBitmapMode(OF_BITMAPMODE_SIMPLE);
    
    
    // we are slowy grabbing part of the line
    string typedLine = seussLines[lineCount].substr(0, letterCount);
    
    // draw the line
    ofPushMatrix();
    
    ofTranslate(pos);
    ofRotate(rotate);
    ofSetColor(0);
    ofDrawRectangle(0,0, strWidth, 15);
    ofSetColor(255);
    
//    ofRotate(0.25*PI);
    ofDrawBitmapString(typedLine, 4, 11);
    ofPopMatrix();
    
    // this is our timer for grabbing the next letter
    float time = ofGetElapsedTimeMillis() - nextLetterTime;
    
    if(time > 9) {
        
        // increment the letter count until
        // we reach the end of the line
        if(letterCount < (int)seussLines[lineCount].size()) {
            
            // move on to the next letter
            letterCount ++;
            
            // store time for next letter type
            nextLetterTime = ofGetElapsedTimeMillis();
            
        }
        else {
            
            // wait just a flash then move on
            // to the next line...
            if(time > 300) {
                
                nextLetterTime = ofGetElapsedTimeMillis();
                letterCount = 0;
                lineCount ++;
                lineCount %= seussLines.size();
                
                if(lineCount == seussLines.size()){
                    lineCount = 0;
                }
            }
        }
    }
    
}

//
//  wave.cpp
//  sceneAll
//
//  Created by Kris Li on 4/22/17.
//
//

#include "wave.hpp"

wave::wave (){
}

void wave::setup(){
    
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    
    num = 20;
    
    for(int i = 0; i < 20; i++){
        ofPoint temp;
        ends.push_back(temp);
    }
    
    for(int i = 0; i < 20; i++){
        ofPoint temp;
        endsAngle.push_back(temp);
    }
}

void wave::update(){
    
}

void wave::draw(){
    ofPushMatrix();

    ofTranslate(pos);
    for(int i = 0; i < 360; i+=3){
        float rad = ofDegToRad(i);
        
        float length = 200+100* ofNoise(ofGetElapsedTimef()*0.6,rad*2);
        ofSetColor(255-0.5*i, 255 - 0.3*i, 230,100);
        
        float width = ofMap(length,200,300,1,5);
        ofSetLineWidth(roundf(width));
        ofDrawLine(0, 0, cos(rad)*length, sin(rad)*length);
        
        ofPoint thisEnd = ofPoint(cos(rad)*length,sin(rad)*length);
        
        for (int i = 1; i < 5; i++){
            ofDrawEllipse(cos(rad)*length*(1+0.1*i), sin(rad)*length*(1+0.1*i),width*(1-0.1*i),width*(1-0.1*i));
        }
        
        if(i % 18 ==0){
            ends.push_back(thisEnd);
            ends.erase(ends.begin());
            
//            ofPoint endAngle = ofRadToDeg(atan2(thisEnd.y,thisEnd.x)+90);
        }
    }
    ofPopMatrix();
}



////    float rotAmt = atan2( vel.y,vel.x);
//rotate = ofRadToDeg(atan2( _rotate.y,_rotate.x)+90);

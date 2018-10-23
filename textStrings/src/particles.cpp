//
//  particles.cpp
//  textStrings
//
//  Created by Kris Li on 4/10/17.
//
//

#include "particles.hpp"

//void particles::setAttractPoints( vector <ofPoint> * attract ){
//    attractPoints = attract;
//    
//    drag = ofRandom(0.95, 0.98);
//}

void particles::reset(){
    
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
//    vel.x = ofRandom(-3.9, 3.9);
//    vel.y = ofRandom(-3.9, 3.9);
}

void particles::gravity(){
//    frc.y +=0.1;
}

void particles::attract(){
    
//    //attract
//    ofPoint attractPt(ofGetMouseX(), ofGetMouseY());
//    atr = attractPt-pos;
//    atr.normalize();
//    
//    vel *= drag; //apply drag
//    vel += acc * 0.6; //apply force
    
    
}

void particles::repulse(){
    
}

void particles::update(){
    
    
}

void particles::bound(){
    
//    if( pos.x > ofGetWidth() ){
//        pos.x = ofGetWidth();
//        vel.x *= -1.0;
//    }else if( pos.x < 0 ){
//        pos.x = 0;
//        vel.x *= -1.0;
//    }
//    if( pos.y > ofGetHeight() ){
//        pos.y = ofGetHeight();
//        vel.y *= -1.0;
//    }
//    else if( pos.y < 0 ){
//        pos.y = 0;
//        vel.y *= -1.0;
//    }	
    
}

void particles::draw(){
    ofSetColor(255,0, 0);
    ofDrawCircle(pos,5);
}




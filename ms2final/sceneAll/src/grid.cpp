//
//  grid.cpp
//  sceneAll
//
//  Created by Kris Li on 4/22/17.
//
//

#include "grid.hpp"

grid::grid(){
    setInitialCondition(ofPoint(0,0), ofPoint(0,0));
    damping = 0.09;
    
}

void grid::setInitialCondition(ofPoint _pos, ofPoint _vel){
    
    pos.set(_pos.x, _pos.y);
    vel.set(_vel.x, _vel.y);
}

void grid::update(){
    vel = vel + force;
    pos = pos + vel;
}

void grid::resetForce(){
    force.set(0, 0);
}

void grid::addDampingForce(){
    force = force - vel * damping;
}

void grid::addRepulsionForce(ofPoint _pos, float _radius, float _strength){
    
    ofPoint posOfForce;
    posOfForce.set(_pos.x, _pos.y);
    
    ofPoint diff = pos - posOfForce;
    
    if(diff.length() < _radius){
        
        //smooth
        //        float pct = 1 - (diff.length() / _radius);
        //        diff.normalize();
        //        force += diff * pct * _strength;
        //wiggly
        diff *= ofMap(diff.length(), 0, _radius, 1.0, 0.0);
        force += diff * _strength;
        
    }
}

void grid::addAttractionForce(ofPoint _pos, float _radius, float _strength){
    
    ofPoint posOfForce;
    posOfForce.set(_pos.x, _pos.y);
    
    ofPoint diff = pos - posOfForce;
    
    if(diff.length() < _radius){
        //smooth:
        //        float pct = 1 - (diff.length() / _radius);
        //        diff.normalize();
        //        force -= diff * pct * _strength;
        
        //wiggly:
        diff *= ofMap(diff.length(), 0, _radius, 1.0, 0.0);
        force -= diff * _strength;
    }
    
}

void grid::draw(){
    //    ofSetColor()
    float r = ofMap(pos.y, 0, ofGetHeight(), 0, 10);
    float g = ofMap(pos.y, 0, ofGetHeight(), 20, 220);
    float b = ofMap(pos.x, 0, ofGetWidth(), 250, 80);
//    ofSetColor(r, g, b);
    ofSetColor(255,80);
    
    for(int i=0; i <5; i++){
        ofDrawCircle(pos, i*4);
    }
    
}










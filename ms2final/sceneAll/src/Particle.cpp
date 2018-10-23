//
//  Particle.cpp
//  Forces
//
//  Created by Charlie Whitney on 9/30/13.
//
//

#include "Particle.h"

Particle::Particle() {
    mass = 1.0;
}

void Particle::applyForce(ofVec2f force){
    accel += (force / mass);
}

void Particle::update(){
    vel += accel;
    pos += vel;
    
    vel *= 0.97;
    
    accel.set(0);
    
    if(pos.x <0){
        pos.x = ofGetWidth();
    }
    if(pos.x > ofGetWidth()){
        pos.x = 0;
    }
    if(pos.y <0){
        pos.y = ofGetHeight();
    }
    if(pos.y > ofGetHeight()){
        pos.y = 0;
    }
    
    perlin = ofNoise(ofGetElapsedTimef()/4);
}

void Particle::link( vector<Particle> *_particleList){
    for(int i = 0; i < _particleList->size(); i++){
        //determining if the particle in the loop is itself
        //to avoid itself
        if (&(*_particleList)[i] == this) {
            continue;
        }
        
        float distance = ofDist(pos.x, pos.y, (*_particleList)[i].pos.x,(*_particleList)[i].pos.y);
        
        if(distance < 100){
            ofPushStyle();
            float bright = ofMap(distance, 0, 100, 255, 100);
            ofSetColor(255,bright);  //runs
            
            float thickness = ofMap(distance, 0, 100, 3, 1);
            ofSetLineWidth(thickness);
            ofDrawLine(pos.x,pos.y, (*_particleList)[i].pos.x, (*_particleList)[i].pos.y);   //doesnt run
            ofPopStyle();
        }
    }
}

void Particle::draw() {
//    ofSetColor(perlin*(150), perlin*(50),perlin*(50),120);
//    ofDrawEllipse( pos, 5,5 );
}

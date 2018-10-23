//
//  trail.cpp
//  sceneAll
//
//  Created by Kris Li on 5/1/17.
//
//

#include "trail.hpp"

void trail::setup(ofPoint _pos){
    pos = _pos;
    size = 10;
    lifeTime = 0;
}

//void trail::addPt(ofPoint _pos){
//    ofPoint temp  = _pos;
//    trailPts.push_back(temp);
//}

void trail::update(){
//    pos = _pos
//    if(trailPts.size()>100){
//        trailPts.erase(trailPts.begin());
    lifeTime ++;
    
}

void trail::draw(int _period){
    
    float a = ofMap(lifeTime,0,_period,80,0);
    
    float newSize = ofMap(size,0,a,0,10 );
    
    for(int i = 0; i < 3; i++){
        ofSetColor(200,0,100,a/i);
        ofDrawCircle(pos, newSize+3*i);
    }

}




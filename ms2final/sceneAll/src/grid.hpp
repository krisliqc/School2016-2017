//
//  grid.hpp
//  sceneAll
//
//  Created by Kris Li on 4/22/17.
//  Reference to Regina Flores AlgoSims 2016
//

#pragma once
#include "ofMain.h"

class grid{
    
public:
    grid();
    void resetForce();
    void addDampingForce();
    void setInitialCondition(ofPoint _pos, ofPoint _vel);
    void update();
    void draw();
    void addRepulsionForce(ofPoint _pos, float _radius, float _strength);
    void addAttractionForce( ofPoint _pos, float _radius, float _strength);
    ofPoint pos;
    
private:
    ofPoint vel, force; //force is also known an acceleration. Newton F = ma
    float damping;
    
};

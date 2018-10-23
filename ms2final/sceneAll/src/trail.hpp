//
//  trail.hpp
//  sceneAll
//
//  Created by Kris Li on 5/1/17.
//
//

#pragma once
#include "ofMain.h"

class trail {
    
public:
    
    void setup(ofPoint _pos);
    void update();
    void draw(int _period);
    
    ofPoint pos;
    float size;
    int lifeTime;
};



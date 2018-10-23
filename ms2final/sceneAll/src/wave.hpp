//
//  wave.hpp
//  sceneAll
//
//  Created by Kris Li on 4/22/17.
//
//

#pragma once
#include "ofMain.h"

class wave {
    
public:
    
    wave();
    
    void setup();
    void update();
    void draw();
    
    ofPoint pos;
    float rotate;

    vector<ofPoint> ends;
    vector<ofPoint> endsAngle;
    int num;
};

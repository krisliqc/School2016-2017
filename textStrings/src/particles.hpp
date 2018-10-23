//
//  particles.hpp
//  textStrings
//
//  Created by Kris Li on 4/10/17.
//
//

#pragma once
#include <ofMain.h>

class particles {
    
public:
    particles();
    
    void reset();
    void update();
    void attract();
    void repulse();
    void gravity();
    
    void draw();
    void bound();
    
    
    float drag;
    float uniqueVal;
    float scale;
    
//    vector <ofPoint> * attractPoints;
    
private:
    
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;
//    vector <> texts;
    
    
};

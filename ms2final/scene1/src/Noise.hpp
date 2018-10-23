//
//  Noise.hpp
//  scene1
//
//  Created by Kris Li on 4/22/17.
//  Reference: openFrameworks example folder NoiseField2D
//

#pragma once
#include"ofMain.h"

class Noise {
    
public:
    
    Noise();
    
    void setup();
    void update();
    void draw();
    ofVec2f getField(ofVec2f position);

    vector<ofVec2f> points;
    ofMesh cloud;
    float t;
    float width, height;

    int nPoints = 256; // points to draw
    float complexity = 6; // wind complexity
    float pollenMass = .8; // pollen mass
    float timeSpeed = .02; // wind variation speed
    float phase = TWO_PI; // separate u-noise from v-noise
    float windSpeed = 20; // wind vector magnitude for debug
    int step = 10; // spatial sampling rate for debug
    bool debugMode = false;

};

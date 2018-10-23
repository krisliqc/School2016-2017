//
//  video.hpp
//  sceneAll
//
//  Created by Kris Li on 4/26/17.
//
//

#pragma once
#include "ofMain.h"
#include "trail.hpp"

class video {
    
public:
    
    void setup();
    void update(int _x, int _y, float _ratio);
    void draw(int _x, int _y, float _ratio);
    
    ofVideoPlayer 		movie;
    bool                frameByframe;
    
    ofPixels pixels;
    int vidWidth;
    int vidHeight ;
    int nChannels ;
    
    vector<ofPoint> trailPos;
    
};



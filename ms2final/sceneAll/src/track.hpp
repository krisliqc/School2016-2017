//
//  track.hpp
//  sceneAll
//
//  Created by Kris Li on 4/22/17.
//
//

#pragma once
#include "ofMain.h"


class track{
    
public:
    
    track();
    
    void setup();
    void update();
    void draw();
    
    ofImage background;
    
    ofVideoPlayer video;
    ofFbo fbo;
    ofMesh mesh;
    
    ofImage image;
    ofPixels fboPixels;
    
    ofEasyCam cam;
    
    //video width and video height
    //MUST be the same w, h of the actual video
    int videoWidth = 450;
    int videoHeight = 360;
    
    int W = 200;
    int H = 200;
    
    int meshSize = 6; //scale to enlargen the mesh
    float distortion = 2;
    
    vector<ofPoint> pts;
    vector<ofPoint> ptsS;
    int count;
    
};

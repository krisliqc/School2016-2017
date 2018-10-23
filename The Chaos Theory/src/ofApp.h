#pragma once

#include "ofMain.h"
#define N 256
#define n 300

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    
    ofSoundPlayer sound;	//Sound sample
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    float spectrum[N];
    float move;
    float vel;
    int specMove = 2;
    int specVel = 100;
    
    
    float tx[n], ty[n],tz[n];
    ofPoint pos[n];
    
    float time0 = 0;
    float r,e,f;
};

#pragma once

#include "ofMain.h"
#include "Noise.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofImage background;
    
    Noise noise;
    
    //noise
//    ofVec2f getField(ofVec2f position);
//    
//    vector<ofVec2f> points;
//    ofMesh cloud;
//    float t;
//    float width, height;
//    
//    int nPoints = 4096; // points to draw
//    float complexity = 6; // wind complexity
//    float pollenMass = .8; // pollen mass
//    float timeSpeed = .02; // wind variation speed
//    float phase = TWO_PI; // separate u-noise from v-noise
//    float windSpeed = 40; // wind vector magnitude for debug
//    int step = 10; // spatial sampling rate for debug
//    bool debugMode = false;
};

#pragma once

#include "ofMain.h"
#include "text.hpp"
#include "FlowField.h"
#include "Particle.h"
#include "grid.hpp"
#include "wave.hpp"
#include "video.hpp"
#include "trail.hpp"
#include "ofxGui.h"

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
		
    //overall-----------------
    int state;
    ofImage background1;
    ofImage background2;
    ofImage background3;
    ofImage background4;
    ofImage background4b;
    
    ofPoint centerScreen;
    ofPoint movingPt;
    
    int time;
    
    
    //text--------------------
    
    vector<text> googleTexts;
    vector<text> insTexts;
    vector<text> fbTexts;
    ofPoint textPos;
    
    
    //state1 points: google -----------
    void addParticle();
    
    FlowField           myField;
    vector<Particle>    particleList;
    vector<Particle>    smallList;
    
    //state2 grid: ins-----------
    vector<grid> gridPts;
    vector<ofPoint> gridSel;
    int ptsW;
    int ptsH;
    
    //state3 waves: fb -----------
    wave myWave;
    
    //state4 map: location -----------
//    track myTrack;
    video myVideo;
    
    ofxIntSlider xValue;
    ofxIntSlider yValue;
    ofxFloatSlider ratio;
    ofxPanel gui;
    
//    trail myTrail;
    vector<trail> myTrails;
    int period;
};




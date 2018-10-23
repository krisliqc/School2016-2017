//
//  text.hpp
//  sceneAll
//
//  Created by Kris Li on 4/22/17.
//
//

#pragma once
#include "ofMain.h"

class text {
    
    public:

    text();
    
    void setup(string name);
    void update(ofPoint _pos, ofPoint _rotate);
    void draw();

    ofPoint pos;
    float rotate;
    
    int strWidth;
    
    float           nextLetterTime;
    int             lineCount;
    int             letterCount;
    int             lineNum;
    vector <string> seussLines;
    
    ofTrueTypeFont adiSans;
};

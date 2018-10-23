//
//  image.hpp
//  is_final
//
//  Created by Kris Li on 5/8/17.
//
//

#pragma once
#include "ofMain.h"

class image {
    
public:
    image();
    
    void setup(string _name, int _xPos, int _yPos);
    void update();
    void draw();
    
    ofImage original;
    int size;
    int xPos, yPos;
    
};

//
//  video.cpp
//  sceneAll
//
//  Created by Kris Li on 4/26/17.
//
//

#include "video.hpp"

//--------------------------------------------------------------
void video::setup(){
//    ofBackground(255,255,255);
    ofSetVerticalSync(true);
    frameByframe = false;
    
    // Uncomment this to show movies with alpha channels
    movie.setPixelFormat(OF_PIXELS_RGBA);
    
    movie.load("trace2.mov");
    movie.setLoopState(OF_LOOP_NORMAL);
    movie.play();
    
     pixels = movie.getPixels();
    
    vidWidth = pixels.getWidth();
    vidHeight = pixels.getHeight();
    nChannels = pixels.getNumChannels();

}

//--------------------------------------------------------------
void video::update(int _x, int _y, float _ratio){
    movie.update();
    
    pixels = movie.getPixels();

    for (int i = 4; i < vidWidth; i+=8){
        for (int j = 4; j < vidHeight; j+=8){
            
            unsigned char r = pixels[(j * 652 + i)*nChannels];
            unsigned char b = pixels[(j * 652 + i)*nChannels+2];
            
            float val = 1 - ((float)r / 255.0f);
            
            ofSetColor(255,150);
            
            //            cout << (float)b <<endl;
            //
            if(val < 0.5){
                continue;
            }
            
            ofPoint temp = ofPoint(i*_ratio, j*_ratio);
            trailPos.push_back(temp);
            
            ofDrawCircle(i*_ratio + _x,j*_ratio + _y,10*val);
            
        }
        ofSetColor(255);
    }
}

//--------------------------------------------------------------
void video::draw(int _x, int _y, float _ratio){
    
    pixels = movie.getPixels();
    
    // let's move through the "RGB(A)" char array
    // using the red pixel to control the size of a circle.
    for (int i = 4; i < vidWidth; i+=8){
        for (int j = 4; j < vidHeight; j+=8){
            
            unsigned char r = pixels[(j * 652 + i)*nChannels];
            unsigned char b = pixels[(j * 652 + i)*nChannels+2];
            
            float val = 1 - ((float)r / 255.0f);
            
            ofSetColor(255,150);
            
//            cout << (float)b <<endl;
//
            if(val < 0.45){
                continue;
            }
            
            ofPoint temp = ofPoint(i*_ratio, j*_ratio);
            trailPos.push_back(temp);
            
            ofDrawCircle(i*_ratio + _x,j*_ratio + _y,10*val);
            
        }
        ofSetColor(255);
    }
}






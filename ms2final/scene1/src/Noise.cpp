//
//  Noise.cpp
//  scene1
//
//  Created by Kris Li on 4/22/17.
//
//

#include "Noise.hpp"

Noise::Noise(){

}

void Noise::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true); // don't go too fast
    ofEnableAlphaBlending();
    
//    cloud.setMode(OF_PRIMITIVE_LINES);
//    cloud.setMode(OF_PRIMITIVE_LINE_STRIP);
    cloud.setMode(OF_PRIMITIVE_LINE_LOOP);

    
    // randomly allocate the points across the screen
    points.resize(nPoints);
    for(int i = 0; i < nPoints; i++) {
        points[i] = ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
    }
    
    // we'll be drawing the points into an ofMesh that is drawn as bunch of points
    cloud.clear();
//    cloud.setMode(OF_PRIMITIVE_POINTS);
}

ofVec2f Noise::getField(ofVec2f position) {
    float normx = ofNormalize(position.x, 0, ofGetWidth());
    float normy = ofNormalize(position.y, 0, ofGetHeight());
    float u = ofNoise(t + phase, normx * complexity + phase, normy * complexity + phase);
    float v = ofNoise(t - phase, normx * complexity - phase, normy * complexity + phase);
    return ofVec2f(u, v);
}

void Noise::update(){
    width = ofGetWidth(), height = ofGetHeight();
    t = ofGetFrameNum() * timeSpeed;
    for(int i = 0; i < nPoints; i++) {
        float x = points[i].x, y = points[i].y;
        ofVec2f field = getField(points[i]); // get the field at this position
        // use the strength of the field to determine a speed to move
        // the speed is changing over time and velocity-space as well
        float speed = (1 + ofNoise(t, field.x, field.y)) / pollenMass;
        // add the velocity of the particle to its position
        x += ofLerp(-speed, speed, field.x);
        y += ofLerp(-speed, speed, field.y);
        // if we've moved outside of the screen, reinitialize randomly
        if(x < 0 || x > width || y < 0 || y > height) {
            x = ofRandom(0, width);
            y = ofRandom(0, height);
        }
        // save the changes we made to the position
        points[i].x = x;
        points[i].y = y;
        // add the current point to our collection of drawn points
        
        cloud.addVertex(ofVec2f(x, y));
        
        float r = ofMap(x, 0, ofGetWidth(), 255, 0);
        float g = ofMap(y, 0, ofGetHeight(), 0, 100);
//        float b = ofMap(i, 0, nPoints, 0, 255);
        float b = ofMap(y, 0, ofGetHeight(), 255, 0);
        
//        int left = cloud.getNumVertices() % nPoints ;
//        float alpha = ofMap(left, 0, nPoints, 0, 255);
        
        cloud.addColor(ofColor(r,g,b,150));
        
        if (cloud.getNumVertices() >  nPoints *2) {
//        if(i % 2 == 0){
        cloud.removeVertex(i);
//        }
        }
        
        //--set triangles
//        for(int i = 0; i <cloud.getNumVertices(); i++){
//            
//            ofPoint
//            
//            int i1,i2,i3,i4;
//            
//            cloud.addTriangle(i, i+1, i+2);
//            cloud.addTriangle(i+1, i+2,i+3);
//        }
    }
    
    //for loop
   for(int i = 0; i < cloud.getNumVertices()/10; i++) {
       
       
       ofPushStyle();
       ofSetColor(0);
       ofDrawCircle(cloud.getVertex(i),5);
       ofPopStyle();
       
       
       for(int j = 0; j < cloud.getNumVertices()/10; j++){
       ofPoint origin = cloud.getVertex(i*10);
       ofPoint end = cloud.getVertex(j*10);
       
           if (i == j) continue;
           
           
          float distance = ofDist(origin.x, origin.y, end.x, end.y);
           
           if (distance < 100){
               
               ofPushStyle();
               ofSetColor(255);
               ofSetLineWidth(3);
               ofDrawLine(origin, end);
               
               ofPopStyle();
//               cout<<"hahaha"<<endl;
        }
     }
   }
    
    
}

void Noise::draw(){
//    if(debugMode) {
//        ofSetColor(255,10);
//        // draw a vector field for the debug screen
//        for(int i = 0; i < width; i += step) {
//            for(int j = 0; j < height; j += step) {
//                ofVec2f field = getField(ofVec2f(i, j));
//                ofPushMatrix();
//                ofTranslate(i, j);
//                ofSetColor(0);
//                ofDrawLine(0, 0, ofLerp(-windSpeed, windSpeed, field.x), ofLerp(-windSpeed, windSpeed, field.y));
//                ofPopMatrix();
//            }
//        }
//        // draw the points as circles
//        ofSetColor(ofColor::red);
//        for(int i = 0; i < nPoints; i++) {
//            ofDrawCircle(points[i], 2);
//        }
//    } else {
        // when not in debug mode, draw all the points to the screen
//        ofSetColor(0, 10);
//        ofSetColor(255, 10);
        cloud.draw();
        cloud.drawWireframe();
//    }
    
    
    
    
//    ofDrawBitmapStringHighlight("click to reset\nhit any key for debug", 10, 10, ofColor::white, ofColor::black);

    
}






#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    
    state = 0;
    time = 0;
    centerScreen = ofPoint(ofGetWidth()/2,ofGetHeight()/2);
    
    background1.load("google.jpg"); //points
    background2.load("ins.png"); //grid
    background3.load("fb.jpg"); //waves
    background4.load("map2.png"); //location
    background4b.load("map3.png"); //location
    
    
    //state1 points: google -----------
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    particleList.clear();
    for( int i=0; i<300; i++ ){
        addParticle();
    }
    
    for (int i = 0; i < 60; i++){
        text p;
        p.setup("google");
        googleTexts.push_back(p);
    }
    
    //state2 grid: ins-----------
    for (int i = 0; i < 40; i++){
        text p;
        p.setup("ins");
        insTexts.push_back(p);
    }
    
    for (int i = 0; i < 40; i++){
        ofPoint p;
        gridSel.push_back(p);
    }
    
    ptsW = 30;
    ptsH = 20;
    
    for(int i = 0; i< ptsW; i++){
        for(int j = 0; j < ptsH; j++){
            float x = ofMap(i,0, ptsW, 0,ofGetWidth());
            float y = ofMap(j,0, ptsH, 0,ofGetHeight());
            grid tempP;
            tempP.setInitialCondition(ofPoint(x,y), ofPoint(0,0));
            gridPts.push_back(tempP);
        }
    }
    
    //state3 waves: fb -----------
    myWave.setup();
    for (int i = 0; i < 20; i++){
        text p;
        p.setup("fb");
        fbTexts.push_back(p);
    }
    movingPt = ofPoint (0,0);
    
    //state4 map: location -----------
    myVideo.setup();
    
    gui.add(xValue.setup("x", 84, 0, 300));
    gui.add(yValue.setup("y", 14, 0, 200));
    gui.add(ratio.setup("ratio", 1.53, 1, 3));
    
}

void ofApp::addParticle() {
    Particle part;
    part.pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    particleList.push_back( part );
}


//--------------------------------------------------------------
void ofApp::update(){
    
    time ++;
    
    if(time > 240){
        time = 0;
        state = floor(ofRandom(1,5));
        for( int i=0; i<particleList.size(); i++ ){
            ofPoint random = ofPoint(ofRandomWidth(),ofRandomHeight());
            particleList[i].pos = random;
        }

    }
    
    //moving pt
    movingPt.x = ofGetWidth()*ofNoise(ofGetElapsedTimef()/8);
    movingPt.y = ofGetHeight()*ofNoise(ofGetElapsedTimef()/8+1000);
    
    for (int i = 0; i < 10; i++){
        int x = ofGetWidth()*ofNoise(ofGetElapsedTimef()/10,i);
        int y = ofGetHeight()*ofNoise(ofGetElapsedTimef()/25,i);
        textPos = ofPoint(x,y);
        insTexts[i].update(textPos, ofPoint(0,1));
    }
    
    //state1 points: google -----------
    for( int i=0; i<particleList.size(); i++ ){
        ofVec2f forceAtPos = myField.getForceAtPosition(particleList[i].pos) * 0.005;
        particleList[i].applyForce( forceAtPos );
        particleList[i].update();
        myField.setPerlin();
    }
    
    for (int i = 0; i < 60; i++){
        googleTexts[i].update(particleList[i*5].pos, particleList[i*5].vel.getPerpendicular());
    }
    
    myField.update();
    
    //state2 grid: ins-----------
    if(state ==2){
    int count = 0;
    
        for(int i = 0; i< ptsW; i++){
            for(int j = 0; j < ptsH; j++){
            
            float x = ofMap(i,0, ptsW, 0,ofGetWidth());
            float y = ofMap(j,0, ptsH, 0,ofGetHeight());
            
            gridPts[count].resetForce();
            gridPts[count].addAttractionForce(ofPoint(x,y), 2000, 0.1);
            gridPts[count].addRepulsionForce(movingPt, 200, 0.2);
            
            gridPts[count].addDampingForce();
            gridPts[count].update();
            
            float distance = ofDist(gridPts[count].pos.x, gridPts[count].pos.y,movingPt.x, movingPt.y);
            if(distance < 100){
                gridSel.push_back(gridPts[count].pos);
                gridSel.erase(gridSel.begin());
            }
            count++;
            }
        }
        
        for (int i = 0; i < 40; i++){
            insTexts[i].update(gridSel[i], ofPoint(1,0));
        }
    }
    
    
    //state3 waves: fb -----------
    if(state ==3){
        for (int i = 0; i < 20; i++){
            
//            fbTexts[i].update(myWave.ends[i], myWave.ends[i]);
            fbTexts[i].update(centerScreen+myWave.ends[i]*1.2, myWave.ends[i]);
        }
    }
    
    //state4 map: location -----------

    period = 60;
    myVideo.update(xValue, yValue, ratio);
    
    int ptNum = myVideo.trailPos.size();
    cout << ptNum <<endl;
    
    for(int i = 0; i < ptNum; i ++){
        trail temp;
        temp.setup(myVideo.trailPos[i]);
        myTrails.push_back(temp);
    }
    
    for(int i=0; i< myTrails.size(); i++){
        myTrails[i].update();
        
        if(myTrails[i].lifeTime > period){
            myTrails.erase(myTrails.begin()+i);
        }
    }
    
    myVideo.trailPos.clear();
//    cout << myTrails.size() <<endl;
    
    int trailNum = myVideo.trailPos.size();
    for(int i = 0; i < trailNum; i++){
        trail p;
        p.setup(myVideo.trailPos[i]);
        myTrails.push_back(p);
    }
    
//    cout << myVideo.trailPos.size() <<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //test
//    for (int i = 0; i < 10; i++){
//        insTexts[i].draw();
//    }
    
    //state1 points: google -----------
    if(state ==1){
        background1.draw(0,0,ofGetWidth(),ofGetHeight());
        ofSetColor(255);
//        myField.draw();
        
        ofSetColor(0, 255, 255);
        for( int i=0; i<particleList.size(); i++ ){
            particleList[i].draw();
            particleList[i].link(&particleList);
        }
        
        for (int i = 0; i < 40; i++){
            googleTexts[i].draw();
        }
    }
    
    
    //state2 grid: ins-----------
    if(state ==2){
        background2.draw(0,0,ofGetWidth(),ofGetHeight());
        for(int i =0; i< gridPts.size(); i++){
            gridPts[i].draw();
        }
        for (int i = 0; i < 40; i++){
            insTexts[i].draw();
        }
    }
    

    
    //state3 waves: fb -----------
    if(state ==3){
        background3.draw(0,0,ofGetWidth(),ofGetHeight());
    
        myWave.draw();
        for (int i = 0; i < 20; i++){
            fbTexts[i].draw();
        }
    }
    
    //state4 map: location -----------
    if(state ==4){
//        background4.draw(-340+xValue,-125+yValue,ofGetWidth()*1.44,ofGetHeight()*1.2);
        background4.draw(-340,-155,ofGetWidth()*1.5,ofGetWidth()*1.5*0.63);
//        background4b.draw(0,-50,ofGetWidth()*1.44,ofGetHeight()*1.2);
        
//        myVideo.draw(xValue, yValue, ratio);
//        gui.draw();
       
        ofPushMatrix();
        ofTranslate(xValue, yValue);
        for(int i=0; i< myTrails.size(); i++){
            myTrails[i].draw(period);
        }
        ofPopMatrix();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1'){
        state = 1;
        for( int i=0; i<particleList.size(); i++ ){
            ofPoint random = ofPoint(ofRandomWidth(),ofRandomHeight());
            particleList[i].pos = random;
        }

    } else if (key == '2'){
        state = 2;
    } else if (key == '3'){
        state = 3;
    } else if (key == '4'){
        state = 4;
    }
    
    cout << state <<endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

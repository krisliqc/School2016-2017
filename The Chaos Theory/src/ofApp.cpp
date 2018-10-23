#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    ofToggleFullscreen();
    sound.loadSound( "sounds/yo.mp3" );
    sound.setLoop( true );
    sound.play();
    
    for (int i=0; i<N; i++) {
        spectrum[i] = 0.0f;
    }
    
    r = 1;
    
    for ( int j=0; j<n; j++ ) {
        ty[j] = r * sin(ofRandom(TWO_PI));
        e = 0.5;
        f = ofRandom(0,1);
        if (f<e) {
            tx[j] = sqrt(r*r - ty[j]*ty[j]);
        } else if (f>e){
            tx[j] = -sqrt(r*r - ty[j]*ty[j]);
        }
  //            tz[j] = ofRandom(-200, 300);
        
}
}
 
//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    
    
    float *data = ofSoundGetSpectrum(N);
    
    for ( int i=0; i<N; i++ ) {
        spectrum[i] *= 0.8;
        spectrum[i] = max(spectrum[i], data[i]);
    }
    
    float time = ofGetElapsedTimef();
    float dt = time - time0;
    dt = ofClamp(dt, 0.0, 0.1);
    time0 = time;
    
    move = ofMap(spectrum[specMove], 1, 3, 400, 500, true);
    vel = ofMap(spectrum[specVel], 0, 0.1, 0.05, 0.5);
    
    for (int j=0; j<n; j++) {
        tx[j] += vel * dt;
        ty[j] += vel * dt;
        pos[j].x = ofSignedNoise(tx[j]) * move;
        cout <<ofSignedNoise(tx[j]) << endl;
        pos[j].y = ofSignedNoise(ty[j]) * move;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(255),ofColor(140),OF_GRADIENT_CIRCULAR );
    ofPushMatrix();
    ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
    
    ofScale(1.6,1.6);
    ofSetColor(70);
    ofFill();
    for (int i=0; i<n; i++) {
        ofCircle(pos[i],1);
    }
   
    float dist = 45;
    for (int j=0; j<n; j++) {
        for (int k=j+1; k<n; k++) {
            if ( ofDist( pos[j].x, pos[j].y, pos[k].x, pos[k].y )
                < dist ) {
                ofLine( pos[j], pos[k] );
            }
        }
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

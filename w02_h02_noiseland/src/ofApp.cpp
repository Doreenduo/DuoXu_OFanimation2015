#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    mult = 0.001;
    noisePixels.allocate(ofGetWidth(), ofGetWidth(), OF_IMAGE_COLOR);
    
    
    ofBackground(255,255,255);
    //ofSetFrameRate(5);
    ofSetVerticalSync(true);
    
    ofEnableAlphaBlending();
    ofSetColor(255,255,255, 100);

  


}

//--------------------------------------------------------------
void ofApp::update(){

    for (int y = 0; y < ofGetHeight(); y++) {
        for (int x = 0; x < ofGetWidth(); x++) {
            ofFloatColor color = ofFloatColor(ofNoise(x*mult, y*mult));
            noisePixels.setColor(x, y, color);
        }
    }

    
    noiseImg.setFromPixels(noisePixels.getPixels(), noisePixels.getWidth(), noisePixels.getHeight(),OF_IMAGE_COLOR);
    
    
  
    
    }



//--------------------------------------------------------------
void ofApp::draw(){
    
    noiseImg.draw(0,0);
    
    ofEnableAlphaBlending();
    ofSetColor(255,255,255, 100);
    //colorScheme.draw(0,0, ofGetWidth(), ofGetHeight());
    
    ofSeedRandom(0); // always pick the same random numbers.
    
    for (int i = 0; i < mouseX*3; i++){
        float x = ofNoise(ofGetElapsedTimef()*0.2, i*0.3)*ofGetWidth();
        float y = ofNoise(-ofGetElapsedTimef()*0.2, i*0.3)*ofGetHeight();
        
          ofCircle(x,y,ofRandom(4,40));
    }


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------

void ofApp::dragEvent(ofDragInfo dragInfo){
    


}

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

        ofBackground(0);
      // ofSetColor(20, 110, 150, 100);
    
    

}

//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
//    for (int i = 1; i < 16; i++) {
//        float sinOfTime = sin (ofGetElapsedTimef()*i);
//        float x = i * 60;
//        float y = ofGetHeight()/2 + (sinOfTime * 100);
//        ofCircle(x, y, 10);
//    }
    
    
    for (int i = 1; i < 16; i++) {
        float sinOfTime = (sin (ofGetElapsedTimef()*i));
        float x = i * 60;
        float y = ofGetHeight()/2 + (sinOfTime * 100);
        
        ofSetColor(220, 100, 80, 200);
        ofCircle(x, y, 20);
        
        
    }

    for (int b = 1;  b < 16; b ++) {
    float sinOfTime = (sin (ofGetElapsedTimef()*b));
        float x = b * 150;
        float y = ofGetHeight()/2 + (sinOfTime * 100);
        
        ofSetColor(120, 200, 100, 200);
        ofRect(x, y, 25, 25);
        //ofCircle(x, y, 20);
        
    }

    for (int j = 1;  j < 16; j ++) {
        float sinOfTime = (sin (ofGetElapsedTimef()*j));
        float x = j * 100;
        float y = ofGetHeight()/2 + (sinOfTime * 100);
        
        ofSetColor(110, 120, 200, 200);
        ofRect(x, y, 20, 20);
        
    }
    
    for (int k = 1;  k < 16; k ++) {
        float sinOfTime = (sin (ofGetElapsedTimef()*k));
        float x = k * 70;
        float y = ofGetHeight()/2 + (sinOfTime * 100);
        
        ofSetColor(55, 60, 100, 220);
        ofCircle(x, y, 15);

        
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

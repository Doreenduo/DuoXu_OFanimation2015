#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    
        for (int i = 0; i < 50; i++) {
            Mover mover;
            mover.setup(ofGetWidth()/2 + ofRandom(-100,100), ofGetHeight()/2+ ofRandom(-100,100),1.0);
            moverList.push_back(mover);
        }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofVec2f mousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());
    
    for (int i = 0; i < 50; i++) {
        
        ofVec2f attraction;
        ofVec2f diff = mousePos - moverList[i].pos;
        attraction.set(diff.getNormalized() * 0.2);
        repulsion.set(attraction* -1);
        
        
        if (diff.length() < ofGetMouseX()) {
           
            moverList[i].applyForce(repulsion);

        } else {
            moverList[i].applyForce(attraction);
           // attraction.set(0);
            attraction.set(diff*0.001);
                    }
        
        moverList[i].resetForces();
        moverList[i].applyForce(attraction);
        moverList[i].applyDampingForce(0.09);
        moverList[i].checkEdges();
        moverList[i].update();
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < 50; i++) {
        moverList[i].draw();
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

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    
     myNewImage.loadImage("haha.png");
     myNewImage1.loadImage("xixi.png");
    
    
     myNewImage.resize(myNewImage.width* 0.25, myNewImage.height*0.25);
     myNewImage1.resize(myNewImage.width* 2.3, myNewImage.height* 2.3 );
}

//--------------------------------------------------------------
void ofApp::update(){

    float sinOfTime = sin(ofGetElapsedTimef());
    size = ofMap(sinOfTime, -1, 1, 100, 300);
  

}

//--------------------------------------------------------------
void ofApp::draw(){


        myNewImage1.draw(300, 70);
        myNewImage.draw(550, 300 , size, size);

    

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

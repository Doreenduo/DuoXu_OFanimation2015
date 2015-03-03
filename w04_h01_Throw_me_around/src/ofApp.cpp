#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    mover.setup(ofGetMouseX(),ofGetMouseY(),3);
    moverTwo.setup(ofGetMouseX(),ofGetMouseY(),8);
    moverThree.setup(ofGetMouseX(),ofGetMouseY(),6);
    moverFour.setup(ofGetMouseX(),ofGetMouseY(),9);
    moverFive.setup(ofGetMouseX(),ofGetMouseY(),5);
    
    gravity.set(0,0.5);
    wind.set(0.1,0);
    
    Throw = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    mover.resetForces();
    mover.applyForce(gravity * mover.mass);
    mover.applyForce(wind);
    mover.applyDampingForce( 0.05 );
    mover.update();

    
    moverTwo.resetForces();
    moverTwo.applyForce(gravity * mover.mass);
    moverTwo.applyForce(wind);
    moverTwo.applyDampingForce( 0.03 );
    moverTwo.update();

    
    moverThree.resetForces();
    moverThree.applyForce(gravity * mover.mass);
    moverThree.applyForce(wind);
    moverThree.applyDampingForce( 0.10 );
    moverThree.update();

    
    moverFour.resetForces();
    moverFour.applyForce(gravity * mover.mass);
    moverFour.applyForce(wind);
    moverFour.applyDampingForce( 0.08 );
    moverFour.update();

    
    moverFive.resetForces();
    moverFive.applyForce(gravity * mover.mass);
    moverFive.applyForce(wind);
    moverFive.applyDampingForce( 0.06 );
    moverFive.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
   //ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255),ofRandom(255));
    mover.draw();
    
   //ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
    moverTwo.draw();
    
   // ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
    moverThree.draw();
    
   // ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255),ofRandom(255));
    moverFour.draw();
    
   // ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
    moverFive.draw();
    
    if (ofGetMousePressed()) {
       ofLine(throwBegin.x, throwBegin.y, ofGetMouseX(), ofGetMouseY());
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
    
    if (!Throw) {
        throwBegin.set(ofGetMouseX(), ofGetMouseY());
        Throw = true;
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    
    mover.pos.set(ofGetMouseX(), ofGetMouseY());
    ofVec2f throwVec;
    
    throwVec.x = ofGetMouseX() - throwBegin.x;
    throwVec.y = ofGetMouseY() - throwBegin.y;
    
    mover.vel = throwVec*0.1;
    Throw = false;
    
    
    moverTwo.pos.set(ofGetMouseX()+73, ofGetMouseY()+6);
    moverTwo.vel = throwVec*0.7;
   
    
    moverThree.pos.set(ofGetMouseX()+10, ofGetMouseY()+70);
    moverThree.vel = throwVec*0.2;
   // Throw = true;
    
    moverFour.pos.set(ofGetMouseX()+76, ofGetMouseY()+57);
    moverFour.vel = throwVec*0.3;
    //Throw = false;
    
    moverFive.pos.set(ofGetMouseX()+56, ofGetMouseY()+86);
    moverFive.vel = throwVec*0.4;
    //Throw = false;

    
    
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


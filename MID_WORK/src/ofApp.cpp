#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
   colorScheme.loadImage("sunset.png");
    
    ofBackground(255);
    
    // particle
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    ofVec2f pos;
    pos.set(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    
    //----------------------------
    bParticle1 = false;
    bParticle2 = false;
    bParticle3 = false;
    
    particle3_Timer = 0;


  
    
 ////////////////////////////  audio  ////////////////////////////////
    
 
    soundStream.listDevices();
    
    //if you want to set a different device id
    //soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    
    int bufferSize = 256;
    
    volHistory.assign(400, 0.0);
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter	= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    drawCounter		= 0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 2);

    
    
    
}



//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    //particle
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        if(beats.getIsPlaying()==false) {
            particles[i].addForce(0.0, 0.28);
            particles[i].addDampingForce();
        }
        
        particles[i].bounceOffWalls();
        particles[i].update();
        particles[i].timer ++;
        colors1[i].a = ofMap(particles[i].timer, 0, 250, 255, 0, true);
        
        if (particles[i].timer > 200) {
            particles.erase(particles.begin()+i);
        }
    }
    
    // update the sound playing system:
  //  ofSoundUpdate();
    
    //fangxing
    for (int i = 0; i < particles2.size(); i++){
        particles2[i].resetForce();
        if(vocals.getIsPlaying()==false){
            particles2[i].addDampingForce();
        }
        
        particles2[i].update();
        particles2[i].timer ++;
        colors2[i].a = ofMap(particles2[i].timer, 0, 500, 255, 0, true);
        
        if (particles2[i].timer > 450) {
            particles2.erase(particles2.begin()+i);
        }
    }
    
    
    
 
     ////////////////////////////  audio  ////////////////////////////////
    
    
    
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    //Record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger then the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }

    




///////////////////////////////////////////////////////////////////////////////


if ( scaledVol <= 0.05 && scaledVol > 0.043 ){
    
    
    
    ofPoint pos(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    
    for (int i = 0; i < 20; i++){
        particle myParticle;
        myParticle.setInitialCondition(pos.x,pos.y,ofRandom(-10,10), ofRandom(-10,10));
        myParticle.size = 25;
        myParticle.timer = 0;
        myParticle.bFill = true;
        ofColor myColor;
        myColor.set(ofRandom(230), ofRandom(100), ofRandom(100),100);
        colors1.push_back(myColor);
        particles.push_back(myParticle);
    }
}


if ( scaledVol <= 0.18 && scaledVol > 0.1 ){
    
    
    
    ofPoint pos(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    
    for (int i = 0; i < 10; i++){
        particle myParticle2;
        float vx = ofRandom(-4,4);
        float vy = ofRandom(-4,4);
        myParticle2.timer = 0;
        myParticle2.bFill = false;
        myParticle2.setInitialCondition(pos.x,pos.y,vx, vy);
        ofColor myColor2;
        myColor2.set(ofRandom(100), ofRandom(210), ofRandom(200),160);
        colors2.push_back(myColor2);
        particles2.push_back(myParticle2);
    }
}



if ( scaledVol <= 0.5 && scaledVol > 0.25){
    
      bParticle3 = true;
    

}
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    //fangxing
    for (int i = 0; i < particles2.size(); i++){
        if (!particles2[i].bFill) {
            ofNoFill();
        }
        ofSetColor(colors2[i]);
        ofRect(particles2[i].pos.x, particles2[i].pos.y, 50, 50);
    }
    
    
    if (bParticle3) {
        ofFill();
        
        ofSeedRandom(0);
        
        for (int i = 0; i < 150; i++){
            float x = ofNoise(ofGetElapsedTimef()*0.2, i*0.3)*ofGetWidth();
            float y = ofNoise(-ofGetElapsedTimef()*0.2, i*0.3)*ofGetHeight();
            
            ofColor col = getColorForPixel(ofMap(x,0,ofGetWidth(), 0, colorScheme.width),
                                           ofMap(y,0,ofGetHeight(), 0, colorScheme.height));
            
            col.a = ofMap(particle3_Timer, 500, 0, 0, 80, true);	// set some alpha.
            ofSetColor(col);
            ofCircle(x,y,ofRandom(4,35));
        }
        
        particle3_Timer ++;
        if (particle3_Timer>500) {
            bParticle3 = false;
            particle3_Timer = 0;
        }
    }
    
    
    // particle
    for (int i = 0; i < particles.size(); i++){
        ofFill();
        ofSetColor(colors1[i]);
        ofSetCircleResolution(ofRandom(3,8));
        ofCircle(particles[i].pos.x, particles[i].pos.y, particles[i].size);
    }
    
    
}


//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
   
    
    
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

ofColor ofApp::getColorForPixel(int x, int y){
    
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= colorScheme.width) x = colorScheme.width-1;
    if (y >= colorScheme.height) y = colorScheme.height-1;
    
    return colorScheme.getColor(x,y);
}

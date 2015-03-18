//#ifndef _TEST_APP
//#define _TEST_APP
#pragma once

#include "ofMain.h"

#include "particle.h"

#include "particleOne.h"



class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    ofSoundPlayer  beats;
    ofSoundPlayer  synth;
    ofSoundPlayer  vocals;
    
    float synthPosition;
    
    
    float threshold;
    ofVideoPlayer movie;
    
    bool showLabels;
    
    float x,y;
    
    
    
private:
    
    void setupArduino(const int & version);
    void digitalPinChanged(const int & pinNum);
    void analogPinChanged(const int & pinNum);
    void updateArduino();
    
    string buttonState;
    string potValue;
    
    // let's make a vector of them
    vector <particle> particles;
    vector <particle> particles2;
    
    vector <ofColor> colors1;
    vector <ofColor> colors2;
    vector <ofColor> colors3;
    
    bool  bParticle1;
    bool  bParticle2;
    bool  bParticle3;
    
    // shape 3
    float position;
    ofImage colorScheme;
    ofColor getColorForPixel(int x, int y);
    int  particle3_Timer;
    
    
    
    
    
    
    ////////////////////////////  audio  ////////////////////////////////
    
    
    void audioIn(float * input, int bufferSize, int nChannels);
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int 	bufferCounter;
    int 	drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;
    
    
    
    
    
};
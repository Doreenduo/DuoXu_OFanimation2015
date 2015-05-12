#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "Particle1.h"
#include "Particle2.h"
#include "Particle3.h"

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
    
    bool bFill;
    bool bWireframe;
    bool bInfoText;
    bool bSplitFaces;
    
    ofImage texture;
    ofVideoGrabber vidGrabber;
    int mode;
    
   // ofSpherePrimitive sphere;
    ofIcoSpherePrimitive icoSphere;
    ofIcoSpherePrimitive icoSphereR;
    ofIcoSpherePrimitive icoSphereU;
    ofIcoSpherePrimitive icoSphereD;
    
    ofMaterial material;

    
    
    
    //audio reference to sound example
    void audioIn(float * input, int bufferSize, int nChannels);
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int bufferCounter;
    int drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;
    
    vector<Particle> particleList;
    
    vector<Particle1> particleListT;
    
    vector<Particle2> particleListD;
    
    vector<Particle3> particleListL;
    
    ofVec2f pos, size;
    ofVec2f force;
    ofColor color;
    ofVec2f vel;
    
    };

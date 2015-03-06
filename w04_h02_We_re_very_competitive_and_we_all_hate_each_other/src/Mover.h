

#pragma once

#include "ofMain.h"

class Mover {
public:
    
    void setup(float x, float y, float _mass);
    void update();
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    void checkEdges();
    void draw();
    
    ofVec2f pos, vel, acc;
    float mass;
    
    
    ofColor circleColor;
    
    float size, alpha;
};
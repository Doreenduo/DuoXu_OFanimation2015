
//
//  Mover.h
//  w04_h01_Throw_me_around
//
//  Created by XuDuo on 15/3/2.
//
//
#pragma once
#include "ofMain.h"


class Mover{
public:
    
    void setup(float x, float y, float _mass);
    void update();
    
    void resetForces();
    void applyForce (ofVec2f force);
    void applyDampingForce(float damping);
    void draw();
    
    ofVec2f pos, vel ,acc;
    
    float mass;
    float size, alpha;
    
    ofColor circleColor;
    
    
};

//
//  Mover.h
//  w04_h02_We_re_very_competitive_and_we_all_hate_each_other
//
//  Created by XuDuo on 15/3/2.
//
//


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
    
};
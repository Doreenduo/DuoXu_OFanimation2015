
//
//  Particle.h
//  w05_h01_Code_fireworks
//
//  Created by XuDuo on 15/3/6.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    
    Particle();
    
    void setup();
    
    void resetForces();
    void applyForce(ofVec2f force);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    float lifespan;
    
     ofColor circleColor;
    
};

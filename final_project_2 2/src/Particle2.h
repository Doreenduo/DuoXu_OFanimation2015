//
//  Particle2.h
//  final_project_2
//
//  Created by XuDuo on 15/5/12.
//
//

#pragma once
#include "ofMain.h"

class Particle2{
public:
    
    Particle2(ofVec2f , float xx, float xy);
    
    void setup();
    void resetForce();
    void applyForce(ofVec2f force);
    
    void update(ofVec2f myPos);
    void draw(ofColor _color);
    
    ofVec2f pos, vel, acc;
    float lifespan;
    float size;
    
    float rad;
    float pct;
    
    
};
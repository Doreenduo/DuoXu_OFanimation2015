//
//  Particle1.cpp
//  final_project_2
//
//  Created by XuDuo on 15/5/12.
//
//

#include "Particle1.h"

Particle1::Particle1(ofVec2f , float xx, float xy){
    
    pos.set(510,610);  // Down
    
    vel.set(xx, xy);
    lifespan = ofRandom(120, 120);
    size = ofRandom(10, 10);
}

void Particle1::setup(){
    
}

void Particle1::resetForce(){
    
    acc *= 0;
}

void Particle1::applyForce(ofVec2f force){
    
    acc += force;
}

void Particle1::update(ofVec2f myPos){
    
    vel += acc;
    // pos += vel;
    pos =(pos*(1-pct) + myPos* pct) + vel;
    
    if(lifespan>0) {
        lifespan -= 3.0;
    }
}

void Particle1::draw(ofColor _color){
    
    ofSetColor(_color, lifespan);
    //ofCircle(25,26, size);
    
}


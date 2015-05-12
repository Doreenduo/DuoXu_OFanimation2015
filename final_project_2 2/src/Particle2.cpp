//
//  Particle2.cpp
//  final_project_2
//
//  Created by XuDuo on 15/5/12.
//
//

#include "Particle2.h"


Particle2::Particle2(ofVec2f , float xx, float xy){
    
    pos.set(510,150); // up
    
    vel.set(xx, xy);
    lifespan = ofRandom(120, 120);
    size = ofRandom(10, 10);
}

void Particle2::setup(){
    
}

void Particle2::resetForce(){
    
    acc *= 0;
}

void Particle2::applyForce(ofVec2f force){
    
    acc += force;
}

void Particle2::update(ofVec2f myPos){
    
    vel += acc;
    // pos += vel;
    pos =(pos*(1-pct) + myPos* pct) + vel;
    
    if(lifespan>0) {
        lifespan -= 3.0;
    }
}

void Particle2::draw(ofColor _color){
    
    ofSetColor(_color, lifespan);
    //ofCircle(25,26, size);
    
}
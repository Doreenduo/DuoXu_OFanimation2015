//
//  Particle.cpp
//  final_project_2
//
//  Created by XuDuo on 15/5/12.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f _pos, float xx, float xy){
    
    pos.set(754,380);
    
    vel.set(xx, xy);
    lifespan = ofRandom(120, 120);
    size = ofRandom(10, 10);
}

void Particle::setup(){
    
}

void Particle::resetForce(){
    
    acc *= 0;
}

void Particle::applyForce(ofVec2f force){
    
    acc += force;
}

void Particle::update(ofVec2f myPos){
    
    vel += acc;
   // pos += vel;
    pos =(pos*(1-pct) + myPos* pct) + vel;
    
    if(lifespan>0) {
        lifespan -= 3.0;
    }
}

void Particle::draw(ofColor _color){
    
    ofSetColor(_color, lifespan);
    //ofCircle(25,26, size);
    
}


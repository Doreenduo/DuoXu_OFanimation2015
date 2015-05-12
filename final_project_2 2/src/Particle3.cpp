//
//  Particle3.cpp
//  final_project_2
//
//  Created by XuDuo on 15/5/12.
//
//

#include "Particle3.h"


Particle3::Particle3(ofVec2f , float xx, float xy){
    
    pos.set(260,380);
    
    vel.set(xx, xy);
    lifespan = ofRandom(120, 120);
    size = ofRandom(10, 10);
}

void Particle3::setup(){
    
}

void Particle3::resetForce(){
    
    acc *= 0;
}

void Particle3::applyForce(ofVec2f force){
    
    acc += force;
}

void Particle3::update(ofVec2f myPos){
    
    vel += acc;
    // pos += vel;
    pos =(pos*(1-pct) + myPos* pct) + vel;
    
    if(lifespan>0) {
        lifespan -= 3.0;
    }
}

void Particle3::draw(ofColor _color){
    
    ofSetColor(_color, lifespan);
    //ofCircle(25,26, size);
    
}
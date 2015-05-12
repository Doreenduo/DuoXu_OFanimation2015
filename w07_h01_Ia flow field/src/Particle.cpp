//
//  Particle.cpp
//  03_flowField
//
//  Created by Bernardo Santos Schorr on 3/31/15.
//
//

#include "Particle.h"

void Particle::setup() {
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    
    ofSetVerticalSync(true);
    colorScheme.loadImage("sunset.png");
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}

void Particle::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void Particle::update() {
    vel += acc;
    pos += vel;
    
}

void Particle::draw() {
    
    ofEnableAlphaBlending();
    ofSetColor(255,255,255, 100);

    
    ofSeedRandom(0);
    
    for (int i = 0; i < 100; i++){
        float x = ofNoise(ofGetElapsedTimef()*0.2, i*0.3)*ofGetWidth();
        float y = ofNoise(-ofGetElapsedTimef()*0.2, i*0.3)*ofGetHeight();
        
        ofColor col = getColorForPixel(ofMap(x,0,ofGetWidth(), 0, colorScheme.width),
                                       ofMap(y,0,ofGetHeight(), 0, colorScheme.height));
        
        col.a = 85;	// set some alpha. 
        ofSetColor(col);
       ofCircle(x,y,ofRandom(4,40));
}
    
}

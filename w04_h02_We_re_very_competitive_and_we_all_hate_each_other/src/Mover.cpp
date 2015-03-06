

#include "Mover.h"

void Mover::setup(float x, float y, float _mass) {
    pos.set(x, y);
    
    circleColor.set(ofRandom(255), ofRandom(255), ofRandom(255));
    
    mass = _mass;
}

void Mover::resetForces() {
    acc *= 0;
}

void Mover::applyForce(ofVec2f force) {

    acc += force / mass;
}

void Mover::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void Mover::update() {
    
    vel += acc;
    pos += vel;
    
    float sinOfTime = sin(ofGetElapsedTimef());
    size = ofMap(sinOfTime, -1, 1, 6, 50);
    alpha = ofMap(sinOfTime, -1, 1, 250, 40);
    
}

void Mover::checkEdges() {
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }
    
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
}

void Mover::draw() {
    ofCircle(pos, size);
    ofSetColor(circleColor,alpha);
}
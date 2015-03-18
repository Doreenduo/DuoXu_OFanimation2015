#pragma once
#include "ofMain.h"

class Bullet {

public:
    
    ofVec2f pos, vel;
    bool    bRemove;
   /////////
    ofImage bullet;
    float 	counter;
    
    void setup(){
       bullet.loadImage("2.png");
        counter = 0.2;
    }
    
    void update() {
        pos += vel;
        vel *= 0.99; // slowdown in a long time
        
        counter = counter + 0.033f;
    }
    
    void draw() {
        
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
        float radius = 5 + sin(counter);
        ofCircle(pos,radius);
      
    }
    
};

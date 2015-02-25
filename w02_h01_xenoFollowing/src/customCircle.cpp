//
//  customCircle.cpp
//  01_xenoFollowing
//
//  Created by XuDuo on 15/2/10.
//
//

#include "customCircle.h"


void customCircle::setup(){
    
    pos.set(0,0);
   circleColor.set(ofRandom(223), ofRandom(155), ofRandom(225), ofRandom(60));
    
    
    for (int y = 0; y<5; y++) {
        ofCircle(pos,y);
    }


}

void customCircle::update(ofVec2f _dest){
    
    pos = pos *0.9+ _dest * 0.1;
    

    
}

void customCircle::draw(){
    
    
    for (int y = 0; y< pos.x; y++) {
        ofCircle(pos,y/10);
    }

    // ofCircle(pos,20);
   // ofRect(pos.x, pos.y, 25, 25);
    ofSetColor(circleColor);
    
 // ofEllipse(pos.x, pos.y, 30, 10);
    
}

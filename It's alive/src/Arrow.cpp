//
//  Arrow.cpp
//  Look_at_me
//
//  Created by XuDuo on 15/2/21.
//
//


#include "Arrow.h"


void Arrow::setup (){
    pos.set(0);
}

void Arrow::update(float _x, float _y){
    
    ofVec2f newPos;
    newPos.set(_x,_y);
    pos = pos * 0.97 + newPos * 0.03;
    
    ofVec2f diff;
    diff = newPos - pos;
    rot = atan2(diff.y, diff.x);
    rot = ofRadToDeg(rot);
   
    
}

void Arrow::draw(){
    float x1 = 0;
    float y1 = -10;
    
    float x2 = 0;
    float y2 = 10;
    
    float x3 = 30;
    float y3 = 0;
    
    
    /////////
    
    float x4 = 0;
    float y4 = -10;
    
    float x5 = 0;
    float y5 = 10;
    
    float x6 = 30;
    float y6 = 0;

    
    ofTranslate(pos);
    ofRotate(rot);
    ofTriangle(x1, y1 , x2 , y2 , x3 , y3);
}


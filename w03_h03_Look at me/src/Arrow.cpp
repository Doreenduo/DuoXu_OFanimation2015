//
//  Arrow.cpp
//  13_atan
//
//  Created by XuDuo on 15/2/17.
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
    
    

    
    
    //////
    
    float sinOfTime = sin(ofGetElapsedTimef());
    float x1 = ofMap(sinOfTime, -1, 1, 0, 200);
    float y1 = ofMap(sinOfTime, -1, 1, 100, 300);
    
    float x2 = ofMap(sinOfTime, -1, 1, 0, 260);
    float y2 = ofMap(sinOfTime, -1, 1, 60, 260);
    
    float x3 = 30;
    float y3 = 30;
    
   /////
    
    float x4 = ofMap(sinOfTime, -1, 1, 0, 200);
    float y4 = ofMap(sinOfTime, -1, 1, -100, -300);
    
    float x5 = ofMap(sinOfTime, -1, 1, -0, 260);
    float y5 = ofMap(sinOfTime, -1, 1, -60, -260);
    
    float x6 = 30;
    float y6 = -30;
    
    
    ////
    
    
    float x7 = -30;
    float y7 = -5;
    
    
    float x8 = -30;
    float y8 = -5;
    
    float x9 = 30;
    float y9 = -5;
    
    
    ofSetColor(ofRandom(255), 0, 0);
    ofTranslate(pos);
    ofRotate(rot);
    ofTriangle(x1, y1 , x3 , y3 , x2 , y2);
    ofTriangle(x5, y5 , x4 , y4 , x6 , y6);
    
    
    ofRect(x7 + 30, y7-5 , 60 , 10);
    
    
    ofCircle(x8, y8, 40 );
    ofCircle(x9, y9, 25 );

}


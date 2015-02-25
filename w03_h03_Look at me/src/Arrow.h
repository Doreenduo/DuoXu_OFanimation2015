//
//  Arrow.h
//  13_atan
//
//  Created by XuDuo on 15/2/17.
//
//

#ifndef ___3_atan__Arrow__
#define ___3_atan__Arrow__

#include <stdio.h>

#endif /* defined(___3_atan__Arrow__) */


#include "ofMain.h"

class Arrow {
    
public:
    
    void setup();
    void update( float _x, float _y);
    void draw();
    
    ofVec2f  pos;
    float   rot;
    
    
    
    

};
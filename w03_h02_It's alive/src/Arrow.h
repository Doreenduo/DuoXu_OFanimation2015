//
//  Arrow.h
//  Look_at_me
//
//  Created by XuDuo on 15/2/21.
//
//

#ifndef __Look_at_me__Arrow__
#define __Look_at_me__Arrow__

#include <stdio.h>

#endif /* defined(__Look_at_me__Arrow__) */


#include "ofMain.h"

class Arrow {
    
public:
    
    void setup();
    void update( float _x, float _y);
    void draw();
    
    ofVec2f  pos;
    float   rot;
    
};
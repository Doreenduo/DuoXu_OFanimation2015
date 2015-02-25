//
//  customCircle.h
//  01_xenoFollowing
//
//  Created by XuDuo on 15/2/10.
//
//

#ifndef ___1_xenoFollowing__customCircle__
#define ___1_xenoFollowing__customCircle__

#include <stdio.h>

#endif /* defined(___1_xenoFollowing__customCircle__) */


#include "ofMain.h"

class customCircle{
    
public:
    void setup();
    void update(ofVec2f _dest);
    void draw();
    
    ofVec2f pos;
   
    ofColor circleColor;
    
    int i;
   
    
 
      };
//
//  particle.h
//  MID_WORK
//
//  Created by XuDuo on 15/3/17.
//
//

#ifndef __MID_WORK__particle__
#define __MID_WORK__particle__

#include <stdio.h>

#endif


#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
public:
    
    float   timer;
    float   size;
    bool    bFill;
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    particle();
    virtual ~particle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    
    void bounceOffWalls();
    
    
    float damping;
    
protected:
private:
    
    //point as textures
    void addPoint(float x, float y, float z);
    
    // vector to store all values
    vector <ofVec3f> points;
    vector <ofVec3f> sizes;
    
    ofVbo vbo;
    ofShader shader;
    ofEasyCam camera;
    
    float camDist;
    
    ofTexture texture;
    
    
};

#endif // PARTICLE_H


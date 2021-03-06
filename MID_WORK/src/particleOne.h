#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particleOne
{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    particleOne();
    virtual ~particleOne(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    
    float damping;
    
protected:
private:
};

#endif // PARTICLE_H

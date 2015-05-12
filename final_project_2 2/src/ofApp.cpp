#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofBackground(0);
    
    texture.loadImage("of.png");
    
   
    bWireframe  = true;
    bInfoText   = true;

    
    float width     = ofGetWidth()/2 * .12;
    float height    = ofGetHeight()/2 * .12;
    
    icoSphere.setRadius( width );
    icoSphereR.setRadius( width );
    icoSphereU.setRadius( width );
    icoSphereD.setRadius( width );
    
        
    
    // aduio part
   
    soundStream.listDevices();
    int bufferSize = 256;
    volHistory.assign(400, 0.0);
    left.assign(bufferSize, 10.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    bufferCounter = 0;
    smoothedVol = 0.0;
    scaledVol = 0.0;
    drawCounter = 0;
    soundStream.setup(this, 0, 2, 44100, bufferSize, 12);

}

//--------------------------------------------------------------
void ofApp::update() {

    
    // aduino part
    scaledVol = ofMap(smoothedVol, 0.0, 0.16, 0.0, 1.0, true);
    volHistory.push_back(scaledVol);
    
    for (int i=0; i<particleList.size(); i++){
        
        particleList[i].resetForce();
        particleList[i].applyForce(force);
        //particleList[i].applyForce(repulsion);
        particleList[i].pct = 0.05f;
        particleList[i].update(particleList[i-1].pos);
        
    }
    
    
    for (int i=0; i<particleListT.size(); i++){
        
        particleListT[i].resetForce();
        particleListT[i].applyForce(force);
        //particleListT[i].applyForce(repulsion);
        particleListT[i].pct = 0.05f;
        particleListT[i].update(particleListT[i-1].pos);
        
    }

    
    for (int i=0; i<particleListD.size(); i++){
        
        particleListD[i].resetForce();
        particleListD[i].applyForce(force);
        //particleListD[i].applyForce(repulsion);
        particleListD[i].pct = 0.05f;
        particleListD[i].update(particleListD[i-1].pos);
        
    }

    
    for (int i=0; i<particleListL.size(); i++){
        
        particleListL[i].resetForce();
        particleListL[i].applyForce(force);
        //particleListL[i].applyForce(repulsion);
        particleListL[i].pct = 0.05f;
        particleListL[i].update(particleListL[i-1].pos);
        
    }


}

//--------------------------------------------------------------
void ofApp::draw() {
    
    // aduino part
    //volume controls size, color and shape
    for (int i=0; i<particleList.size(); i++){
    
        if( scaledVol <= 0.3 && scaledVol > 0.0){
            
            color.set(221, 255, 252);
            ofSetCircleResolution(3);
            force.set(scaledVol*0.1);
        }
        
        if(scaledVol <= 0.6 && scaledVol > 0.2){
            
            color. set(150,150, 255);
            ofSetCircleResolution(6);
            force.set(scaledVol*0.5);
        }
        
        if(scaledVol <= 0.8 && scaledVol > 0.4){
            
            color.set(180, 230, 255);
            ofSetCircleResolution(4);
            force.set(scaledVol*0.9);
        }
        
        if(scaledVol <= 1.0 && scaledVol > 0.6){
            
            color.set(237, 237, 255);
            ofSetCircleResolution(10);
            force.set(scaledVol*1.2);
        }
        
        particleList[i].draw(color);
        ofLine(particleList[i].pos, particleList[i-1].pos);
    }
    
    
    for (int i=0; i<particleListT.size(); i++){
        
        if( scaledVol <= 0.3 && scaledVol > 0.0){
            
            color.set(221, 255, 252);
            ofSetCircleResolution(3);
            force.set(scaledVol*0.1);
        }
        
        if(scaledVol <= 0.6 && scaledVol > 0.2){
            
            color. set(150,150, 255);
            ofSetCircleResolution(6);
            force.set(scaledVol*0.5);
        }
        
        if(scaledVol <= 0.8 && scaledVol > 0.4){
            
            color.set(180, 230, 255);
            ofSetCircleResolution(4);
            force.set(scaledVol*0.9);
        }
        
        if(scaledVol <= 1.0 && scaledVol > 0.6){
            
            color.set(237, 237, 255);
            ofSetCircleResolution(10);
            force.set(scaledVol*1.2);
        }
        
        particleListT[i].draw(color);
        ofLine(particleListT[i].pos, particleListT[i-1].pos);
    }
    
    
    for (int i=0; i<particleListD.size(); i++){
        
        if( scaledVol <= 0.3 && scaledVol > 0.0){
            
            color.set(221, 255, 252);
            ofSetCircleResolution(3);
            force.set(scaledVol*0.1);
        }
        
        if(scaledVol <= 0.6 && scaledVol > 0.2){
            
            color. set(150,150, 255);
            ofSetCircleResolution(6);
            force.set(scaledVol*0.5);
        }
        
        if(scaledVol <= 0.8 && scaledVol > 0.4){
            
            color.set(180, 230, 255);
            ofSetCircleResolution(4);
            force.set(scaledVol*0.9);
        }
        
        if(scaledVol <= 1.0 && scaledVol > 0.6){
            
            color.set(237, 237, 255);
            ofSetCircleResolution(10);
            force.set(scaledVol*1.2);
        }
        
        particleListD[i].draw(color);
        ofLine(particleListD[i].pos, particleListD[i-1].pos);
    }
    
    for (int i=0; i<particleListL.size(); i++){
        
        if( scaledVol <= 0.3 && scaledVol > 0.0){
            
            color.set(221, 255, 252);
            ofSetCircleResolution(3);
            force.set(scaledVol*0.1);
        }
        
        if(scaledVol <= 0.6 && scaledVol > 0.2){
            
            color. set(150,150, 255);
            ofSetCircleResolution(6);
            force.set(scaledVol*0.5);
        }
        
        if(scaledVol <= 0.8 && scaledVol > 0.4){
            
            color.set(180, 230, 255);
            ofSetCircleResolution(4);
            force.set(scaledVol*0.9);
        }
        
        if(scaledVol <= 1.0 && scaledVol > 0.6){
            
            color.set(237, 237, 255);
            ofSetCircleResolution(10);
            force.set(scaledVol*1.2);
        }
        
        particleListL[i].draw(color);
        ofLine(particleListL[i].pos, particleListL[i-1].pos);
    }

    
    
    
    
    float spinX = sin(ofGetElapsedTimef()*.35f);
    float spinY = cos(ofGetElapsedTimef()*.075f);
    
    material.begin();
    
    ofSetColor(180);
    ofNoFill();
  
    // ICO Sphere //
    icoSphere.setPosition(ofGetWidth()*.74, ofGetHeight()*.50, 0); // right
    icoSphere.rotate(spinX, 1.0, 1.0, 0.0);
    icoSphere.rotate(spinY, 0, 0.0, 0.0);
    
    icoSphereD.setPosition(ofGetWidth()*.26, ofGetHeight()*.50, 0); //left
    icoSphereD.rotate(spinX, 1.0, 0.0, 0.0);
    icoSphereD.rotate(spinY, 0, 1.0, 0.0);
    
    
    icoSphereR.setPosition(ofGetWidth()*.50, ofGetHeight()*.20, 0);  //shang
    icoSphereR.rotate(spinX, 0, 0.0, 0.0);
    icoSphereR.rotate(spinY, 1.0, 1.0, 0.0);
    
    
    icoSphereU.setPosition(ofGetWidth()*.50, ofGetHeight()*.80, 0); // xia
    icoSphereU.rotate(spinX, 0, 1.0, 0.0);
    icoSphereU.rotate(spinY, 1.0, 0.0, 0.0);
 
    
    if(bFill) {

        icoSphere.draw();
        icoSphereR.draw();
        icoSphereU.draw();
        icoSphereD.draw();
    }
    
    
    if(bWireframe) {
        ofNoFill();
        ofSetColor(0, 0, 0);
        if(!bFill) ofSetColor(255);
        
        
        icoSphere.setScale(1.01f);
        icoSphere.drawWireframe();
        icoSphere.setScale(1.f);
        
        icoSphereR.setScale(1.01f);
        icoSphereR.drawWireframe();
        icoSphereR.setScale(1.f);
        
        
        icoSphereU.setScale(1.01f);
        icoSphereU.drawWireframe();
        icoSphereU.setScale(1.f);

        
        icoSphereD.setScale(1.01f);
        icoSphereD.drawWireframe();
        icoSphereD.setScale(1.f);
    }
    
    
    if(mode == 1 ) texture.getTextureReference().unbind();
       
    material.end();
    
    ofSetColor(0);
    ofRect(icoSphere.getPosition().x-154, icoSphere.getPosition().y + 120, 100, 20);
    ofRect(icoSphereR.getPosition().x-154, icoSphere.getPosition().y + 120, 150, 20);
    ofRect(icoSphereU.getPosition().x-154, icoSphere.getPosition().y + 120, 100, 20);
    ofRect(icoSphereD.getPosition().x-154, icoSphere.getPosition().y + 120, 100, 20);
    
   }



//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    int numCounted = 0;
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    curVol /= (float)numCounted;
    curVol = sqrt( curVol );
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    bufferCounter++;
    
    //draw particle
    float angle = ofRandom(0, 2*PI);
    float rad = ofRandom(scaledVol*20.0f, scaledVol*50.0f);
    float xx = rad*cos(angle);
    float xy = rad*sin(angle);
    Particle p(ofVec2f(ofGetWindowSize()/2), xx, xy);
    particleList.push_back(p);
    
    Particle1 p1(ofVec2f(ofGetWindowSize()/2), xx, xy);
    particleListT.push_back(p1);
    
    
    Particle2 p2(ofVec2f(ofGetWindowSize()/2), xx, xy);
    particleListD.push_back(p2);
    
    Particle3 p3(ofVec2f(ofGetWindowSize()/2), xx, xy);
    particleListL.push_back(p3);
    

    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    switch(key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 's':
            bFill = !bFill;
            break;
        case '1':
            bSplitFaces=true;
            // icosahedron //
            icoSphere.setResolution(0); // number of subdivides //
            icoSphereR.setResolution(0);
            icoSphereU.setResolution(0);
            icoSphereD.setResolution(0);
            break;
        case '2':
            bSplitFaces=false;
            icoSphere.setResolution(1);
            icoSphereR.setResolution(1);
            icoSphereU.setResolution(1);
            icoSphereD.setResolution(1);
            break;
        case '3':
            bSplitFaces=false;
            icoSphere.setResolution(2);
            icoSphereR.setResolution(2);
            icoSphereU.setResolution(2);
            icoSphereD.setResolution(2);
            break;
        case 't':
            bInfoText=!bInfoText;
            break;

    }
    
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

#include "ofApp.h"
#include "ofxTablet.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(10,10,10);
    ofEnableDepthTest();
    light.setPosition(100, -50, 100);
    
    cam.move(0,-600,200);
    cam.lookAt(ofVec3f(0,0,0));
    
    tabmtx = ofMatrix4x4::newIdentityMatrix();
    gridsize = 500;
    
    ofxTablet::start();
    
    // if you want to get data events, you can add a listener to ofxTablet::tabletEvent
	ofAddListener(ofxTablet::tabletEvent, this, &ofApp::tabletMoved);
}

//--------------------------------------------------------------
void ofApp::update(){
    
 

}

//--------------------------------------------------------------
void ofApp::draw(){
    float gridsize = 500;
    
    cam.begin();
    
    ofDrawGrid(gridsize/2.0, 8.0f, false, false, false, true);
    
    ofPushMatrix();
   
    ofMultMatrix(tabmtx);
    
    ofDrawAxis(30);
    
    ofEnableLighting();
    light.enable();
    
    ofPushMatrix();
    ofRotateX(90);
    ofDrawCylinder(0,52,0,3,100);
    ofPopMatrix();
    
    // you can also get global tablet data at any time
    TabletData& data = ofxTablet::tabletData;
    float p= data.pressure*25;
    if (p<10) p = 10;
    
    ofDrawArrow(ofVec3f(0,0,100), ofVec3f(0,0,0), p);

    ofDisableLighting();

    ofPopMatrix();
    
    cam.end();
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

// get data as soon as it comes in
void ofApp::tabletMoved(TabletData &data) {
    
    // set up coordinate frame based on tablet data
    ofVec3f translate((data.abs_screen[0]-0.5)*gridsize,(data.abs_screen[1]-0.5)*gridsize, 0);
    ofVec3f tilt(data.tilt_vec[0], data.tilt_vec[1], data.tilt_vec[2]);
    ofQuaternion tiltquat;
    tiltquat.makeRotate(ofVec3f(0,0,1), tilt);
    
    tabmtx.setRotate(tiltquat);
    tabmtx.setTranslation(translate);
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
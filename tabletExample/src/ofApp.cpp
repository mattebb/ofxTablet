#include "ofApp.h"
#include "ofxTablet.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofxTablet::start();
    
    // if you want to get data events, you can add a listener to ofxTablet::tabletEvent
	ofAddListener(ofxTablet::tabletEvent, this, &ofApp::tabletMoved);

    
    // this uses depth information for occlusion
	// rather than always drawing things on top of each other
	ofEnableDepthTest();
	
	// ofBox uses texture coordinates from 0-1, so you can load whatever
	// sized images you want and still use them to texture your box
	// but we have to explicitly normalize our tex coords here
	ofEnableNormalizedTexCoords();
    
	// loads the OF logo from disk
	ofLogo.loadImage("of.png");

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // get the most recent data
	//TabletData& data = ofxTablet::tabletData;
    //cout << "update tilt " << data.tilt[0] << endl;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor c;
    ofSetColor( c );
    ofFill();
    
    TabletData& data = ofxTablet::tabletData;
    //ofTranslate(400+data.location[0],400+data.location[1]);
    ofTranslate(data.absScreen[0]*1900,data.absScreen[1]*1200);
    ofRotateX(data.tilt[1]*70);
    ofRotateY(data.tilt[0]*70);
    float sca=(data.pressure*5);
    if (sca<1) sca = 1;
    ofScale(sca,sca,sca);

    ofLogo.bind();
    ofFill();
    ofSetColor(255);
    ofDrawBox(100);
    ofLogo.unbind();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

// get data as soon as it comes in
void ofApp::tabletMoved(TabletData &data) {
	// this would be a good place to get data from multiple devices
	
    //cout << "tabletMoved tilt " << data.tilt[0];
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
/*
    // get the most recent tablet data
	TabletData& data = ofxTablet::tabletData;
    printf("mouseMoved tilt: %f \n", data.tilt[0]);
 */
    TabletData& data = ofxTablet::tabletData;
    //printf("mouseMoved [%d,%d] data [%f,%f] \n", x,y, data.location[0], data.location[1]);
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
#include "ofApp.h"
#include "ofxTablet.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofxTablet::start();
    
    // if you want to get data events, you can add a listener to ofxTablet::tabletEvent
	ofAddListener(ofxTablet::tabletEvent, this, &ofApp::tabletMoved);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // get the most recent data
	TabletData& data = ofxTablet::tabletData;
    cout << "update tilt " << data.tilt[0] << endl;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor c;
    ofSetColor( c );
    ofFill();
    TabletData& data = ofxTablet::tabletData;
    ofTranslate(400,400);
    ofRotate(data.tilt[0]*60);

    ofRect( 20, 20, 100, 100 );
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
	//cout << data.getButton(0) << " " << data.getButton(1) << endl;
    cout << "tabletMoved tilt " << data.tilt[0];
	
	// use the button state to set the LED
	//ofxConnexion::setLed(data.getButton(0) || data.getButton(1));
} 

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
/*
    // get the most recent tablet data
	TabletData& data = ofxTablet::tabletData;
    printf("mouseMoved tilt: %f \n", data.tilt[0]);
 */
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
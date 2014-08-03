#pragma once

#include "ofMain.h"
#include "ofxTablet.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
        void tabletMoved(TabletData &data);  // for receiving tablet events directly
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofLight light; // creates a light and enables lighting
        ofCamera cam;
    
        ofMatrix4x4 tabmtx;
        float gridsize;
};

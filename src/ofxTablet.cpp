// Copyright (c) 2014 Matt Ebb
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ofxTablet.h"

#ifdef __APPLE__
    #include "tabletCocoa.h"
#endif

ofEvent<TabletData> ofxTablet::tabletEvent;
TabletData ofxTablet::tabletData;

void ofxTablet::start() {
#ifdef __APPLE__
    // only Mac Cocoa implemented so far
    setupTabletCocoa(tabletData);
#endif

}

// tablet data update method implemented here to so it can
// call ofNotifyEvent without including openframeworks in obj-c code
void TabletData::update() {
    ofNotifyEvent(ofxTablet::tabletEvent, ofxTablet::tabletData);
    
    tilt_vec[0] = tiltX;
    tilt_vec[1] = tiltY;
    tilt_vec[2] = sqrt(max(0.0,1.0 - tiltX*tiltX - tiltY*tiltY));
}

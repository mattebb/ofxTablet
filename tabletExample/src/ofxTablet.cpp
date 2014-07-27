#include "ofxTablet.h"
#include <iostream>

#ifdef __APPLE__
    #include "tabletCocoa.h"
#endif

ofEvent<TabletData> ofxTablet::tabletEvent;
TabletData ofxTablet::tabletData;

void ofxTablet::start() {
#ifdef __APPLE__
    setupTabletCocoa(tabletData);
#endif
}

void ofxTablet::handle() {

    std::cout << tabletData.pressure << " " << tabletData.tilt[0] << std::endl;
    ofNotifyEvent(tabletEvent, tabletData);
}

// tablet data update method implemented here to so it can
// call ofNotifyEvent without including openframeworks in obj-c code

void TabletData::update() {
    printf("UPDATE method \n");
    ofNotifyEvent(ofxTablet::tabletEvent, ofxTablet::tabletData);
}

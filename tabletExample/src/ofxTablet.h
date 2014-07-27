#pragma once
#include "ofMain.h"
#include "tabletData.h"


class ofxTablet {
public:
    static ofEvent<TabletData> tabletEvent;
    static TabletData tabletData;
    
    static void start();
	static void stop();
    static void handle();
};


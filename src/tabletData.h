// Copyright (c) 2014 Matt Ebb
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

// for meanings of fields see here: http://www.wacomeng.com/mac/Developers%20Guide.htm

class TabletData {
public:
    // absolute floating point location relative to main screen in (0,1)
    float absScreen[2];
    
    int absX;
    int absY;
    int absZ;
    float tilt[2];
    float pressure;
    float rotation;
    float tangentialPressure;
    
    // from proximity events
    bool in_proximity;
    int pointerType;
    int pointerID;      // index of the device on this tablet
    int deviceID;       // used to match pointer events with proximity events
    
    int vendorID;
    int vendorPointerType;
    
    // update global tablet data for use in openFrameworks, implemented in ofxTablet.cpp
    void update();
};

enum tabletPointerType {
    PTypeUnknown = 0,       // should never happen
    PTypePen,               // tip end of a stylus like device
    PTypeCursor,            // any puck like device
    PTypeEraser             // eraser end of a stylus like device
};

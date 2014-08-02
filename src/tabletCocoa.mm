// Copyright (c) 2014 Matt Ebb
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#import <Cocoa/Cocoa.h>
#import "tabletCocoa.h"

// forward declarations, keep NSEvent out of the C++ compatible header
void handlePoint(TabletData &data, NSEvent *event);
void handleProximity(TabletData &data, NSEvent *event);

void setupTabletCocoa(TabletData &data) {
    unsigned long long tabletmask =   NSMouseMovedMask|
                                NSLeftMouseDownMask|
                                NSRightMouseDownMask|
                                NSLeftMouseDraggedMask|
                                NSRightMouseDraggedMask;
    
    id handler = [NSEvent addLocalMonitorForEventsMatchingMask:tabletmask handler:^(NSEvent *event) {
        
        switch ([event subtype]) {
            case NX_SUBTYPE_TABLET_POINT:
                handlePoint(data, event);
                data.update();
                break;
            case NX_SUBTYPE_TABLET_PROXIMITY:
                handleProximity(data, event);
                data.update();
                break;
            default:
                break;
        }
        return event;
    }];
}

void handlePoint(TabletData &data, NSEvent *event) {

    NSRect frame = [[NSScreen mainScreen] frame];
    data.abs_screen[0] = [NSEvent mouseLocation].x / (frame.size.width);
    data.abs_screen[1] = [NSEvent mouseLocation].y / (frame.size.height);
    
    data.pressure = [event pressure];
    data.tiltX = [event tilt].x;
    data.tiltY = [event tilt].y;
    data.rotation = [event rotation];
    data.tangentialPressure = [event tangentialPressure];
}

void handleProximity(TabletData &data, NSEvent *event) {
    if ([event isEnteringProximity])
        data.in_proximity = TRUE;
    else
        data.in_proximity = FALSE;
    
    data.pointerType = [event pointingDeviceType];
    data.pointerID = [event pointingDeviceID];
    data.deviceID = [event deviceID];
    
    data.vendorID = [event vendorID];
    data.vendorPointerType = [event vendorPointingDeviceType];
}

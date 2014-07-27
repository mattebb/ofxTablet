#import <Cocoa/Cocoa.h>
#import "tabletCocoa.h"

void setupTabletCocoa(TabletData &data) {
    unsigned long long tabletmask =   NSMouseMovedMask|
                                NSLeftMouseDownMask|
                                NSRightMouseDownMask|
                                NSLeftMouseDraggedMask|
                                NSRightMouseDraggedMask;
    
    id handler = [NSEvent addLocalMonitorForEventsMatchingMask:tabletmask handler:^(NSEvent *event) {
        
        //handleTabletCocoa(event);
        
        switch ([event subtype]) {
            case NX_SUBTYPE_TABLET_POINT:
                //TabletData data;
                data.pressure = [event pressure];
                data.tilt[0] = [event tilt].x;
                data.tilt[1] = [event tilt].y;
                
                //ofxTablet::handle(&data);
                
                //NSLog(@"tablet pt, tilt %f \n", [event tilt].x);
                NSLog(@"setup tablet DATA pt, tilt %f \n", data.tilt[0]);
                data.update();
                break;
        }
        return event;
    }];
}

void handleTabletCocoa(NSEvent *event) {
    switch ([event subtype]) {
        case NX_SUBTYPE_TABLET_POINT:
            NSLog(@"tablet pt, tilt %f \n", [event tilt].x);
            break;
    }
}
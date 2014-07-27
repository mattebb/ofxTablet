#pragma once

class TabletData {
public:
    float tilt[2];
    float pressure;
    void update();
};
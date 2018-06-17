//
//  volunteer.hpp
//  Kimchi
//
//  Created by  Heejun Lee on 9/13/17.
//
//

#ifndef volunteer_hpp
#define volunteer_hpp

#include <stdio.h>
#include "ofMain.h"



class Volunteer{
public:
    Volunteer(int pos_x, int pos_y);
    ofImage img;
    int vol_x, vol_y;
    static const int VOLUNTEER_WIDTH = 40;
    static const int VOLUNTEER_LENGTH = 90;
    void setup();
    void update();
    void draw();
    void work();    // Shaking its arm
};

//-------------------------------------------

class Arm{
public:
    Arm();
    ofImage img;
    
    int arm_x, arm_y;
    static const int ARM_WIDTH = 60;
    static const int ARM_LENGTH = 60;
    void setup();
    void update();
    void draw();
    void work();
};

#endif /* volunteer_hpp */

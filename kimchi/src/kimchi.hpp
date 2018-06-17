//
//  kimchi.hpp
//  Kimchi
//
//  Created by  Heejun Lee on 9/14/17.
//
//

#ifndef kimchi_hpp
#define kimchi_hpp

#include <stdio.h>
#include "ofMain.h"

class Kimchi{
public:
    ofImage img[5];
    int kimchi_x, kimchi_y;
    static const int KIMCHI_WIDTH = 20;
    static const int KIMCHI_LENGTH = 20;
    int state;  //0: 1: 2: 3: 4:
    void setup();
    void update();
    void draw();
    
};

#endif /* kimchi_hpp */

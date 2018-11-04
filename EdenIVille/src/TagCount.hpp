//
//  TagCount.hpp
//  EdenIVille
//
//  Created by 정구열 on 2018. 1. 28..
//

#ifndef TagCount_hpp
#define TagCount_hpp

#include <stdio.h>
#include "ofMain.h"

class TagCount {
public:
    static const int SCORE_WIDTH = 120;
    static const int SCORE_HEIGHT = 270;
    static const int fixed_y = 1920*2 - 500;
    static const int floating_y = 20;
    
    bool checked;
    int pos_x, pos_y;
    int dir;
    int tagCount;
    int countState;
    ofImage number[4][10];
    
    void setup();
    void update();
    void draw();
};
#endif /* TagCount_hpp */

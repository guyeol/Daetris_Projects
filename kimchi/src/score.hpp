//
//  score.hpp
//  Kimchi
//
//  Created by  Heejun Lee on 9/14/17.
//
//

#ifndef score_hpp
#define score_hpp

#include <stdio.h>
#include "ofMain.h"

class Score{
public:
    ofImage number[4][10];
    void setup();
    void update();
    void draw();
};

#endif /* score_hpp */

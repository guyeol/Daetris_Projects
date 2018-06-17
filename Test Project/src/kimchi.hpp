//
//  kimchi.hpp
//  Test Project
//
//  Created by 정구열 on 2017. 9. 28..
//

#ifndef kimchi_hpp
#define kimchi_hpp

#include <stdio.h>
#include "ofMain.h"
class Kimchi{
public:
    ofImage kimchiImg;
    void setup();
    void update(bool isChecked);
    void draw();
    
    int pos_y;
    int pos_x;
    int state;
};
#endif /* kimchi_hpp */

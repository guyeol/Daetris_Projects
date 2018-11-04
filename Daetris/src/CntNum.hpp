//
//  CntNum.hpp
//  Daetris
//
//  Created by 정구열 on 2017. 11. 22..
//

#ifndef CntNum_hpp
#define CntNum_hpp

#include <stdio.h>
#include "ofMain.h"

class CntNum{
public:
    ofImage number[10], hundredsDigitImg, tensDigitImg, unitsImg;
    void setup();
    void update();
    void draw();
    void countUp();
    const int DIGIT_WIDTH = 80;
    const int DIGIT_HEIGHT = 140;
    const int HDIGIT_POSX = 105;
    const int TDIGIT_POSX = 205;
    const int UDIGIT_POSX = 305;
    const int DIGIT_POSY = 1920+65;
    int count;
    int hDigit, tDigit, units;
};

#endif /* CntNum_hpp */

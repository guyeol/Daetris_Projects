//
//  CntNum.cpp
//  Daetris
//
//  Created by 정구열 on 2017. 11. 22..
//

#include "CntNum.hpp"

void CntNum::setup(){
    static const string numberStr[] = { "0", "1", "2", "3", "4","5","6","7","8","9"};
    for(int j = 0; j < 10; j++)
        number[j].load("images/"+numberStr[j]+".png");
    hundredsDigitImg.load("images/default.png");
    tensDigitImg.load("images/default.png");
    unitsImg.load("images/0.png");
}

void CntNum::update(){
    if(count != 0 && count<10)
        unitsImg = number[count];
    if(count/10 != 0 && count<100){
        tDigit = count/10;
        units = (count - tDigit*10);
        tensDigitImg = number[tDigit];
        unitsImg = number[units];
    }
    if(count/100 != 0){
        hDigit = count/100;
        tDigit = (count - hDigit*100)/10;
        units = count - hDigit*100 - tDigit*10;
        hundredsDigitImg = number[hDigit];
        tensDigitImg = number[tDigit];
        unitsImg = number[units];
    }
}

void CntNum::draw(){
    hundredsDigitImg.draw(HDIGIT_POSX, DIGIT_POSY, DIGIT_WIDTH, DIGIT_HEIGHT);
    tensDigitImg.draw(TDIGIT_POSX, DIGIT_POSY, DIGIT_WIDTH, DIGIT_HEIGHT);
    unitsImg.draw(UDIGIT_POSX, DIGIT_POSY, DIGIT_WIDTH, DIGIT_HEIGHT);
}

void CntNum::countUp(){
    this->count ++;
}

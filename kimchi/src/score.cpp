//
//  score.cpp
//  Kimchi
//
//  Created by  Heejun Lee on 9/14/17.
//
//

#include "score.hpp"
#include <cstdlib>

void Score::setup(){
    static const string numberStr[] = { "0", "1", "2", "3", "4","5","6","7","8","9"};
    for(int i = 0 ; i < 4; i++){
        for(int j = 0; j < 10; j++){
            number[i][j].load("images/num_"+numberStr[j]+".png");
        }
    }
}

void Score::update(){
    for(int i=0; i<4 ; i++){
        for(int j=0; j<10; j++){
            number[i][j].update();
        }
    }
}

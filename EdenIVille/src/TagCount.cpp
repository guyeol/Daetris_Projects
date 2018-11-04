//
//  TagCount.cpp
//  EdenIVille
//
//  Created by 정구열 on 2018. 1. 28..
//

#include "TagCount.hpp"
#include <cstdlib>

void TagCount::setup(){
    static const string numberStr[] = { "0", "1", "2", "3", "4","5","6","7","8","9"};
    for(int i = 0 ; i < 4; i++){
        for(int j = 0; j < 10; j++){
            number[i][j].load("images/num_" + numberStr[j] + ".png");
        }
    }
    pos_y = fixed_y;
    dir = 1;
    countState = 0;
    tagCount = 0;
    checked = false;
}

void TagCount::update(){
    if(checked){
        // Update the count
        if(countState == 1){
            pos_y+=3;
            if(pos_y > 1920*2 + 10){
                tagCount++;
                countState = 2;
            }
        }
        else{
            pos_y-=3;
            if(pos_y <= fixed_y){
                pos_y = fixed_y;
                countState = 0;
                checked = false;
            }
        }
    }
    else{
        // Floating in the air
        if(pos_y == fixed_y + floating_y)
            dir = -2;
        else if(pos_y == fixed_y - floating_y)
            dir = 2;
        
        if(dir % 2 == 0){
            dir = dir / 2;
            pos_y += dir;
        }
        else if(dir < 0 ){
            dir--;
        }
        else{
            dir++;
        }
    }
}

void TagCount::draw(){
    int num, digit=0, tmp = tagCount;
    do{
        tmp /= 10;
        digit++;
    }while(tmp>0);
    tmp = tagCount;
    
    // 100
    if(digit==3){
        for(int i=0;i<digit;i++){
            num = tmp/pow(10, digit-i-1);
            tmp -= num*pow(10, digit-i-1);
            number[i][num].draw(400+i*130, pos_y, SCORE_WIDTH, SCORE_HEIGHT);
        }
    }
    // 10
    else if(digit==2){
        for(int i=0;i<digit;i++){
            num = tmp/pow(10, digit-i-1);
            tmp -= num*pow(10, digit-i-1);
            number[i][num].draw(450+i*130, pos_y, SCORE_WIDTH, SCORE_HEIGHT);
        }
    }
    // 1
    else{
        num = tmp;
        number[0][num].draw(520, pos_y, SCORE_WIDTH, SCORE_HEIGHT);
    }
}

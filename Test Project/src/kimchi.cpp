//
//  kimchi.cpp
//  Test Project
//
//  Created by 정구열 on 2017. 9. 28..
//

#include "kimchi.hpp"
void Kimchi::setup(){
    kimchiImg.load("images/kimchi.png");
    kimchiImg.resize(100,100);
    pos_x=500;
    pos_y=500;
}

void Kimchi::update(bool isChecked){

}

void Kimchi::draw(){
        kimchiImg.draw(pos_x,pos_y);
}

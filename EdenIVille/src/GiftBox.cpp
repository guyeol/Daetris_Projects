//
//  GiftBox.cpp
//  EdenIVille
//
//  Created by 정구열 on 2018. 2. 2..
//

#include "GiftBox.hpp"
#include <cmath>

void GiftBox::setup() {
    blueBox.load("images/gift_b.png");
    greenBox.load("images/gift_g.png");
    
}

void GiftBox::update() {
    if(count % 5 == 0) {
        boxCount = count/5;
        posY = 50 + 150*multiY;
        if((boxCount%2) == 1) {
            boxes[boxCount-1].image = greenBox;
            boxes[boxCount-1].boxPosX = posX[1-(int)pow(-1, boxCount-1)];
            boxes[boxCount-1].boxPosY = posY;
        }
        else {
            boxes[boxCount-1].image = blueBox;
            boxes[boxCount-1].boxPosX = posX[1-(int)pow(-1, boxCount-1)];
            boxes[boxCount-1].boxPosY = posY;
            multiY ++;
        }
    }
}

void GiftBox::draw() {
    for(int i = 0; i < boxCount; i++) boxes[i].image.draw(boxes[i].boxPosX, boxes[i].boxPosY);
}

void GiftBox::countUp(){
    this->count ++;
}

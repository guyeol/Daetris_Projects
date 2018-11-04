//
//  Items.cpp
//  EdenIVille
//
//  Created by 정구열 on 2018. 1. 28..
//

#include "Items.hpp"
#include <cstdlib>

void Items::setup(){
    currentItemIdx = 1;
    fallItemIdx = 0;
    ofImage img;
    isChecked = false;
    for(int i = 1; i <= 12; i++) {
        if(i%4 == 0)
            dir[i-1] = 2;
        else if(i%4 == 1)
            dir[i-1] = - 2;
        else if(i%4 == 2)
            dir[i-1] = 2;
        else if(i%4 == 3)
            dir[i-1] = -2;
    }
    int pos[12][2] {
        {30, 1920 + 830}, {270, 1920 + 800}, {450, 1920 + 870}, {710, 1920 + 930},
        {800, 1920 + 600}, {600, 1920 + 650}, {350, 1920 + 600}, {50, 1920 + 500},
        {0, 1920 + 250}, {250, 1920 + 170}, {450, 1920 + 220}, {800, 1920 + 150}
    };
    
    for(int i = 1; i <= 12; i++) {
        img.load("images/item_" + std::to_string(i) + ".png");
        item[i-1] = {img, pos[i-1][0], pos[i-1][1], pos[i-1][1]};
    }
    boyStar.show = false; girlStar.show = false;
    boyStar.posX = 280; boyStar.posY = 650;
    girlStar.posX = 690; girlStar.posY = 650;
}

void Items::update(){
    if(isChecked) {
        boyStar.img.load("images/star.png"); girlStar.img.load("images/star.png");
        boyStar.img.resize(100, 100); girlStar.img.resize(100, 100);
        fallItemIdx = currentItemIdx;
        currentItemIdx ++;
        isChecked = false;
    }
    for(int i = currentItemIdx; i <= 12; i++){
        if(item[i-1].itemPosY == item[i-1].fixedY + floatingY) dir[i-1] = -2;
        else if(item[i-1].itemPosY == item[i-1].fixedY - floatingY) dir[i-1] = 2;
        if(dir[i-1] % 2 == 0){
            dir[i-1] = dir[i-1] / 2;
            item[i-1].itemPosY += dir[i-1];
        }
        else if(dir[i-1] < 0 ) dir[i-1]--;
        else dir[i-1]++;
    }
    if(fallItemIdx) {
        if(item[fallItemIdx-1].itemPosY < 500){
            item[fallItemIdx-1].image.clear();
            if(fallItemIdx == 1 | fallItemIdx == 2 | fallItemIdx == 8 | fallItemIdx == 7 | fallItemIdx == 9 |fallItemIdx == 10) {
                boyStar.show = true;
            }
            else if(fallItemIdx == 3 | fallItemIdx == 4 | fallItemIdx == 5 | fallItemIdx == 6 | fallItemIdx == 11 | fallItemIdx == 12) {
                girlStar.show = true;
            }
            if(starWidth < 300) {
                starWidth += 5; starHeight += 5;
                if(boyStar.show) {
                    boyStar.img.resize(starWidth, starHeight);
                    boyStar.posX -= 2.5; boyStar.posY -= 2.5;
                }
                else {
                    girlStar.img.resize(starWidth, starHeight);
                    girlStar.posX -= 2.5; girlStar.posY -= 2.5;
                }
            }
            else {
                if(fallItemIdx == 12) init();
                fallItemIdx = 0; starWidth = 100; starHeight = 100;
                boyStar.img.clear(); girlStar.img.clear();
                boyStar.show = false; girlStar.show = false;
                boyStar.posX = 280; boyStar.posY = 650;
                girlStar.posX = 690; girlStar.posY = 650;
            }
        }
        else item[fallItemIdx-1].itemPosY-=10;
    }
}

void Items::draw(){
    for(int i = 0; i < 12; i++) item[i].image.draw(item[i].itemPosX, item[i].itemPosY);
    if(boyStar.show) boyStar.img.draw(boyStar.posX, boyStar.posY);
    else if(girlStar.show) girlStar.img.draw(girlStar.posX, girlStar.posY);
}

void Items::init(){
    ofImage img;
    int pos[12][2] {
        {30, 1920 + 830}, {270, 1920 + 800}, {450, 1920 + 870}, {710, 1920 + 930},
        {800, 1920 + 600}, {600, 1920 + 650}, {350, 1920 + 600}, {50, 1920 + 500},
        {0, 1920 + 250}, {250, 1920 + 170}, {450, 1920 + 220}, {800, 1920 + 150}
    };
    for(int i = 1; i <= 12; i++) {
        img.load("images/item_" + std::to_string(i) + ".png");
        item[i-1] = {img, pos[i-1][0], pos[i-1][1], pos[i-1][1]};
    }
    currentItemIdx = 1;
}

//
//  Items.hpp
//  EdenIVille
//
//  Created by 정구열 on 2018. 1. 28..
//

#ifndef Items_hpp
#define Items_hpp

#include <stdio.h>
#include <vector>
#include "ofMain.h"

using namespace std;

class Items {
public:

    void setup();
    void update();
    void draw();
    void init();
    
    static const int ITEM_WIDTH = 200;
    static const int ITEM_HEIGHT = 200;
    static const int floatingY = 20;
    int starWidth = 100;
    int starHeight = 100;
    int currentItemIdx;
    int dir[12];
    int fallItemIdx;
    bool isChecked;
    
    struct items {
        ofImage image;
        int itemPosX;
        int itemPosY;
        int fixedY;
    };
    
    struct star {
        ofImage img;
        float posX;
        float posY;
        int width;
        int height;
        bool show;
    };
    
    items item[12];
    star boyStar, girlStar;
};
#endif /* Items_hpp */

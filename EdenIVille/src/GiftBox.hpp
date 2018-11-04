//
//  GiftBox.hpp
//  EdenIVille
//
//  Created by 정구열 on 2018. 2. 2..
//

#ifndef GiftBox_hpp
#define GiftBox_hpp

#include <stdio.h>
#include "ofMain.h"

using namespace std;

class GiftBox {
public:
    void setup();
    void draw();
    void update();
    void countUp();
    
    int boxCount;
    int count;
    int posX[3] = {5, 0, 930};
    int posY = 50;
    int multiY = 0;
    
    ofImage blueBox, greenBox;
    struct box {
        ofImage image;
        int boxPosX;
        int boxPosY;
    };
    struct box boxes[30];
};
#endif /* GiftBox_hpp */

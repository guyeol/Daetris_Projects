//
//  volunteer.cpp
//  Kimchi
//
//  Created by  Heejun Lee on 9/13/17.
//
//

#include "volunteer.hpp"

Volunteer::Volunteer(int x,int y){
    pos_x = x;
    pos_y = y;
}

void Volunteer::setup(){
    
}

void Volunteer::update(){
    
}

void Volunteer::draw(){
    img.draw(pos_x, pos_y, VOLUNTEER_WIDTH, VOLUNTEER_LENGTH);
}

void Volunteer::work(){
    //  Input shaking arm motion or calling that mehtod in Arm
}

//-------------------------------------------

Arm::Arm(){
    arm_x = Volunteer::vol_x + 5;
    arm_y = Volunteer::vol_y - 15;
}

void Arm::setup(){
    
}

void Arm::update(){
    //  Input shaking arm motion
}

void Arm::draw(){
    img.draw(arm_x, arm_y, ARM_WIDTH, ARM_LENGTH);
}

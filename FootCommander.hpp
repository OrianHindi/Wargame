//
// Created by yirat on 19/05/2020.
//

#pragma once

#include "Soldier.hpp"

class FootCommander : public Soldier{
public:
    FootCommander(int num_player):Soldier(150,20,num_player){}
    void take_activity () override{}
};
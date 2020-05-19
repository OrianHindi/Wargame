//
// Created by Yirat and Orian on 19/05/2020.
//

#pragma once

#include "Soldier.hpp"

class Paramedic : public Soldier{
public:
    Paramedic(int num_player): Soldier(100,50, num_player){}
    void take_activity () override;

};
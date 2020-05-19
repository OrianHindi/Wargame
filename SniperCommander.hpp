//
// Created by Yirat and Orian on 19/05/2020.
//

#pragma once

#include "Soldier.hpp"

class SniperCommander : public Soldier{
public:
    SniperCommander(int num_player):Soldier(120,100,num_player){}

    void take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>> board) override;


};
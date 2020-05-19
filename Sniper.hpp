//
// Created by yirat on 19/05/2020.
//
#pragma  once

#include "Soldier.hpp"

class Sniper : public Soldier{
    Sniper(int num_player) : Soldier(100,50,num_player){}

    void take_activity(std::pair<int,int> source,WarGame::Board& gameBoard) override ;
};

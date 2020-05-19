//
// Created by Yirat and Orian on 19/05/2020.
//

#pragma once
#include "Soldier.hpp"
using namespace std;

class ParamedicCommander : public Soldier{
public:
    ParamedicCommander(int num_payer): Soldier(200,100,num_payer){}

    void take_activity () override;
};

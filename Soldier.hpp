
#pragma once
#include <vector>
#include <utility>

class Soldier{
public:
    int HP;
    int AP;
    int player;
    static int num1;
    static int num2;
    Soldier(int HP, int AP, int player):
    HP(HP), AP(AP), player(player){
        if(player==1)num1++;
        if(player==2)num2++;
    }
    virtual void take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>> board)=0;
};

int Soldier::num1=0;
int Soldier::num2=0;



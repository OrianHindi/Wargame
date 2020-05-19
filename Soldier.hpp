
#pragma once

class Soldier{
protected:
    int HP;
    int AP;
    int player;
public:
    Soldier(int HP, int AP, int player):
    HP(HP), AP(AP), player(player){
    }
    virtual void take_activity()=0;
};




#pragma once
#include <vector>
#include <utility>
#include <limits>
#include <cmath>

static int num1=0;
static int num2=0;

class Soldier{
public:
    int HP;
    int player;
    const int maxHP;
    const int AP;

    Soldier(int HP, int player,int AP,int maxHP):
            HP(HP), player(player) , AP(AP) ,maxHP(maxHP) {
        if(player==1)num1++;
        if(player==2)num2++;
    }
    virtual ~Soldier(){
        if(player==1)num1--;
        if(player==2)num2--;
    }

    virtual void take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board)=0;

    std::pair<int,int> minDistance (std::pair<int,int> source,const std::vector<std::vector<Soldier*>>& board){
        std::pair<int,int> ans;
        double min=std::numeric_limits<double>::max();
        int toAttack;
        double distance;
        if(board[source.first][source.second]->player==1) toAttack=2; //check who i need to attack;
        else toAttack=1;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]!=nullptr && board[i][j]->player==toAttack){
                    distance=sqrt(pow(source.first-i,2)+pow(source.second-j,2));
                    if(distance<min) {
                        min=distance;
                        ans.first=i;
                        ans.second=j;
                    }
                }
            }
        }
        return ans;
    }
};

//int Soldier::num1=0;
//int Soldier::num2=0;



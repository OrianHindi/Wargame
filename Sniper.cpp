//
// Created by yirat on 19/05/2020.
//

#include "Sniper.hpp"

void Sniper::take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board){
    std::pair<int,int> toAttack = this->minDistance(source,board);
    int life =board[toAttack.first][toAttack.second]->HP;
    int hit = board[source.first][source.second]->AP;
    board[toAttack.first][toAttack.second]->HP=life-hit;
    if(board[toAttack.first][toAttack.second]->HP<=0) {
        delete board[toAttack.first][toAttack.second];
        board[toAttack.first][toAttack.second]= nullptr;
    }
}


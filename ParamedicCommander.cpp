//
// Created by yirat on 19/05/2020.
//
#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"

void ParamedicCommander::take_activity(std::pair<int, int> source, std::vector<std::vector<Soldier *> > &board) {
    std::pair<int,int> toAttack = this->minDistance(source,board);
    int check  = board[source.first][source.second]->player;
    board[toAttack.first][toAttack.second]->HP=maxHP;
    for(int i = 0; i<board.size(); i++){
        for(int j =0; j<board[i].size() ; j++){
            if(board[i][j]->player==check && dynamic_cast<Paramedic*>(board[i][j]))
                board[i][j]->take_activity({i,j},board);
        }
    }
}
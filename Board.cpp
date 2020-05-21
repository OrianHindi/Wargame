//
// Created by yirat on 19/05/2020.
//
#include "Board.hpp"
using namespace std;

bool WarGame::Board::has_soldiers(uint player_number) const{
    if(player_number==1 && num1==0) return false;
    if(player_number==2 && num2==0) return false;
    return true;
}

void WarGame::Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
    Soldier* toMove = (*this)[source];
    std::pair<int,int> target;
    switch(direction){
        case Up:
            target.first=source.first+1;
            target.second=source.second;
            break;
        case Down:
            target.first=source.first-1;
            target.second=source.second;
            break;
        case Left:
            target.first=source.first;
            target.second=source.second-1;
            break;
        case Right:
            target.first=source.first;
            target.second=source.second+1;
            break;
    }
    if(toMove == nullptr || toMove->player!=player_number || (*this)[target]!= nullptr){
        throw invalid_argument("Action is forbidden");
    }
    if(target.first<0 || target.first>=board.size()|| target.second<0 || target.second>=board[target.first].size()) {
        throw invalid_argument("Action is forbidden,out of Board");
    }
    (*this)[target]=toMove;
    (*this)[source]=nullptr;
    toMove->take_activity(target,board);

}


Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
    return this->board[location.first][location.second];
}

Soldier*& WarGame::Board::operator[](std::pair<int,int> location){
    return this->board[location.first][location.second];
}


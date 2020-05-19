//
// Created by yirat on 19/05/2020.
//
#include "Board.hpp"
using namespace std;

bool WarGame::Board::has_soldiers(uint player_number) const{
    return true;
}
void WarGame::Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){

}
Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
    return nullptr;
}
Soldier*& WarGame::Board::operator[](std::pair<int,int> location){
    return board[0][0];
}


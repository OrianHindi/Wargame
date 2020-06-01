/**
  Demo for the war-game exercise.

  @author Oz Levi
  @since  2020-05
**/

#include <iostream>
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"




using namespace std;
WarGame::Board fillBoard(){
    WarGame::Board p(6,6);
    p[{0,0}]= new FootSoldier(1);
    p[{3,3}]= new FootSoldier(2);
    p[{5,0}]= new FootCommander(1);
    p[{3,5}]= new FootCommander(2);
    p[{0,1}]= new Sniper(1);
    p[{3,0}]= new Sniper(2);
    p[{2,1}]= new SniperCommander(1);
    p[{0,3}]= new SniperCommander(2);
    p[{5,1}]= new Paramedic(1);
    p[{1,3}]= new Paramedic(2);
    p[{4,5}]= new ParamedicCommander(1);
    p[{4,0}]= new ParamedicCommander(2);
    return p;
}
int main() {
    pair<int,int> (1,2);
    WarGame::Board p = fillBoard();
    p.move(1,{0,0},WarGame::Board::Up);
    p.move(1,{0,1},WarGame::Board::Left);
    p.move(1,{2,1},WarGame::Board::Down);
    (p.move(2,{0,3},WarGame::Board::Right));
    (p.move(2,{3,0},WarGame::Board::Down));
    (p.move(2,{3,3},WarGame::Board::Right));
    (p.move(2,{3,5},WarGame::Board::Down));
    (p.move(2,{4,0},WarGame::Board::Down));
    (p.move(1,{4,5},WarGame::Board::Up));
    (p.move(1,{5,0},WarGame::Board::Down));
    (p.move(1,{5,1},WarGame::Board::Right));
    (p.move(1,{5,2},WarGame::Board::Right));
    (p.move(1,{5,5},WarGame::Board::Left));
    (p.move(1,{4,0},WarGame::Board::Right));
    return 0;
}

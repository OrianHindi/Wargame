//
// Created by Yirat and Orian on 19/05/2020.
//

#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"




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
WarGame::Board fillCommBoard(){
    WarGame::Board p (5,5);
    p[{0,0}] = new FootSoldier(1);
    p[{0,1}] = new FootSoldier(2);
    p[{0,3}] = new SniperCommander(2);
    p[{0,4}] = new FootCommander(2);
    p[{2,0}] = new Paramedic(2);
    p[{2,1}] = new Paramedic(1);
    p[{2,2}] = new FootCommander(1);
    p[{2,3}] = new SniperCommander(1);
    p[{4,0}] = new Sniper(1);
    p[{4,1}] = new Sniper(2);
    p[{4,3}] = new ParamedicCommander(1);
    p[{4,4}] = new ParamedicCommander(2);
    return p;
}



TEST_CASE("Check Adding player to board"){
    WarGame::Board q(1,1);
            CHECK_FALSE(q.has_soldiers(1));
            CHECK_FALSE(q.has_soldiers(2));
    WarGame::Board p = fillBoard();
            CHECK(p.has_soldiers(1)== true);
            CHECK(p.has_soldiers(2)== true);
            CHECK(typeid(p[{0,0}]) == typeid(FootSoldier));
            CHECK(typeid(p[{3,3}]) == typeid(FootSoldier));
            CHECK(typeid(p[{5,0}]) == typeid(FootCommander));
            CHECK(typeid(p[{3,5}]) == typeid(FootCommander));
            CHECK(typeid(p[{0,1}]) == typeid(Sniper));
            CHECK(typeid(p[{3,0}]) == typeid(Sniper));
            CHECK(typeid(p[{2,1}]) == typeid(SniperCommander));
            CHECK(typeid(p[{0,3}]) == typeid(SniperCommander));
            CHECK(typeid(p[{5,1}]) == typeid(Paramedic));
            CHECK(typeid(p[{1,3}]) == typeid(Paramedic));
            CHECK(typeid(p[{4,5}]) == typeid(ParamedicCommander));
            CHECK(typeid(p[{4,0}]) == typeid(ParamedicCommander));
}

TEST_CASE("Move function - no Commander"){
    WarGame::Board p = fillBoard();
    p.move(1,{0,0},WarGame::Board::Up);
            CHECK(p[{0,0}]== nullptr);
            CHECK(typeid(p[{1,0}])==typeid(FootSoldier));
            CHECK(p[{3,0}]->HP==90);
    p.move(1,{0,1},WarGame::Board::Right);
            CHECK(p[{0,1}]==nullptr);
            CHECK(typeid(p[{0,2}])== typeid(Sniper));
            CHECK(p[{0,3}]->HP==70);
    p.move(1,{5,1},WarGame::Board::Down);
            CHECK(p[{5,1}]==nullptr);
            CHECK(typeid(p[{4,1}])== typeid(Paramedic));
            CHECK(p[{5,0}]->HP==p[{5,0}]->maxHP);

    p.move(2,{3,0},WarGame::Board::Right);
            CHECK(p[{3,0}]== nullptr);
            CHECK(typeid(p[{3,1}])==typeid(Sniper));
            CHECK(p[{2,1}]->HP==70);
    p.move(2,{3,3},WarGame::Board::Up);
            CHECK(p[{3,3}]== nullptr);
            CHECK(typeid(p[{4,3}])==typeid(FootSoldier));
            CHECK(p[{4,5}]->HP==190);
    p.move(2,{2,3},WarGame::Board::Right);
            CHECK(p[{2,3}]== nullptr);
            CHECK(typeid(p[{2,4}])==typeid(Paramedic));
            CHECK(p[{0,3}]->HP==p[{0,3}]->maxHP);
}

TEST_CASE("Move Function - Commander"){
    WarGame::Board p = fillCommBoard();
    p.move(1,{2,2},WarGame::Board::Up);
        CHECK(p[{2,2}]==nullptr);
        CHECK(typeid(p[{3,2}])== typeid(FootCommander));
        CHECK(p[{4,2}]->HP==80);
        CHECK(p[{0,1}]->HP==90);
    p.move(1,{2,3},WarGame::Board::Down);
        CHECK(p[{2,3}]==nullptr);
        CHECK(typeid(p[{1,3}])==typeid(SniperCommander));
        CHECK(p[{0,3}]->HP==20);
        CHECK(p[{4,2}]->HP==30);

    p.move(1,{4,3},WarGame::Board::Down);
        CHECK(p[{4,3}]==nullptr);
        CHECK(typeid(p[{3,3}])==typeid(ParamedicCommander));
        CHECK(p[{3,2}]->HP==p[{3,2}]->maxHP);
        CHECK(p[{3,2}]->HP==p[{3,2}]->maxHP);

    p.move(2,{})

}





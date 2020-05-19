cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled Demo.cpp Soldier.hpp Board.cpp FootSoldier.cpp FootSoldier.hpp FootCommander.cpp FootCommander.hpp Sniper.cpp Sniper.hpp SniperCommander.cpp SniperCommander.hpp Paramedic.cpp Paramedic.hpp ParamedicCommander.cpp ParamedicCommander.hpp Test.cpp)
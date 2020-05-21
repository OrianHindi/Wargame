cmake_minimum_required(VERSION 3.15)
project(Wargame)

set(CMAKE_CXX_STANDARD 14)

add_executable(Wargame Demo.cpp Soldier.hpp FootCommander.hpp FootSoldier.hpp Board.hpp DemoGame.hpp DemoGame.cpp)
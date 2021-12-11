cmake_minimum_required(VERSION 3.20)
project(CogielSzymon-etap1)

set(CMAKE_CXX_STANDARD 17)

add_executable(CogielSzymon-etap1
        main.cpp Car.cpp Factory.cpp)

target_link_libraries(CogielSzymon-etap1 -lSDL2 -lSDL2_mixer)

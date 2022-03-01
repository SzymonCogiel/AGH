cmake_minimum_required(VERSION 3.20)
project(CogielSzymon-etap2)

set(CMAKE_CXX_STANDARD 17)

add_executable(CogielSzymon-etap2
        main.cpp Car.cpp Factory.cpp Motor_vehicle.cpp Motor.cpp Varnisher.cpp Vehicle.cpp Bike.cpp Komis.cpp Cin_exception.cpp Div_zero_exc.cpp utils.cpp)

target_link_libraries(CogielSzymon-etap2 -lSDL2 -lSDL2_mixer)

#add_custom_command(
#        TARGET ${PROJECT_NAME}  POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#        ${CMAKE_CURRENT_BINARY_DIR}/motor_in_stock.csv
#        ${CMAKE_CURRENT_BINARY_DIR}/motor_in_stock.csv)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datafactory.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/motor_in_stock.csv
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/cars_in_stock.csv
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/KK_CHCIALBYM.wav
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/stdin.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/cars_for_sell.csv
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

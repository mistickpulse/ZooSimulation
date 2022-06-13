cmake_minimum_required(VERSION 3.8)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/module)
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_NAME)

############## COLORS

set(RED "red")
set(NORMAL "normal")
set(BLACK "black")
set(GREEN "green")
set(YELLOW "yellow")
set(BLUE "blue")
set(MAGENTA "magenta")
set(CYAN "cyan")
set(WHITE "white")
set(BOLD "bold")

function(message_color color str)
    execute_process(COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --${BOLD} --${color} ${str})
endfunction(message_color)

#####################

## Habitats Sources & Headers ## 
set(SRC_HABITATS )
set(HDR_HABITATS ./src/Habitats/Cages.hpp ./src/Habitats/CagesReferences.hpp)

## Food Sources & Headers ## 
set(SRC_FOOD ./src/Foods/foodPrice.cpp)
set(HDR_FOOD ./src/Foods/foodPrice.hpp ./src/Foods/FoodType.hpp)

## Animals Sources & Headers ## 
set(HDR_ANIMAL ./src/Animals/Animal.hpp ./src/Animals/AnimalType.hpp ./src/Animals/Eagle.hpp)

set(SRC ${SRC_FOOD} ${SRC_ANIMAL} ${SRC_HABITATS} ./src/main.cpp ./src/Zoo.cpp)
set(HDR ${HDR_FOOD} ${HDR_ANIMAL} ${HDR_HABITATS} ./src/Zoo.hpp)

message_color(${GREEN} "Starting Compilation")
add_executable(${PROJECT_NAME} ${SRC} ${HDR})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "zooSimulator")

cmake_minimum_required(VERSION 3.25.2)

project(Paper-Rock-Scissors)

add_executable(Paper-Rock-Scissors
  src/Computer.cpp
  src/Game.cpp
  src/Human.cpp
  src/Message.cpp
  src/main.cpp
  src/Player.cpp
)

set_target_properties(Paper-Rock-Scissors PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)
target_include_directories(Paper-Rock-Scissors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
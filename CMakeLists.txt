cmake_minimum_required(VERSION 3.22)
project(BeatLeaderFriendsSniper VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include($ENV{ANDROID_NDK}/build/cmake/android.toolchain.cmake)

add_library(${PROJECT_NAME} SHARED
  src/main.cpp
  src/BeatLeaderService.cpp
  src/FriendsLeaderboardController.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wno-unused-parameter)

find_package(beatsaber-hook REQUIRED CONFIG)
find_package(Paper REQUIRED CONFIG)

target_link_libraries(${PROJECT_NAME}
  beatsaber-hook::shared
  Paper::Paper
  log
)

# QPM packaging helper
include($ENV{QPM_PATH}/modloader.cmake)
setup_mod(${PROJECT_NAME})

cmake_minimum_required(VERSION 3.28)
project(MusicPlayerCLI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

# ---------------------------------------------------
# FTXUI
# ---------------------------------------------------
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

# ---------------------------------------------------
# SFML (Audio Only)
# ---------------------------------------------------
FetchContent_Declare(sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.1
)
FetchContent_MakeAvailable(sfml)

# ---------------------------------------------------
# TagLib via ExternalProject_Add
# ---------------------------------------------------
include(ExternalProject)

ExternalProject_Add(taglib_ep
  GIT_REPOSITORY https://github.com/taglib/taglib.git
  GIT_TAG v2.1.1
  PREFIX ${CMAKE_BINARY_DIR}/taglib
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/taglib/install
)

include_directories(${CMAKE_BINARY_DIR}/taglib/install/include)
link_directories(${CMAKE_BINARY_DIR}/taglib/install/lib)

# ---------------------------------------------------
# Add Executable and Sources
# ---------------------------------------------------
add_executable(main
  src/main.cpp
  src/song.cpp
  src/playlist.cpp
  src/music_player.cpp
)

# Ensure TagLib builds before main
add_dependencies(main taglib_ep)

# Zlib is required by TagLib
find_package(ZLIB REQUIRED)

# ---------------------------------------------------
# Link Libraries
# ---------------------------------------------------
target_link_libraries(main
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component

  PRIVATE sfml-audio
  PRIVATE sfml-system

  PRIVATE tag
  PRIVATE ZLIB::ZLIB
)

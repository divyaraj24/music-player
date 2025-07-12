cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

find_package(Taglib REQUIRED)

add_executable(main src/main.cpp src/song.cpp src/playlist.cpp)
target_compile_features(main PRIVATE cxx_std_17)


target_link_libraries(main PRIVATE SFML::Graphics)
target_link_libraries(main PRIVATE SFML::Audio)

# taglib multiplatform linking
if (WIN32)
    # Assume TagLib is installed in a known directory on Windows (e.g., vcpkg or manual)
    target_include_directories(main PRIVATE "C:/libs/taglib/include")
    target_link_directories(main PRIVATE "C:/libs/taglib/lib")
    target_link_libraries(main PRIVATE tag)
elseif(APPLE)
    find_package(Taglib REQUIRED)
    target_link_libraries(main PRIVATE Taglib::Taglib)
elseif(UNIX)
    target_include_directories(main PRIVATE /usr/include/taglib)
    target_link_libraries(main PRIVATE tag)
endif()


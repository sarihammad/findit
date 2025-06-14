cmake_minimum_required(VERSION 3.10)
project(FindIt)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(FindIt
    main.cpp
    src/FileManager.cpp
    src/Searcher.cpp
    src/SearchResult.cpp
    src/ThreadedSearchEngine.cpp
)
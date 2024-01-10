cmake_minimum_required(VERSION 3.27)
project(db_workers VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(db_workers
        headers/buffer.h
        sources/buffer.cpp

        headers/database.h
        sources/database.cpp
        sources/database.ui

        headers/add_worker_win.h
        sources/add_worker_win.cpp
        sources/add_worker_win.ui

        headers/informational.h
        sources/informational.cpp
        sources/informational.ui

        main.cpp
)

target_link_libraries(db_workers PRIVATE Qt6::Widgets)

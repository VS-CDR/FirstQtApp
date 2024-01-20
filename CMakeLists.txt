cmake_minimum_required(VERSION 3.27)
project(db_workers VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(DBSM
        headers/buffer.h
        sources/buffer.cpp

        headers/mainwindow.h
        sources/mainwindow.cpp
        sources/mainwindow.ui

        headers/add_worker_win.h
        sources/add_worker_win.cpp
        sources/add_worker_win.ui

        headers/informational.h
        sources/informational.cpp
        sources/informational.ui

        main.cpp
)


target_link_libraries(DBSM
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

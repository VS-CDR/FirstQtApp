cmake_minimum_required(VERSION 3.27)
project(db_workers VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(db_workers
        forms/database.ui
        sources/database.cpp

        forms/add_worker_win.ui
        sources/add_worker_win.cpp

        forms/informational.ui
        sources/informational.cpp
        main.cpp
)

target_link_libraries(db_workers PRIVATE Qt6::Widgets)

#set_target_properties(db_workers PROPERTIES
#        WIN32_EXECUTABLE ON
#        MACOSX_BUNDLE ON
#)

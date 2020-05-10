cmake_minimum_required(VERSION 3.16)
project(prac_qt)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)

find_package (Qt5Core)
find_package (Qt5Widgets)

qt5_wrap_ui(QT_TEST_UI_HEADERS  mainwindow.ui)
add_executable(prac_qt main.cpp dbmanager.cpp mainwindow.cpp ${QT_TEST_UI_HEADERS})
target_link_libraries(prac_qt ${Qt5Core_LIBRARIES} ${Qt5Widgets_LIBRARIES})

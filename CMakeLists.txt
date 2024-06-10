cmake_minimum_required(VERSION 3.14)

project(qtlab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

option(RELEASE_BUILD "Enable Release build" OFF)
if(RELEASE_BUILD)
    set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

qt6_wrap_ui(UI_HEADERS "ui/dialogwindow.ui")
qt6_wrap_cpp(MOC_SOURCES ${HEADERS})

if (WIN32)
    add_executable(qtlab WIN32 ${SOURCES} ${MOC_SOURCES})
else()
    add_executable(qtlab ${SOURCES} ${MOC_SOURCES})
endif()

target_link_libraries(qtlab PRIVATE Qt6::Widgets)
target_include_directories(qtlab PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(qtlab PRIVATE
    $<$<CONFIG:Release>:RELEASE_BUILD>
)

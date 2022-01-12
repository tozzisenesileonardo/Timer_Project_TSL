cmake_minimum_required(VERSION 3.19)
project(Timer_Project_TSL)

set(CMAKE_CXX_STANDARD 11)


set(wxWidgets_ROOT_DIR </usr/include/wx-3.0-unofficial>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_subdirectory(Test)

set(SOURCE_FILES main.cpp Applicazione.cpp Applicazione.h Cronometro.cpp Cronometro.h MainFrame.cpp MainFrame.h CronoType.cpp CronoType.h OroType.cpp OroType.h TimerType.cpp TimerType.h Orologio.cpp Orologio.h Timer.cpp Timer.h )
add_executable(Timer ${SOURCE_FILES} )
add_library(core ${SOURCE_FILES} )
target_link_libraries(Timer ${wxWidgets_LIBRARIES} core)
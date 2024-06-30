cmake_minimum_required(VERSION 3.5)

project(Weather_Predictor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)
find_package(ZLIB REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mywidget.cpp
        mywidget.h
        mywidget.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Weather_Predictor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        cityinfo.h cityinfo.cpp
                weathereachday.h weathereachday.cpp
                decompressGzip.h
                decompressGzip.cpp
                search_box.h search_box.cpp search_box.ui
	weatherrealtime.cpp weatherrealtime.h
        images/WeiMingLake.png

        images.qrc
        images/multiweather.h images/multiweather.cpp images/multiweather.ui
        followmousewidget.h followmousewidget.cpp followmousewidget.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Weather_Predictor APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Weather_Predictor SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Weather_Predictor
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Weather_Predictor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network ZLIB::ZLIB)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Weather_Predictor)
endif()
set_target_properties(Weather_Predictor PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Weather_Predictor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Weather_Predictor)
endif()

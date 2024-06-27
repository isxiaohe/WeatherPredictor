cmake_minimum_required(VERSION 3.5)

project(Weather-main004 VERSION 0.1 LANGUAGES CXX)

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
    search_box.cpp
    search_box.h
    search_box.ui
    001.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Weather-main004
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        cityinfo.h cityinfo.cpp
        weathereachday.h weathereachday.cpp
        decompressGzip.h
        decompressGzip.cpp

    )
else()
    if(ANDROID)
        add_library(Weather-main004 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Weather-main004
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# 链接库
target_link_libraries(Weather-main004 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network ZLIB::ZLIB)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Weather-main004)
endif()
set_target_properties(Weather-main004 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Weather-main004
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Weather-main004)
endif()

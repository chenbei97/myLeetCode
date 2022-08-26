cmake_minimum_required(VERSION 3.5)

project(TCPServer LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()
set(Qt5_DIR C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib/cmake/Qt5) # C:\Qt\Qt5.9.9\5.9.9\mingw53_32\lib\cmake可以看到所有的包依赖
find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

if(ANDROID)
  add_library(TCPServer SHARED
    main.cpp
    TCPServer.cpp
    TCPServer.h
    mSocket.cpp
    mSocket.h
    mServer.cpp
    mServer.h
  )
else()
  add_executable(TCPServer
    main.cpp
    TCPServer.cpp
    TCPServer.h
    mSocket.cpp
    mSocket.h
    mServer.cpp
    mServer.h
  )
endif()

target_link_libraries(TCPServer PRIVATE Qt5::Widgets Qt5::Network)

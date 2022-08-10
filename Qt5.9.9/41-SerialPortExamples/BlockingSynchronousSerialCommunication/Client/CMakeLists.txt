cmake_minimum_required(VERSION 3.5)

project(Client LANGUAGES CXX)

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
if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(Qt5_DIR C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib/cmake/Qt5) # C:\Qt\Qt5.9.9\5.9.9\mingw53_32\lib\cmake可以看到所有的包依赖

find_package(Qt5 COMPONENTS Widgets SerialPort REQUIRED)

if(ANDROID)
  add_library(Client SHARED
    main.cpp
    serialClient.cpp
    serialClient.h
    clientThread.cpp
    clientThread.h
  )
else()
  add_executable(Client
    main.cpp
    serialClient.cpp
    serialClient.h
    clientThread.cpp
    clientThread.h
  )
endif()

target_link_libraries(Client PRIVATE Qt5::Widgets Qt5::SerialPort )

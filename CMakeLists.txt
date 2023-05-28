#Touche Windows --> Taper "Qt" -> "Qt 5.6 for Desktop (MSVC2015 64 bits)"
#ouvrira une console avec l'environnement de Qt préchargé.
#Ensuite tapez "windeployqt -release (ou -debug) <chemin_de_mon_exécutable>".

cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



project(NaoCmakeBroker VERSION 0.1 LANGUAGES CXX)
#set(CMAKE_PREFIX_PATH C:/Qt/6.4.1/mingw_64)
#set(CMAKE_PREFIX_PATH C:/Qt/5.15.2/msvc2015_64)
set(CMAKE_PREFIX_PATH C:/Qt/5.15.2/mingw_64)

set(QT_DIR  C:/Qt/5.15.2/msvc2015_64/lib/cmake/Qt5)
set(Qt5_DIR C:/Qt/5.15.2/msvc2015_64/lib/cmake/Qt5)
#set(QT_DIR C:/Qt/6.4.1/msvc2019_64/lib/cmake/Qt6)
#set(Qt6_DIR C:/Qt/6.4.1/msvc2019_64/lib/cmake/Qt6)

#C:\Qt\6.4.1\msvc2019_64\lib\cmake\Qt6

#LINK_DIRECTORIES(C:/PCL 1.8.1/3rdParty/Boost/lib)
LINK_DIRECTORIES(C:/naoqi-sdk/lib)
LINK_DIRECTORIES(C:/naoqi-sdk/needLib)

# dans C:\Qt\5.15.2\msvc2015_64\plugins\sqldrivers
# -> copier qsqlmysql.dll version MSVC et release

find_package(QT NAMES Qt5 COMPONENTS Widgets Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Sql REQUIRED)
find_package(qibuild)


#add_compile_options(/Zc:rvalueCast /Zc:inline /Zc:strictStrings /Zc:throwingNew /permissive- /Zc:__cplusplus /Zc:externConstexpr /utf-8 /w34100 /w34189 /w44996 /w44456 /w44457 /w44458)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        img/img.qrc
)

qi_create_bin(NaoCmakeBroker ${PROJECT_SOURCES})

add_library(NAO)
qi_use_lib(NAO ALPROXIES ALCOMMON ALVALUE ALERROR ALAUDIO)

target_link_libraries(NaoCmakeBroker PRIVATE Qt5::Widgets Qt5::Sql NAO)



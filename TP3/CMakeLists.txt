cmake_minimum_required( VERSION 3.0 )
project( TP_CPP )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )
set( CMAKE_BUILD_TYPE Debug )

find_package( PkgConfig REQUIRED )
pkg_check_modules( PKG REQUIRED cpputest )
include_directories( ${PKG_INCLUDE_DIRS} )

add_executable( main.out src/main.cpp
	src/Location.cpp
	src/Client.cpp
	src/Produit.cpp
	src/Magasin.cpp)
target_link_libraries( main.out ${PKG_LIBRARIES} )

add_executable( main_test.out src/main_test.cpp
	src/Client.cpp
	src/Client_test.cpp
	src/Produit.cpp
	src/Produit_test.cpp
	src/Location.cpp
	src/Magasin.cpp
	src/Magasin_test.cpp)
target_link_libraries( main_test.out ${PKG_LIBRARIES} )


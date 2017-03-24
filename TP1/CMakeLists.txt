cmake_minimum_required( VERSION 3.0 )
project( TP1 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )
set ( CMAKE_BUILD_TYPE Debug )

add_executable( main
	src/main.cpp
	src/fibonacci.cpp
	src/vecteur3.cpp
)

# Tests unitaires
find_package( PkgConfig REQUIRED )
pkg_check_modules( PKG REQUIRED cpputest )
include_directories( ${PKG_INCLUDE_DIRS} )
add_executable( main_test
	src/main_test.cpp
	src/fibonacci.cpp
	src/fibonacci_test.cpp
	src/vecteur3.cpp
	src/vecteur3_test.cpp
)
target_link_libraries ( main_test ${PKG_LIBRARIES} )

#Incase anyone ever comes across this one day, the use of this txt file is it acts as a project manager that cooordinates your c++ files into a single runnning program.
#It automates the compilation process
#aswell as platform independence

cmake_minimum_required(VERSION 3.10)
project(Owl-C VERSION 0.1.0)

#used c++17 cause it has modern features that will save me alot of time.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

add_executable(owlc
		src/main.cpp
		src/lexer.cpp
)

cmake_minimum_required(VERSION 3.12)
project(ex2)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex2 main.cpp interface..h myEmplyee.cpp myEmplyee.h IDfactory.cpp IDfactory.h myPlane.cpp myPlane.h myFlight.cpp myFlight.h myCustomer.cpp myCustomer.h myReservation.cpp myReservation.h Date.cpp Writer.cpp Writer.h MyImplementation.h Reader.cpp Reader.h Valid.cpp Valid.h MyImplementation.cpp)
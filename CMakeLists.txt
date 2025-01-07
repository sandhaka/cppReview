cmake_minimum_required(VERSION 3.30)
project(cppReview)

set(CMAKE_CXX_STANDARD 20)

add_executable(cppReview main.cpp
        Shapes/Shape.h
        Shapes/Rectangle.cpp
        Shapes/Rectangle.h
        Shapes/Square.cpp
        Shapes/Square.h
        Shapes/NotDerivedRectangle.h
        Templates/ArrayOf2.h
        Templates/Swap12.h
        Templates/Ratio.h
        Templates/Specialization/Ratio.h
)

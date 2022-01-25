cmake_minimum_required(VERSION 3.21)
project(SCA)

set(CMAKE_CXX_STANDARD 20)

include_directories(Include/)
add_executable(SCA main.cpp Include/SCA/Resources/Resources.hpp Include/SCA/Resources/ManagedResource.hpp Include/SCA/Resources/Utils.hpp Include/SCA/Resources/Text/TextResource.hpp Include/SCA/Utils/Delegate/IDelegate.hpp Include/SCA/Utils/Delegate/MethodDelegate.hpp)

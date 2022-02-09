cmake_minimum_required(VERSION 3.21)
project(SCA)

set(CMAKE_CXX_STANDARD 20)

include_directories(Include/)
add_executable(SCA main.cpp Include/SCA/Resources/Utils.hpp Include/SCA/Utils/Delegate/IDelegate.hpp Include/SCA/Utils/Delegate/MethodDelegate.hpp Include/SCA/Resources/Resource/Resource.hpp Include/SCA/Resources/Resource/ResourceData.hpp Include/SCA/Resources/Resource/Metainfo.hpp)

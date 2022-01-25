//
// Created by anton on 1/14/22.
//

#ifndef SCA_MACRO_HPP
#define SCA_MACRO_HPP

#define getter(...) { return __VA_ARGS__; }
#define setter(TargetVarName, ...) { TargetVarName = __VA_ARGS__; }

#endif //SCA_MACRO_HPP

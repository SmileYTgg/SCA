//
// Created by anton on 1/22/22.
//

#ifndef SCA_UTILS_HPP
#define SCA_UTILS_HPP

// --- Macro ---
/// Trivial getter ( just copy of ::getter() )
#define managed_getter(...) getter(__VA_ARGS__)

/// Trivial setter for a managed field ( automatically emits OnChanged event )
#define managed_setter(FieldId, TargetVarName, ...) { if (TargetVarName != (__VA_ARGS__)) emitOnChanged(FieldId); TargetVarName = __VA_ARGS__; }

#endif //SCA_UTILS_HPP

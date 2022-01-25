//
// Created by anton on 1/26/22.
//

#ifndef SCA_METHODDELEGATE_HPP
#define SCA_METHODDELEGATE_HPP

#include "IDelegate.hpp"
#include <type_traits>

namespace SCA {
    /**
     * \brief Delegate that forwards calls to the method ( that's compatible with the delegate signature )
     * @tparam Owner Type of the method owner
     * @tparam Ret Type that a delegate will return
     * @tparam Args Delegate signature
     */
    template <typename Owner, typename Ret, typename... Args>
    struct MethodDelegate : public IDelegate<Ret, Args...> {
        Ret(Owner::*method)(Args...);
        Owner &owner;

        MethodDelegate(Ret(Owner::*method)(Args...), Owner &owner) : method(method), owner(owner) { }

        // -- Operators --
        Ret operator()(Args... args) override {
            return (owner.*method)(std::forward<Args>(args)...);
        }
    };
}

#endif //SCA_METHODDELEGATE_HPP

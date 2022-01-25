//
// Created by anton on 1/26/22.
//

#ifndef SCA_IDELEGATE_HPP
#define SCA_IDELEGATE_HPP

namespace SCA {
    /**
     * \brief Basic interface for every delegate
     * @tparam Ret Type that a delegate will return
     * @tparam Args Delegate signature
     */
    template <typename Ret, typename... Args>
    struct IDelegate {
        virtual Ret operator()(Args...) = 0;
    };
}

#endif //SCA_IDELEGATE_HPP

//
// Created by anton on 1/22/22.
//

#ifndef SCA_RESOURCES_HPP
#define SCA_RESOURCES_HPP

#include <SCA/Utils/Macro.hpp>

#include <string>
#include <vector>

namespace SCA::Resources {
    class Resources {
        std::string root_;
        uint changedInstances_;

        std::vector <ManagedResource *> resources_;

    public:
        Resources() = default;

        // -- Modifiers --
        // -- Import

        // -- Export
        // -- Save/Load

        // -- Getters --
        bool isSaveable()            const noexcept getter(root_.empty());
        uint countChangedInstances() const noexcept getter(changedInstances_);
    };
}

#endif //SCA_RESOURCES_HPP

//
// Created by anton on 1/22/22.
//

#ifndef SCA_RESOURCES_HPP
#define SCA_RESOURCES_HPP

#include <SCA/Utils/Macro.hpp>
#include <SCA/Utils/Delegate/MethodDelegate.hpp>

#include <string>
#include <map>

namespace SCA::Resources {
    class Resources {
        std::string root_;
        uint changedInstances_;

        std::map <std::string, ManagedResource *> resources_;

    public:
        Resources() = default;

        // -- Modifiers --
        // -- Import

        // -- Export
        // -- Save/Load

        // -- Getters --
        bool isSaveable()            const noexcept getter(root_.empty());
        uint countChangedInstances() const noexcept getter(changedInstances_);

    protected:
        void onChangedListener(uint fieldId, ManagedResource *res) {
            std::cout << "Hello: " << fieldId << '\n';
        }

        MethodDelegate<Resources, void, uint, ManagedResource*> onChanged_ {&Resources::onChangedListener, *this};
    };
}

#endif //SCA_RESOURCES_HPP

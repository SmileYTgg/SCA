//
// Created by anton on 1/22/22.
//

#ifndef SCA_MANAGEDRESOURCE_HPP
#define SCA_MANAGEDRESOURCE_HPP

#include "Utils.hpp"

#include <SCA/Utils/Macro.hpp>
#include <string>
#include <utility>

namespace SCA::Resources {
    /**
     * \brief Class that implements basic API for a managed resource
     * \details Encapsulates OnChanged event + resource name property
     */
    class ManagedResource {
    protected:
        void(*onChanged_)(int) = nullptr;
        std::string name_;

    public:
        ManagedResource(std::string name) noexcept : name_(std::move(name)) {

        }

        // -- Modifiers --
        virtual inline void emitOnChanged(int fieldID) const noexcept {
            if (onChanged_) onChanged_(0);
        }

        // -- Setters --
        virtual void setName(const std::string &name) noexcept managed_setter(0, name_, name);

        // -- Getters --
        virtual const std::string &name() const noexcept managed_getter(name_);
        virtual constexpr uint8_t type()  const          managed_getter(0);

        virtual ManagedResource clone()   const noexcept managed_getter({name_});
        virtual bool areChangesListened() const noexcept managed_getter(onChanged_ != nullptr);

        // -- Operators --
        ManagedResource operator=(const ManagedResource &) noexcept = delete;

    protected:
        // -- Resources management mechanizm --
        virtual void bindOnChanged(void(*callback)(int)) noexcept setter(onChanged_, callback)
        virtual bool unbindOnChanged(void(*callback)(int)) noexcept {
            onChanged_ = nullptr;
            return true;
        }

        friend class Resources;
    };
}

#endif //SCA_MANAGEDRESOURCE_HPP

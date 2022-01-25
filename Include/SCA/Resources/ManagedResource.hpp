//
// Created by anton on 1/22/22.
//

#ifndef SCA_MANAGEDRESOURCE_HPP
#define SCA_MANAGEDRESOURCE_HPP

#include "Utils.hpp"

#include <SCA/Utils/Macro.hpp>
#include "SCA/Utils/Delegate/IDelegate.hpp"
#include <string>
#include <utility>

namespace SCA::Resources {
    /**
     * \brief Class that implements basic API for a managed resource
     * \details Encapsulates OnChanged event + resource name property
     */
    class ManagedResource {
        typedef IDelegate<void, uint, ManagedResource *> OnChangedSignature;

    protected:
        OnChangedSignature *onChanged_; ///< void(fieldId, self)
        std::string name_;

    public:
        ManagedResource(std::string name) noexcept : name_(std::move(name)) {

        }

        // -- Modifiers --
        virtual inline void emitOnChanged(uint fieldID) noexcept {
            if (onChanged_) onChanged_->operator()(fieldID, this);
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
        virtual void bindOnChanged(OnChangedSignature *listener) noexcept setter(onChanged_, listener)
        virtual bool unbindOnChanged(OnChangedSignature *listener) noexcept {
            onChanged_ = nullptr;
            return true;
        }

        friend class Resources;
    };
}

#endif //SCA_MANAGEDRESOURCE_HPP

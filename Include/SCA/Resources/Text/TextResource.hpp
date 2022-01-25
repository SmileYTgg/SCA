//
// Created by anton on 1/22/22.
//

#ifndef SCA_TEXTRESOURCE_HPP
#define SCA_TEXTRESOURCE_HPP

#include <SCA/Resources/ManagedResource.hpp>
#include <utility>

namespace SCA::Resources {
    /**
     * \brief Plain-text resource
     * \details Representation of UTF8-compatible plain text resource
     */
    class TextResource : public ManagedResource {
        std::string content_;

    public:
        TextResource(const std::string &filename, std::string content) noexcept
             : ManagedResource(filename), content_(std::move(content)) {

        }

        // -- Setters --
        void setContent(const std::string &content) noexcept managed_setter(1, content_, content);

        // -- Getters --
        const std::string &content() const noexcept managed_getter(content_);
        uint length()                const noexcept managed_getter(content_.length());
    };
}

#endif //SCA_TEXTRESOURCE_HPP

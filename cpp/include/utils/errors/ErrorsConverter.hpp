#pragma once

#include "../../interface/InterfaceErrors.hpp"

#include <string>

// Errors converter
namespace faceless::utils::errors {

// Basic template for errors to string convertation
template <typename E>
[[nodiscard]] constexpr std::string toString(E err) noexcept = delete;

// Converter for InterfaceError
template <>
[[nodiscard]] constexpr std::string toString<faceless::interface::errors::InterfaceError>(faceless::interface::errors::InterfaceError err) noexcept {
    switch (err) {
        case faceless::interface::errors::InterfaceError::UnknownCommand:
            return "Unknown command. Write [help] to get more info.\n";
        
        case faceless::interface::errors::InterfaceError::InvalidCommandFormat:
            return "Invalid command format. Write [help] to get more info.\n";
        
        default:
            [[unlikely]];
            return "Unknown interface error.\n";
    }
}

} // namespace faceless::utils::errors

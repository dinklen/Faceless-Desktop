#pragma once

#include "../StateContext.hpp"

#include <memory>
#include <string>
#include <expected>

namespace faceless::interface::states {

// Welcome page state class
class WelcomePageState final: public faceless::interface::context::StateContext {
public:
    // Welcome page state methods
    explicit WelcomePageState() = default;

    WelcomePageState(const WelcomePageState&) = delete;
    WelcomePageState& operator=(const WelcomePageState&) = delete;

    WelcomePageState(WelcomePageState&&) = default;
    WelcomePageState& operator=(WelcomePageState&&) = default;

    // Virtual methods
    void display() override;

    std::expected<std::unique_ptr<faceless::interface::context::StateContext>, faceless::interface::errors::InterfaceError> handler(std::string input) override;

    constexpr faceless::interface::context::StateType getType() const noexcept override {
        return faceless::interface::context::StateType::Welcome;
    }
};

} // namespace faceless::interface::states

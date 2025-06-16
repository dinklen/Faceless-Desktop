#pragma once

#include "../StateContext.hpp"

#include <memory>
#include <string>

// Welcome page state class
class WelcomePageState final: public StateContext {
public:
    // Welcome page state methods
    explicit WelcomePageState() = default;

    WelcomePageState(const WelcomePageState&) = delete;
    WelcomePageState& operator=(const WelcomePageState&) = delete;

    WelcomePageState(WelcomePageState&&) = default;
    WelcomePageState& operator=(WelcomePageState&&) = default;

    // Virtual methods
    void display() override;

    std::unique_ptr<StateContext> handler(std::string input) override;

    constexpr StateType getType() const noexcept override {
        return StateType::Welcome;
    }
};

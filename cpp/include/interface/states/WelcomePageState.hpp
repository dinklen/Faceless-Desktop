#pragma once

#include "../StateContext.hpp"

#include <memory>
#include <string>

// Welcome page state class
class WelcomePageState: public StateContext {
public:
    void display() override;
    std::unique_ptr<StateContext> handler(std::string input) override;
};

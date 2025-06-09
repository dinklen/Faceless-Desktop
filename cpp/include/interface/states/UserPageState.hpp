#pragma once

#include "../StateContext.hpp"

#include <memory>
#include <string>

// User page state class
class UserPageState: public StateContext {
public:
    // Get a nick when the state creating
    UserPageState(const std::string& nickname): nickname_(nickname) {}

    void display() override;
    std::unique_ptr<StateContext> handler(std::string input) override;

private:
    // User data
    std::string nickname_;
};

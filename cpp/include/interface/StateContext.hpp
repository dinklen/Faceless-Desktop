#pragma once

#include <string>
#include <memory>

// Basic state class
class StateContext {
public:
    virtual ~StateContext() = default;

    // States print function
    virtual void display() = 0;

    // States handler
    virtual std::unique_ptr<StateContext> handler(std::string input) = 0;
};

// States types
enum class StateType {
    Welcome,
    User
};

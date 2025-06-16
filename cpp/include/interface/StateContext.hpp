#pragma once

#include <string>
#include <memory>
#include <unordered_map>

// States types
enum class StateType {
    Welcome,
    User,
    Chat
};

// Basic state class
class StateContext {
public:
    virtual ~StateContext() = default;

    // States pool
    static std::unordered_map<StateType, std::unique_ptr<StateContext>>& getStatePool();

    // States print function
    virtual void display() = 0;

    // States handler
    virtual std::unique_ptr<StateContext> handler(std::string input) = 0;
    
    // State type info
    virtual constexpr StateType getType() const noexcept = 0;
};

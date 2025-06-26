#pragma once

#include "InterfaceErrors.hpp"

#include <string>
#include <memory>
#include <unordered_map>
#include <expected>

namespace faceless::interface::context {

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
    virtual std::expected<std::unique_ptr<StateContext>, faceless::interface::errors::InterfaceError> handler(std::string input) = 0;
    
    // State type info
    virtual constexpr StateType getType() const noexcept = 0;
};

} // namespace faceless::interface::context

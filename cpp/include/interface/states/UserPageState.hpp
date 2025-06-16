#pragma once

#include "../StateContext.hpp"

#include "../../models/user/UserModel.hpp"

#include <memory>
#include <string>

// User page state class
class UserPageState final: public StateContext {
public:
    // Get a nick when the state creating | User page state methods
    explicit UserPageState(std::unique_ptr<User> account): account_(std::move(account)) {}

    UserPageState(const UserPageState&) = delete;
    UserPageState& operator=(const UserPageState&) = delete;

    UserPageState(UserPageState&&) = default;
    UserPageState& operator=(UserPageState&&) = default;
    
    // Virtual methods
    void display() override;

    std::unique_ptr<StateContext> handler(std::string input) override;

    constexpr StateType getType() const noexcept override {
        return StateType::User;
    }

private:
    // User account
    std::unique_ptr<User> account_;
};

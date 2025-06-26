#pragma once

#include "../StateContext.hpp"

#include "../../models/user/UserModel.hpp"

#include <memory>
#include <string>
#include <expected>

namespace faceless::interface::states {

// User page state class
class UserPageState final: public faceless::interface::context::StateContext {
public:
    // Get a nick when the state creating | User page state methods
    explicit UserPageState(std::unique_ptr<faceless::models::user::User> account): account_(std::move(account)) {}

    UserPageState(const UserPageState&) = delete;
    UserPageState& operator=(const UserPageState&) = delete;

    UserPageState(UserPageState&&) = default;
    UserPageState& operator=(UserPageState&&) = default;
    
    // Virtual methods
    void display() override;

    std::expected<std::unique_ptr<faceless::interface::context::StateContext>, faceless::interface::errors::InterfaceError> handler(std::string input) override;

    constexpr faceless::interface::context::StateType getType() const noexcept override {
        return faceless::interface::context::StateType::User;
    }

private:
    // User account
    std::unique_ptr<faceless::models::user::User> account_;
};

} // namespace faceless::interface::states

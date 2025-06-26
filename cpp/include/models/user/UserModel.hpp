#pragma once

#include <string>

namespace faceless::models::user {

// User data class
class User final {
public:
    explicit User(const std::string nickname): nickname_(nickname) {}

    std::string getNickname() const;

private:
    // User nickname
    std::string nickname_;
};

} // namespace faceless::models::user

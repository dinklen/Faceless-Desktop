#pragma once

#include <string>

// User data class
class User {
public:
    explicit User(const std::string nickname): nickname_(nickname) {}

    std::string getNickname() const;

private:
    // User nickname
    std::string nickname_;
};

#include "../../../include/models/user/UserModel.hpp"

#include <string>

// Nickname getter
std::string User::getNickname() const {
    return nickname_;
}

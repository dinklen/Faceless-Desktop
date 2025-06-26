#include "../../../include/models/user/UserModel.hpp"

#include <string>

namespace faceless::models::user {

// Nickname getter
std::string User::getNickname() const {
    return nickname_;
}

} // namespace faceless::models::user

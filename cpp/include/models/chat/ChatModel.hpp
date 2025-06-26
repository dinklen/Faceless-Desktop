#pragma once

#include "../message/MessageModel.hpp"
#include "../user/UserModel.hpp"

#include <vector>

namespace faceless::models::chat { // ! without ::chat?

// Chat types
enum class ChatType {
    Personal,
    OneOnOne,
    Group,
    Chanell
};

class Chat final {
public:
    Chat(ChatType type, std::vector<faceless::models::user::User> members): type_(type), members_(members) {}

    // Getters
    ChatType getType() const;
    std::vector<faceless::models::user::User> getMembers() const;
    std::vector<faceless::models::message::Message> getHistory() const; // Add message timeline

    // ! Get info struct?

private:
    // Chat configuration
    ChatType type_;
    std::vector<faceless::models::user::User> members_;
    std::vector<faceless::models::message::Message> history_;
    // name
    // description
    // password
};

} // namespace faceless::models::chat

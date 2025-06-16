#pragma once

#include "../message/MessageModel.hpp"
#include "../user/UserModel.hpp"

#include <vector>

// Chat types
enum class ChatType {
    Personal,
    OneOnOne,
    Group,
    Chanell
};

class Chat {
public:
    Chat(ChatType type, std::vector<User> members): type_(type), members_(members) {}

    // Getters
    ChatType getType() const;
    std::vector<User> getMembers() const;
    std::vector<Message> getHistory() const; // Add message timeline

    // ! Get info struct?

private:
    // Chat configuration
    ChatType type_;
    std::vector<User> members_;
    std::vector<Message> history_;
    // name
    // description
    // password
};
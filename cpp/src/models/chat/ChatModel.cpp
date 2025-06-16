#include "../../../include/models/chat/ChatModel.hpp"
#include "../../../include/models/user/UserModel.hpp"
#include "../../../include/models/message/MessageModel.hpp"

#include <vector>

// ! temp. Replace to data struct
ChatType Chat::getType() const {
    return type_;
}

std::vector<User> Chat::getMembers() const {
    return members_;
}

std::vector<Message> Chat::getHistory() const {
    return history_;
}

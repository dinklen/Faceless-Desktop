#include "../../../include/models/chat/ChatModel.hpp"
#include "../../../include/models/user/UserModel.hpp"
#include "../../../include/models/message/MessageModel.hpp"

#include <vector>

// Declare short namespaces names
namespace models = faceless::models;

namespace faceless::models::chat {

// ! temp. Replace to data struct
ChatType Chat::getType() const {
    return type_;
}

std::vector<models::user::User> Chat::getMembers() const {
    return members_;
}

std::vector<models::message::Message> Chat::getHistory() const {
    return history_;
}

} // namespace faceless::models::chat

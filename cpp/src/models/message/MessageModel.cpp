#include "../../../include/models/message/MessageModel.hpp"

#include <vector>
#include <string>

namespace faceless::models::message {

// ! temp. Replace to data struct
MessageType Message::getType() const {
    return type_;
}

std::string Message::getInfo() const {
    return info_;
}

} // namespace faceless::models::message

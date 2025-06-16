#include "../../../include/models/message/MessageModel.hpp"

#include <vector>
#include <string>

// ! temp. Replace to data struct
MessageType Message::getType() const {
    return type_;
}

std::string Message::getInfo() const {
    return info_;
}

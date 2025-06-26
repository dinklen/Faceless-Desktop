#pragma once

#include <string>

namespace faceless::models::message {

// Message types
enum class MessageType {
    Text,
    Audio,
    Video,
    Document
};

// Message class
class Message final {
public:
    Message(MessageType type, std::string info): type_(type), info_(info) {}

    MessageType getType() const;
    std::string getInfo() const;

private:
    MessageType type_;
    std::string info_; // ! temp. Replace to struct
};

} // namespace faceless::models::message

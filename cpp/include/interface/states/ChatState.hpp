#pragma once

#include "../StateContext.hpp"

#include "../../models/chat/ChatModel.hpp"

#include <memory>
#include <string>
#include <expected>

namespace faceless::interface::states {

// Chat state class
class ChatState final: public faceless::interface::context::StateContext {
public:
    // Chat state methods
    explicit ChatState(): chat_(std::move(nullptr)) {}

    ChatState(const ChatState&) = delete;
    ChatState& operator=(const ChatState&) = delete;

    ChatState(ChatState&&) = default;
    ChatState& operator=(ChatState&&) = default;

    // Chat move method
    void changeChat(std::unique_ptr<faceless::models::chat::Chat> newChat);

    // Virtual methods
    void display() override;

    std::expected<std::unique_ptr<faceless::interface::context::StateContext>, faceless::interface::errors::InterfaceError> handler(std::string input) override;
    
    constexpr faceless::interface::context::StateType getType() const noexcept override {
        return faceless::interface::context::StateType::Chat;
    }

private:
    // Chat pointer
    std::unique_ptr<faceless::models::chat::Chat> chat_;
};

} // namespace faceless::interface::states

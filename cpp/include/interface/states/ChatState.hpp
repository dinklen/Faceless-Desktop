#pragma once

#include "../StateContext.hpp"

#include "../../models/chat/ChatModel.hpp"

#include <memory>

// Chat state class
class ChatState final: public StateContext {
public:
    // Chat state methods
    explicit ChatState(): chat_(std::move(nullptr)) {}

    ChatState(const ChatState&) = delete;
    ChatState& operator=(const ChatState&) = delete;

    ChatState(ChatState&&) = default;
    ChatState& operator=(ChatState&&) = default;

    // Chat move method
    void changeChat(std::unique_ptr<Chat> newChat);

    // Virtual methods
    void display() override;

    std::unique_ptr<StateContext> handler(std::string input) override;
    
    constexpr StateType getType() const noexcept override {
        return StateType::Chat;
    }

private:
    // Chat pointer
    std::unique_ptr<Chat> chat_;
};

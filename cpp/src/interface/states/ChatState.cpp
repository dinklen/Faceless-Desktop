#include "../../../include/interface/StateContext.hpp"
#include "../../../include/interface/states/ChatState.hpp"
#include "../../../include/interface/cmd_manager/CommandManager.hpp"

#include "../../utils/parser/StringParser.hpp"

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

// Change chat method
void ChatState::changeChat(std::unique_ptr<Chat> newChat) {
    chat_ = std::move(newChat);
}

// Display method
void ChatState::display() {
    std::cout << "you> "; // ! temp. Print sender name
}

// State handler
std::unique_ptr<StateContext> ChatState::handler(std::string input) {
    const auto& commands = CommandManager::getInstance().getCommands(StateType::Chat);

    std::vector<std::string> args = parser::parseChatCommand(input);

    if (args.empty()) {
        // Send function will be here
        return nullptr;
    }

    auto it = commands.find(args[0]);
    if (it != std::end(commands)) {
        return it->second(args);
    }
    
    std::cerr << "Unknown command. Use [help] to get more info about commands" << std::endl; // ! temp. Replace to error
    return nullptr;
}

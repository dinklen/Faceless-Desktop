#include "../../../include/interface/StateContext.hpp"
#include "../../../include/interface/states/ChatState.hpp"
#include "../../../include/interface/cmd_manager/CommandManager.hpp"
#include "../../../include/interface/InterfaceErrors.hpp"

#include "../../../include/models/chat/ChatModel.hpp"

#include "../../../include/utils/parser/StringParser.hpp"

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <iostream>
#include <unordered_map>
#include <expected>

// Declare short namespaces names
namespace context = faceless::interface::context;
namespace states = faceless::interface::states;
namespace cmd_manager = faceless::interface::cmd_manager;
namespace models = faceless::models;
namespace utils = faceless::utils;
namespace i_errors = faceless::interface::errors;

namespace faceless::interface::states {

// Change chat method
void ChatState::changeChat(std::unique_ptr<models::chat::Chat> newChat) {
    chat_ = std::move(newChat);
}

// Display method
void ChatState::display() {
    std::cout << "you> "; // ! temp. Print sender name
}

// State handler
std::expected<std::unique_ptr<context::StateContext>, i_errors::InterfaceError> ChatState::handler(std::string input) {
    const auto& commands = cmd_manager::CommandManager::getInstance().getCommands(context::StateType::Chat);

    std::vector<std::string> args = utils::parser::parseChatCommand(input);

    if (args.empty()) {
        // Send function will be here
        return nullptr;
    }

    if (auto it = commands.find(args[0]); it != std::end(commands)) {
        return it->second(args);
    }
    
    return std::unexpected(i_errors::InterfaceError::UnknownCommand);
}

} // namespace faceless::interface::states

#include "../../../include/interface/StateContext.hpp"
#include "../../../include/interface/states/UserPageState.hpp"
#include "../../../include/interface/cmd_manager/CommandManager.hpp"

#include "../../../include/utils/parser/StringParser.hpp"

#include <memory>
#include <string>
#include <vector>
#include <expected>
#include <iostream>
#include <unordered_map>

namespace context = faceless::interface::context;
namespace cmd_manager = faceless::interface::cmd_manager;
namespace utils = faceless::utils;
namespace i_errors = faceless::interface::errors;

namespace faceless::interface::states {

// Display method
void UserPageState::display() {
    std::cout << account_->getNickname() + "> ";
}

// State handler
std::expected<std::unique_ptr<context::StateContext>, i_errors::InterfaceError> UserPageState::handler(std::string input) {
    const auto& commands = cmd_manager::CommandManager::getInstance().getCommands(context::StateType::User);

    std::vector<std::string> args = utils::parser::parseHandlerInput(input);

    if (args.empty()) {
        return std::unexpected(i_errors::InterfaceError::UnknownCommand);
    }

    if (auto it = commands.find(args[0]); it != std::end(commands)) {
        return it->second(args);
    }
    
    return std::unexpected(i_errors::InterfaceError::UnknownCommand);
}

} // namespace faceless::interface::states

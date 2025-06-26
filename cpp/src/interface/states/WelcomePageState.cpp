#include "../../../include/interface/StateContext.hpp"
#include "../../../include/interface/states/WelcomePageState.hpp"
#include "../../../include/interface/cmd_manager/CommandManager.hpp"

#include "../../../include/utils/parser/StringParser.hpp"

#include <memory>
#include <string>
#include <vector>
#include <expected>
#include <iostream>
#include <unordered_map>

// Declare short namespaces names
namespace context = faceless::interface::context;
namespace cmd_manager = faceless::interface::cmd_manager;
namespace utils = faceless::utils;
namespace i_errors = faceless::interface::errors;

namespace faceless::interface::states {

// Display method
void WelcomePageState::display() {
    std::cout << "welcome_page> ";
}

// State handler
std::expected<std::unique_ptr<context::StateContext>, i_errors::InterfaceError> WelcomePageState::handler(std::string input) {
    const auto& commands = cmd_manager::CommandManager::getInstance().getCommands(context::StateType::Welcome);

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

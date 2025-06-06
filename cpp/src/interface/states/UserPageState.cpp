#include "../../../include/interface/StateContext.hpp"
#include "../../../include/interface/states/UserPageState.hpp"
#include "../../../include/interface/cmd_manager/CommandManager.hpp"

#include "../../utils/parser/StringParser.hpp"

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

// Display method
void UserPageState::display() {
    //std::cout << nickname_ + "> ";
    std::cout << "user_nick> ";
}

// State handler
std::unique_ptr<StateContext> UserPageState::handler(std::string input) {
    const auto& commands = CommandManager::getInstance().getCommands(StateType::User);

    std::vector<std::string> args = parser::parseInput(input);

    if (args.empty()) {
        std::cerr << "Invalid input. Use [help] to get more info about commands" << std::endl; // ! temp. Replace to error
        return nullptr;
    }

    auto it = commands.find(args[0]);
    if (it != std::end(commands)) {
        return it->second(args);
    }
    std::cerr << "Unknown command. Use [help] to get more info about commands" << std::endl; // ! temp. Replace to error
    return nullptr;
}

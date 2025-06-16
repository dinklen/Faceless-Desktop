#pragma once

#include <vector>
#include <string>

// Parser methods
namespace parser {
    // Handler strings parser
    std::vector<std::string> parseHandlerInput(std::string input);

    // Chat commands parser
    std::vector<std::string> parseChatCommand(std::string input);
};

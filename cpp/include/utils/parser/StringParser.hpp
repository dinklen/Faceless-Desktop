#pragma once

#include <vector>
#include <string>

// Parser methods
namespace faceless::utils::parser {

// Handler strings parser
inline std::vector<std::string> parseHandlerInput(std::string input) {
    std::vector<std::string> output;
    
    size_t pos = 0;

    while ((pos = input.find(' ')) != std::string::npos) {
        output.push_back(input.substr(0, pos));
        input.erase(0, pos+1);
    }
    if (!input.empty()) output.push_back(input);

    return output;
}

// Chat commands parser
inline std::vector<std::string> parseChatCommand(std::string input) {
    std::vector<std::string> output;

    if (std::size(input) > 2 && input.front() == '{' && input.back() == '}') {
        output.push_back(input.substr(1, std::size(input)-2));
    }
    
    return output;
}

} // namespace faceless::utils::parser

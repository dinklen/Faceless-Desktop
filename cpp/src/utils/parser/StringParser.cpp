#include "StringParser.hpp"

#include <vector>
#include <string>
#include <algorithm>

// Handler input parser
std::vector<std::string> parser::parseHandlerInput(std::string input) {
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
std::vector<std::string> parser::parseChatCommand(std::string input) {
    std::vector<std::string> output;

    if (std::size(input) > 2 && input.front() == '{' && input.back() == '}') {
        output.push_back(input.substr(1, std::size(input)-2));
    }
    return output;
}

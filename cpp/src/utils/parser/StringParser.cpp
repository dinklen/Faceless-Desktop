#include "StringParser.hpp"

#include <vector>
#include <string>

// Input strings parser method
std::vector<std::string> parser::parseInput(std::string input) {
    std::vector<std::string> output;
    
    size_t pos = 0;
    std::string token;

    while ((pos = input.find(' ')) != std::string::npos) {
        output.push_back(input.substr(0, pos));
        input.erase(0, pos+1);
    }
    if (!input.empty()) output.push_back(input);

    return output;
}

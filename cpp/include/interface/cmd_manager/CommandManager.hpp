#pragma once

#include "../StateContext.hpp"

#include <unordered_map>
#include <functional>
#include <vector>
#include <memory>
#include <string>

// States commands manager
class CommandManager {
public:
    using CommandFunc = std::function<std::unique_ptr<StateContext>(const std::vector<std::string>&)>;

public:
    // Singletone
    static CommandManager& getInstance();

    // Get states commands by state type
    const std::unordered_map<std::string, CommandFunc>& getCommands(StateType state);

private:
    // Singletone methods
    CommandManager();
    ~CommandManager() = default;

    CommandManager(const CommandManager&) = delete;
    CommandManager& operator=(const CommandManager&) = delete;

    // Singletone copy
    static std::unique_ptr<CommandManager> instance_;
    
    // States commands storage
    std::unordered_map<StateType, std::unordered_map<std::string, CommandFunc>> stateCommands_;
};

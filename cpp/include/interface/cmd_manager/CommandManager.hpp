#pragma once

#include "../StateContext.hpp"
#include "../InterfaceErrors.hpp"

#include <unordered_map>
#include <functional>
#include <vector>
#include <memory>
#include <string>
#include <expected>

namespace faceless::interface::cmd_manager {

// States commands manager
class CommandManager {
public:
    using CommandFunc = std::function<std::expected<std::unique_ptr<faceless::interface::context::StateContext>, faceless::interface::errors::InterfaceError>(const std::vector<std::string>&)>;

public:
    // Singletone
    static CommandManager& getInstance();

    // Get states commands by state type
    const std::unordered_map<std::string, CommandFunc>& getCommands(faceless::interface::context::StateType state);

private:
    // Singletone methods
    CommandManager();
    ~CommandManager() = default;

    CommandManager(const CommandManager&) = delete;
    CommandManager& operator=(const CommandManager&) = delete;
    
    // States commands storage
    std::unordered_map<faceless::interface::context::StateType, std::unordered_map<std::string, CommandFunc>> stateCommands_;
};

} // namespace faceless::interface::cmd_manager

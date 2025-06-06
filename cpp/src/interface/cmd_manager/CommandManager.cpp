#include "../../../include/interface/cmd_manager/CommandManager.hpp"
#include "../../../include/interface/StateContext.hpp"
#include "../../../include/interface/states/UserPageState.hpp"
#include "../../../include/interface/states/WelcomePageState.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

// Static initializer. Singletone
CommandManager& CommandManager::getInstance() {
    static CommandManager instance_;
    return instance_;
}

// Private constructor. Register states commands
CommandManager::CommandManager() {
    // Welcome page state commands
    stateCommands_[StateType::Welcome] = {
        {"help", [](const std::vector<std::string>&) -> std::unique_ptr<StateContext> {
            std::cout << "Commands:\n"
            << "[help] - use it to get more info about commands\n"
            << "[sign_up] - use it to create new account\n"
            << "[start_session] - use it to start new session on this device\n"
            << "[quit] - use it to quit\n"
            << "---\nFor more info use [help <command>]\n"
            << std::endl;

            return nullptr;
        }},

        {"sign_up", [](const std::vector<std::string>& args) -> std::unique_ptr<StateContext> {
            if (std::size(args) < 3) {
                std::cerr << "Invalid command format. For more info use [help <command>]" << std::endl; // ! Replace to struct errors
                return nullptr;
            }
            std::cout << "Account created" << std::endl; // ! temp
            return nullptr;
        }},

        {"start_session", [](const std::vector<std::string>& args) -> std::unique_ptr<StateContext> {
            if (std::size(args) < 3) {
                std::cerr << "Usage: start <login> <password>" << std::endl; // ! Replace to struct errors
                return nullptr;
            }
            std::cout << "Login successful" << std::endl; // ! temp
            return std::make_unique<UserPageState>();
        }},

        {"quit", [](const std::vector<std::string>&) -> std::unique_ptr<StateContext> {
            std::cout << "Exiting..." << std::endl;
            exit(0); // ! temp. Replace to safety exit from starter
        }}
    };

    // User page state commands
    stateCommands_[StateType::User] = {
        {"help", [](const std::vector<std::string>&) -> std::unique_ptr<StateContext> {
            std::cout << "Commands:\n"
            << "[help] - use it to get more info about commands\n"
            << "[loc] - use it to get your current location\n"
            << "[quit] - use it to log out from this account\n"
            << "---\nFor more info use [help <command>]\n"
            << std::endl;

            return nullptr;
        }},

        {"loc", [](const std::vector<std::string>&) -> std::unique_ptr<StateContext> {
            std::cout << "*current location*\n" << std::endl; // ! temp
            return nullptr;
        }},

        {"quit", [](const std::vector<std::string>&) -> std::unique_ptr<StateContext> {
            std::cout << "Logging out...\n" << std::endl;
            return std::make_unique<WelcomePageState>();
        }}
    };
}

// The function that returns commands for the corresponding states
const std::unordered_map<std::string, CommandManager::CommandFunc>& CommandManager::getCommands(StateType state) {
    return stateCommands_[state];
}

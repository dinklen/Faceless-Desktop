#include "../../../include/interface/cmd_manager/CommandManager.hpp"
#include "../../../include/interface/StateContext.hpp"
#include "../../../include/interface/states/UserPageState.hpp"
#include "../../../include/interface/states/WelcomePageState.hpp"
#include "../../../include/interface/states/ChatState.hpp"

#include "../../../include/models/chat/ChatModel.hpp"
#include "../../../include/models/user/UserModel.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

// Static initializer. Singletone
CommandManager& CommandManager::getInstance() {
    static CommandManager instance;
    return instance;
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

            return std::move(nullptr);
        }},

        {"sign_up", [](const std::vector<std::string>& args) -> std::unique_ptr<StateContext> {
            if (std::size(args) != 3) {
                std::cerr << "Invalid command format. For more info use [help <command>]" << std::endl; // ! Replace to struct errors
                return std::move(nullptr);
            }
            std::cout << "Account created" << std::endl; // ! temp
            return std::move(nullptr);
        }},

        {"start_session", [](const std::vector<std::string>& args) -> std::unique_ptr<StateContext> {
            if (std::size(args) != 3) {
                std::cerr << "Usage: start <login> <password>" << std::endl; // ! Replace to struct errors
                return std::move(nullptr);
            }
            // Login logic will be here
            std::cout << "Login successful" << std::endl; // ! temp

            auto& pool = StateContext::getStatePool();
            if ((pool.find(StateType::User)) == std::end(pool)) {
                pool[StateType::User] = std::make_unique<UserPageState>(std::move(std::make_unique<User>(std::move(args[1]))));
            }

            return std::move(pool.find(StateType::User)->second);
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
            << "[open_chat] - use it to open a chat\n"
            << "[quit] - use it to log out from this account\n"
            << "---\nFor more info use [help <command>]\n"
            << std::endl;

            return std::move(nullptr);
        }},

        {"plinf", [](const std::vector<std::string>&) -> std::unique_ptr<StateContext> {
            std::cout << "*current location*\n" << std::endl; // ! temp
            return std::move(nullptr);
        }},

        // open
        // delete
        // change --name "gg" --description "rwe" --password "234"
        // deselect
        // settings
        // create --chat jfd --folder dfsa
        // goto <location>

        {"quit", [](const std::vector<std::string>&) -> std::unique_ptr<StateContext> {
            std::cout << "Logging out...\n" << std::endl;

            auto& pool = StateContext::getStatePool();
            return std::move(pool.find(StateType::Welcome)->second);
        }},

        {"open_chat", [](const std::vector<std::string>& args) -> std::unique_ptr<StateContext> {
            if (std::size(args) < 2) {
                std::cout << "Invalid command format. Usage [help] for more info." << std::endl;
                return std::move(nullptr);
            }
            
            // ! temp. Simulate chat creation. Should be taken from storage.
            User user("*nickname*");
            std::vector<User> users = {user};
            std::unique_ptr<Chat> chat = std::make_unique<Chat>(ChatType::Personal, users);

            auto& pool = StateContext::getStatePool();
            if ((pool.find(StateType::Chat)) == std::end(pool)) {
                pool[StateType::Chat] = std::make_unique<ChatState>();
            }
            
            if (auto* chatState = dynamic_cast<ChatState*>(pool.find(StateType::Chat)->second.get())) {
                chatState->changeChat(std::move(chat));
            }

            return std::move(pool.find(StateType::Chat)->second); // ! temp. SELECT field = chat info struct
        }}
    };

    // Chat commands
    stateCommands_[StateType::Chat] = {
        {"quit", [](const std::vector<std::string>&) -> std::unique_ptr<StateContext> {
            std::cout << "Closing..." << std::endl;

            auto& pool = StateContext::getStatePool();
            return std::move(pool.find(StateType::User)->second);
        }}
    };
}

// The function that returns commands for the corresponding states
const std::unordered_map<std::string, CommandManager::CommandFunc>& CommandManager::getCommands(StateType state) {
    return stateCommands_.find(state)->second; // !. Add errors
}

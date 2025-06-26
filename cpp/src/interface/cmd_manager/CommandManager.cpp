#include "../../../include/interface/cmd_manager/CommandManager.hpp"
#include "../../../include/interface/StateContext.hpp"
#include "../../../include/interface/states/UserPageState.hpp"
#include "../../../include/interface/states/WelcomePageState.hpp"
#include "../../../include/interface/states/ChatState.hpp"
#include "../../../include/interface/InterfaceErrors.hpp"

#include "../../../include/models/chat/ChatModel.hpp"
#include "../../../include/models/user/UserModel.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <expected>
#include <unordered_map>

// Declare short namespaces names
namespace context = faceless::interface::context;
namespace states = faceless::interface::states;
namespace models = faceless::models;
namespace i_errors = faceless::interface::errors;

namespace faceless::interface::cmd_manager {

// Static initializer. Singletone
CommandManager& CommandManager::getInstance() {
    static CommandManager instance;
    return instance;
}

// Private constructor. Register states commands
CommandManager::CommandManager() {
    // Welcome page state commands
    stateCommands_[context::StateType::Welcome] = {
        {"help", [](const std::vector<std::string>&) -> std::expected<std::unique_ptr<context::StateContext>, i_errors::InterfaceError> {
            std::cout << "Commands:\n"
            << "[help] - use it to get more info about commands\n"
            << "[sign_up] - use it to create new account\n"
            << "[start_session] - use it to start new session on this device\n"
            << "[quit] - use it to quit\n"
            << "---\nFor more info use [help <command>]\n"
            << std::endl;

            return std::move(nullptr);
        }},

        {"sign_up", [](const std::vector<std::string>& args) -> std::expected<std::unique_ptr<context::StateContext>, i_errors::InterfaceError> {
            if (std::size(args) != 3) {
                return std::unexpected(i_errors::InterfaceError::InvalidCommandFormat);
            }
            std::cout << "Account created" << std::endl; // ! temp
            return std::move(nullptr);
        }},

        {"start_session", [](const std::vector<std::string>& args) -> std::expected<std::unique_ptr<context::StateContext>, i_errors::InterfaceError> {
            if (std::size(args) != 3) {
                return std::unexpected(i_errors::InterfaceError::InvalidCommandFormat);
            }
            // Login logic will be here
            std::cout << "Login successful" << std::endl; // ! temp

            auto& pool = context::StateContext::getStatePool();
            if ((pool.find(context::StateType::User)) == std::end(pool)) {
                pool[context::StateType::User] = std::make_unique<states::UserPageState>(std::move(std::make_unique<models::user::User>(std::move(args[1]))));
            }

            return std::move(pool.find(context::StateType::User)->second);
        }},

        {"quit", [](const std::vector<std::string>&) -> std::expected<std::unique_ptr<context::StateContext>, i_errors::InterfaceError> {
            std::cout << "Exiting..." << std::endl;
            exit(0); // ! temp. Replace to safety exit from starter
        }}
    };

    // User page state commands
    stateCommands_[context::StateType::User] = {
        {"help", [](const std::vector<std::string>&) -> std::expected<std::unique_ptr<context::StateContext>, i_errors::InterfaceError> {
            std::cout << "Commands:\n"
            << "[help] - use it to get more info about commands\n"
            << "[loc] - use it to get your current location\n"
            << "[open_chat] - use it to open a chat\n"
            << "[quit] - use it to log out from this account\n"
            << "---\nFor more info use [help <command>]\n"
            << std::endl;

            return std::move(nullptr);
        }},

        {"plinf", [](const std::vector<std::string>&) -> std::expected<std::unique_ptr<context::StateContext>, i_errors::InterfaceError> {
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

        {"quit", [](const std::vector<std::string>&) -> std::expected<std::unique_ptr<context::StateContext>, i_errors::InterfaceError> {
            std::cout << "Logging out...\n" << std::endl;

            auto& pool = context::StateContext::getStatePool();
            return std::move(pool.find(context::StateType::Welcome)->second);
        }},

        {"open_chat", [](const std::vector<std::string>& args) -> std::expected<std::unique_ptr<context::StateContext>, i_errors::InterfaceError> {
            if (std::size(args) != 2) {
                return std::unexpected(i_errors::InterfaceError::InvalidCommandFormat);
            }
            
            // ! temp. Simulate chat creation. Should be taken from storage.
            models::user::User user("*nickname*");
            std::vector<models::user::User> users = {user};
            std::unique_ptr<models::chat::Chat> chat = std::make_unique<models::chat::Chat>(models::chat::ChatType::Personal, users);

            auto& pool = context::StateContext::getStatePool();
            if ((pool.find(context::StateType::Chat)) == std::end(pool)) {
                pool[context::StateType::Chat] = std::make_unique<states::ChatState>();
            }
            
            if (auto* chatState = dynamic_cast<states::ChatState*>(pool.find(context::StateType::Chat)->second.get())) {
                chatState->changeChat(std::move(chat));
            }

            return std::move(pool.find(context::StateType::Chat)->second); // ! temp. SELECT field = chat info struct
        }}
    };

    // Chat commands
    stateCommands_[context::StateType::Chat] = {
        {"quit", [](const std::vector<std::string>&) -> std::expected<std::unique_ptr<context::StateContext>, i_errors::InterfaceError> {
            std::cout << "Closing..." << std::endl;

            auto& pool = context::StateContext::getStatePool();
            return std::move(pool.find(context::StateType::User)->second);
        }}
    };
}

// The function that returns commands for the corresponding states
const std::unordered_map<std::string, CommandManager::CommandFunc>& CommandManager::getCommands(context::StateType state) {
    return stateCommands_.find(state)->second; // !. Add errors
}

} // namespace faceless::interface::cmd_manager

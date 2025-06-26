#include "../../../include/core/application/Application.hpp"

#include "../../../include/interface/StateContext.hpp"
#include "../../../include/interface/states/WelcomePageState.hpp"
#include "../../../include/interface/InterfaceErrors.hpp"

#include "../../../include/utils/errors/ErrorsConverter.hpp"

#include <iostream>
#include <memory>

// Declare short namespaces names
namespace context = faceless::interface::context;
namespace states = faceless::interface::states;
namespace i_errors = faceless::interface::errors;
namespace utils = faceless::utils;

namespace faceless::core::application {

// Static initializer. Singletone
Application& Application::getInstance() {
    static Application instance;
    return instance;
}

// When application starting
Application::Application() {
    std::cout << "Starting... ";

    auto& pool = context::StateContext::getStatePool();
    pool[context::StateType::Welcome] = std::make_unique<states::WelcomePageState>();
    currentState_ = std::move(pool.find(context::StateType::Welcome)->second);

    std::cout << "done" << std::endl;
}

// Event loop
[[noreturn]] void Application::run() {
    std::cout << "Faceless, v0.3.0\n"
    << "Write \"help\" to get more info\n"
    << std::endl;

    std::string input;
    std::unique_ptr<context::StateContext> newState{nullptr};
    while (true) {
        currentState_->display();
        std::getline(std::cin, input);

        if (auto result = currentState_->handler(input)) {
            newState = std::move(*result);
        } else {
            std::cerr << utils::errors::toString<i_errors::InterfaceError>(result.error()) << std::endl;
            continue; // Add logging
        }

        if (newState) {
            auto& pool = context::StateContext::getStatePool();
            pool[currentState_->getType()] = std::move(currentState_);
            currentState_ = std::move(newState);
        }
    }
}

// When application shutting down
Application::~Application() {
    std::cout << "Shutting down... ";
    // todo
    std::cout << "done" << std::endl;
}

} // namespace faceless::core::application

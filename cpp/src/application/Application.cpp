#include "Application.hpp"

#include "../../include/interface/StateContext.hpp"
#include "../../include/interface/states/WelcomePageState.hpp"

#include <iostream>
#include <memory>

// Static initializer. Singletone
Application& Application::getInstance() {
    static Application instance;
    return instance;
}

// When application starting
Application::Application() {
    std::cout << "Starting... ";

    auto& pool = StateContext::getStatePool();
    pool[StateType::Welcome] = std::make_unique<WelcomePageState>();
    currentState_ = std::move(pool.find(StateType::Welcome)->second);

    std::cout << "done" << std::endl;
}

// Event loop
void Application::run() {
    std::cout << "Faceless, v0.2.0\n"
    << "Write \"help\" to get more info\n"
    << std::endl;

    std::string input;
    while (true) {
        currentState_->display();

        std::getline(std::cin, input);

        auto newState = currentState_->handler(input);
        if (newState) {
            auto& pool = StateContext::getStatePool();
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

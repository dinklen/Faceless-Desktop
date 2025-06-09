#include "Application.hpp"

#include "../../include/interface/StateContext.hpp"
#include "../../include/interface/states/WelcomePageState.hpp"

#include <iostream>
#include <memory>

// Static initializer. Singletone
Application& Application::getInstance() {
    static Application instance_;
    return instance_;
}

// When application starting
Application::Application() {
    std::cout << "Starting... ";
    currentState_ = std::make_unique<WelcomePageState>();
    std::cout << "done" << std::endl;
}

// Event loop
void Application::run() {
    std::cout << "Faceless, v0.1.1-alpha\n"
    << "Write \"help\" to get more info\n"
    << std::endl;

    std::string input;
    while (true) {
        currentState_->display();

        std::getline(std::cin, input);

        auto newState = currentState_->handler(input);
        if (newState) {
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

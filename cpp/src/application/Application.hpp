#pragma once

#include "../../include/interface/StateContext.hpp"

#include <memory>

// Application manager class
class Application {
public:
    // Singletone
    static Application& getInstance();

    // Event loop
    void run();

private:
    // Singletone methods
    Application();
    ~Application();

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    // States tracker
    std::unique_ptr<StateContext> currentState_;
};

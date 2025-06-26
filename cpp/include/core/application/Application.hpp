#pragma once

#include "../../interface/StateContext.hpp"

#include <memory>

namespace faceless::core::application {

// Application manager class
class Application final {
public:
    // Singletone
    static Application& getInstance();

    // Event loop
    [[noreturn]] void run();

private:
    // Singletone methods
    Application();
    ~Application();

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    // States tracker
    std::unique_ptr<faceless::interface::context::StateContext> currentState_;
};

} // namespace faceless::core::application

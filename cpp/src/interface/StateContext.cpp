#include "../../include/interface/StateContext.hpp"

#include <unordered_map>
#include <memory>

// State pool getter
std::unordered_map<StateType, std::unique_ptr<StateContext>>& StateContext::getStatePool() {
    static std::unordered_map<StateType, std::unique_ptr<StateContext>> statePool;
    return statePool;
}

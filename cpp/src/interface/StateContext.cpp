#include "../../include/interface/StateContext.hpp"

#include <unordered_map>
#include <memory>

namespace faceless::interface::context {

// State pool getter
std::unordered_map<StateType, std::unique_ptr<StateContext>>& StateContext::getStatePool() {
    static std::unordered_map<StateType, std::unique_ptr<StateContext>> statePool;
    return statePool;
}

} // namespace faceless::interface::context

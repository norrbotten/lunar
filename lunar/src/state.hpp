#pragma once

#include <functional>
#include <string>

#include "luadef.hpp"

namespace Lunar {

class State {
  private:
    lua_State* lstate;

  public:
    State(lua_State* lstate_)
        : lstate(lstate_){};

    auto GetLuaState() { return this->lstate; }

    /**
     * Compiles and runs the given string
     * If theres an error its printed to STDOUT
     * Returns true on failure, false on success
     */
    auto RunString(std::string code) {
        auto failure = Symbols::luaL_dostring(this->lstate, code.c_str());
        if (failure) {
            puts(Symbols::lua_tostring(this->lstate, -1));
            Symbols::lua_pop(this->lstate, 1);
            return true;
        }
        return false;
    }

    /**
     * Compiles and runs the given string
     * Calls the error_handler with the error message if theres an error
     * Returns true on failure, false on success
     */
    auto RunString(std::string code, std::function<void(std::string)> error_handler) {
        auto failure = Symbols::luaL_dostring(this->lstate, code.c_str());
        if (failure) {
            const std::string err = Symbols::lua_tostring(this->lstate, -1);
            Symbols::lua_pop(this->lstate, 1);
            error_handler(err);
            return true;
        }
        return false;
    }
};

} // namespace Lunar
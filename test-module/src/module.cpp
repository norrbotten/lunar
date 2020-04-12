#include <cstdio>

#include <lunar.hpp>

static int hello(lua_State* L) {
    Lunar::Symbols::lua_pushnumber(L, 1.234);
    return 1;
}

LUNAR_MODULE_OPEN() {
    if (Lunar::Loader::Initialize())
        return 0;

    // Lunar::Symbols::lua_pushcfunction(L, &hello);
    // Lunar::Symbols::lua_setfield(L, LUA_GLOBALSINDEX, "hello");

    return 0;
}

LUNAR_MODULE_CLOSE() {
    Lunar::Loader::Deinitialize();
    return 0;
}

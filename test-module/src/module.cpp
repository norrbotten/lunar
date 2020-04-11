#include <cstdio>

#include <lunar.hpp>

DLLEXPORT int hello(lua_State* L) {
    Lunar::Symbols::lua_pushnumber(L, 1.234);
    return 1;
}

LUNAR_MODULE_OPEN() {
    Lunar::Loader::Initialize();

    puts("Initialized LUNAR");

    Lunar::Symbols::lua_createtable(L, 0, 0);
    Lunar::Symbols::lua_pushcclosure(L, hello, 0);
    Lunar::Symbols::lua_setfield(L, -2, "hello");

    return 1;
}

LUNAR_MODULE_CLOSE() {
    Lunar::Loader::Deinitialize();
    return 1;
}
#include <cstdio>
#include <dlfcn.h>
#include <unordered_map>

namespace Lunar::Loader {

#ifdef LUNAR_CLIENT_MODULE
constexpr auto LUA_MODULE_PATH = "./garrysmod/bin/lua_shared.so";
#else
constexpr auto LUA_MODULE_PATH = "./garrysmod/bin/lua_shared_srv.so";
#endif

static void* handle = nullptr;

static std::unordered_map<const char*, void*> symbol_map;

static void Initialize() {
    handle = dlopen(LUA_MODULE_PATH, RTLD_LAZY | RTLD_DEEPBIND);
    if (handle == nullptr) {
        exit(1);
        puts("Lunar LuaLoader Error: lua_shared library not found");
    }
}

static void Deinitialize() {
    if (handle != nullptr) {
        dlclose(handle);
    }
}

template <typename Ret, typename... Args>
auto CallSymbol = [](const char* name, Args... args) -> Ret {
    Ret (*symbol)(Args...);

    if (symbol_map.find(name) != symbol_map.end()) {
        *(void**)(&symbol) = symbol_map[name];
    }
    else {
        auto* raw_symbol = dlsym(handle, name);
        symbol_map[name] = raw_symbol;

        Ret (*symbol)(Args...);
        *(void**)(&symbol) = raw_symbol;
    }

    printf("%p\n", symbol);
    return symbol(args...);
};

} // namespace Lunar::Loader

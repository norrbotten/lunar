#define DLLEXPORT extern "C" __attribute((visibility("default")))

#include "symbols.hpp"

#define LUNAR_MODULE_OPEN() DLLEXPORT int gmod13_open(lua_State* L)
#define LUNAR_MODULE_CLOSE() DLLEXPORT int gmod13_close(lua_State* L)
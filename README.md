# Lunar
### A library for writing C++ modules for Garry's Mod

# What it does
Loads the `lua_shared` library and gives a nice OOP wrapper around it (in the future)

# Why I made this
Because garry's mods built in lua wrapper thing is useless (and I couldn't get danielga's thing to work)

# How to use

__This is very early in development and likely isn't very useful right now__

1. Make a project with the same structure as the `test-module` example, copying the premake
2. Modify the premake to your likings
3. Include the lunar headers in your project `#include <lunar.hpp>`
4. Define your modules entry and exit point using the `LUNAR_MODULE_OPEN` and `LUNAR_MODULE_CLOSE` libraries
5. Build it
    1. `cd` to your projects directory
    2. `premake5 gmake2`
    3. `cd makefiles`
    4. `make config=release` - use `debug` to include debug symbols in the binary
    5. Your library is now in `build/bin/`. You can verify it by running `premake5 verify` in your projects directory.
    6. If you configured the `ìnstall_dir` in the premake, you can run `premake5 install` to copy it there.

**Example code** Refer to the 'test-module' example

## Dependencies
  * `Lua 5.1 headers` - These should be somewhere where your compiler can find them, ie `/usr/include/` or in the `lunar/src/` directory
 
  * (OPTIONAL) Premake5 - If you're going to use the example projects premake file

# Windows support?
1. Fork this repo
2. Add it
3. Test it
4. Submit a pull request

# Credits
 * *danielga's* [garrysmod_common](https://github.com/danielga/garrysmod_common) - For giving me the idea to load the lua library that already comes with gmod, instead of compiling lua5.1 for 32 bit and crying myself to sleep after trying to fix ABI issues

#pragma once

#include "loader.hpp"

#include <lua5.1/lua.h>

namespace Lunar::Symbols {
using Lunar::Loader::CallSymbol;

void lua_getfenv(lua_State* L, int i = 0) {
    return CallSymbol<void, lua_State*, int>("lua_getfenv", L, i);
}

int lua_setfenv(lua_State* L, int i = 0) {
    return CallSymbol<int, lua_State*, int>("lua_setfenv", L, i);
}

int lua_error(lua_State* L) { return CallSymbol<int, lua_State*>("lua_error", L); }

int lua_gettop(lua_State* L) { return CallSymbol<int, lua_State*>("lua_gettop", L); }

void lua_insert(lua_State* L, int i) {
    return CallSymbol<void, lua_State*, int>("lua_insert", L, i);
}

void lua_remove(lua_State* L, int i) {
    return CallSymbol<void, lua_State*, int>("lua_remove", L, i);
}

void lua_replace(lua_State* L, int i) {
    return CallSymbol<void, lua_State*, int>("lua_replace", L, i);
}

int lua_isnumber(lua_State* L, int i) {
    return CallSymbol<int, lua_State*, int>("lua_isnumber", L, i);
}

int lua_isstring(lua_State* L, int i) {
    return CallSymbol<int, lua_State*, int>("lua_isstring", L, i);
}

int lua_iscfunction(lua_State* L, int i) {
    return CallSymbol<int, lua_State*, int>("lua_iscfunction", L, i);
}

int lua_isuserdata(lua_State* L, int i) {
    return CallSymbol<int, lua_State*, int>("lua_isuserdata", L, i);
}

int lua_type(lua_State* L, int i) { return CallSymbol<int, lua_State*, int>("lua_type", L, i); }

const char* lua_typename(lua_State* L, int i) {
    return CallSymbol<const char*, lua_State*, int>("lua_typename", L, i);
}

int lua_equal(lua_State* L, int i, int j) {
    return CallSymbol<int, lua_State*, int, int>("lua_equal", L, i, j);
}

int lua_rawequal(lua_State* L, int i, int j) {
    return CallSymbol<int, lua_State*, int, int>("lua_rawequal", L, i, j);
}

int lua_lessthan(lua_State* L, int i, int j) {
    return CallSymbol<int, lua_State*, int, int>("lua_lessthan", L, i, j);
}

lua_Number lua_tonumber(lua_State* L, int i) {
    return CallSymbol<lua_Number, lua_State*, int>("lua_tonumber", L, i);
}

lua_Integer lua_tointeger(lua_State* L, int i) {
    return CallSymbol<lua_Integer, lua_State*, int>("lua_tointeger", L, i);
}

int lua_toboolean(lua_State* L, int i) {
    return CallSymbol<int, lua_State*, int>("lua_toboolean", L, i);
}

const char* lua_tolstring(lua_State* L, int i) {
    return CallSymbol<const char*, lua_State*, int>("lua_tolstring", L, i);
}

size_t lua_objlen(lua_State* L, int i) {
    return CallSymbol<size_t, lua_State*, int>("lua_objlen", L, i);
}

#undef lua_strlen
size_t lua_strlen(lua_State* L, int i) {
    return CallSymbol<size_t, lua_State*, int>("lua_objlen", L, i); // lua_objlen is not a typo
                                                                    // lua_strlen is a macro
}

lua_CFunction lua_tocfunction(lua_State* L, int i) {
    return CallSymbol<lua_CFunction, lua_State*, int>("lua_tocfunction", L, i);
}

void* lua_touserdata(lua_State* L, int i) {
    return CallSymbol<void*, lua_State*, int>("lua_touserdata", L, i);
}

const void* lua_topointer(lua_State* L, int i) {
    return CallSymbol<const void*, lua_State*, int>("lua_topointer", L, i);
}

void lua_pushnil(lua_State* L) { return CallSymbol<void, lua_State*>("lua_pushnil", L); }

void lua_pushnumber(lua_State* L, lua_Number n) {
    return CallSymbol<void, lua_State*, lua_Number>("lua_pushnumber", L, n);
}

void lua_pushinteger(lua_State* L, lua_Integer n) {
    return CallSymbol<void, lua_State*, lua_Integer>("lua_pushinteger", L, n);
}

void lua_pushlstring(lua_State* L, const char* s, size_t n) {
    return CallSymbol<void, lua_State*, const char*, size_t>("lua_pushlstring", L, s, n);
}

void lua_pushstring(lua_State* L, const char* s) {
    return CallSymbol<void, lua_State*, const char*>("lua_pushstring", L, s);
}

void lua_pushcclosure(lua_State* L, lua_CFunction f, int i) {
    return CallSymbol<void, lua_State*, lua_CFunction, int>("lua_pushcclosure", L, f, i);
}

#undef lua_pushcfunction
void lua_pushcfunction(lua_State* L, lua_CFunction f) {
    return CallSymbol<void, lua_State*, lua_CFunction, int>("lua_pushcclosure", L, f, 0);
}

void lua_pushboolean(lua_State* L, int b) {
    return CallSymbol<void, lua_State*, int>("lua_pushboolean", L, b);
}

void lua_pushlightuserdata(lua_State* L, void* d) {
    return CallSymbol<void, lua_State*, void*>("lua_pushlightuserdata", L, d);
}

int lua_pushthread(lua_State* L) { return CallSymbol<int, lua_State*>("lua_pushthread", L); }

void lua_gettable(lua_State* L, int i) {
    return CallSymbol<void, lua_State*, int>("lua_gettable", L, i);
}

void lua_getfield(lua_State* L, int i, const char* c) {
    return CallSymbol<void, lua_State*, int, const char*>("lua_getfield", L, i, c);
}

void lua_createtable(lua_State* L, int i, int j) {
    return CallSymbol<void, lua_State*, int, int>("lua_createtable", L, i, j);
}

#undef lua_newtable
void lua_newtable(lua_State* L) {
    return CallSymbol<void, lua_State*, int, int>("lua_createtable", L, 0, 0);
}

void* lua_newuserdata(lua_State* L, size_t s) {
    return CallSymbol<void*, lua_State*, size_t>("lua_newuserdata", L, s);
}

int lua_getmetatable(lua_State* L, int i) {
    return CallSymbol<int, lua_State*, int>("lua_getmetatable", L, i);
}

void lua_settable(lua_State* L, int i) {
    return CallSymbol<void, lua_State*, int>("lua_settable", L, i);
}

void lua_setfield(lua_State* L, int i, const char* c) {
    return CallSymbol<void, lua_State*, int, const char*>("lua_setfield", L, i, c);
}

void lua_rawset(lua_State* L, int i) {
    return CallSymbol<void, lua_State*, int>("lua_rawset", L, i);
}

void lua_rawseti(lua_State* L, int i, int j) {
    return CallSymbol<void, lua_State*, int, int>("lua_rawset", L, i, j);
}

int lua_setmetatable(lua_State* L, int i) {
    return CallSymbol<int, lua_State*, int>("lua_setmetatable", L, i);
}

int lua_call(lua_State* L, int i, int j) {
    return CallSymbol<int, lua_State*, int, int>("lua_call", L, i, j);
}

int lua_pcall(lua_State* L, int i, int j, int k) {
    return CallSymbol<int, lua_State*, int, int, int>("lua_call", L, i, j, k);
}

int lua_cpcall(lua_State* L, lua_CFunction c, void* d) {
    return CallSymbol<int, lua_State*, lua_CFunction, void*>("lua_cpcall", L, c, d);
}

int lua_load(lua_State* L, lua_Reader r, void* d, const char* c) {
    return CallSymbol<int, lua_State*, lua_Reader, void*, const char*>("lua_load", L, r, d, c);
}

int load_dump(lua_State* L, lua_Writer w, void* d) {
    return CallSymbol<int, lua_State*, lua_Writer, void*>("lua_dump", L, w, d);
}

int lua_resume_real(lua_State* L, int i) {
    return CallSymbol<int, lua_State*, int>("lua_resume_real", L, i);
}

int lua_yield(lua_State* L, int i) { return CallSymbol<int, lua_State*, int>("lua_yield", L, i); }

int lua_resume(lua_State* L, int i) { return CallSymbol<int, lua_State*, int>("lua_resume", L, i); }

int lua_status(lua_State* L) { return CallSymbol<int, lua_State*>("lua_status", L); }

int lua_gc(lua_State* L, int i, int j) {
    return CallSymbol<int, lua_State*, int, int>("lua_gc", L, i, j);
}

int lua_next(lua_State* L, int i) { return CallSymbol<int, lua_State*, int>("lua_next", L, i); }

void lua_concat(lua_State* L, int i) {
    return CallSymbol<void, lua_State*, int>("lua_concat", L, i);
}

lua_Alloc lua_getallocf(lua_State* L, void** d) {
    return CallSymbol<lua_Alloc, lua_State*, void**>("lua_getallocf", L, d);
}

void lua_setallocf(lua_State* L, lua_Alloc a, void* d) {
    return CallSymbol<void, lua_State*, lua_Alloc, void*>("lua_setallocf", L, a, d);
}

} // namespace Lunar::Symbols
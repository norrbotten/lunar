#pragma once

#include "loader.hpp"
#include "luadef.hpp"

namespace Lunar::Symbols {

using Lunar::Loader::CallSymbol;

lua_State* lua_newstate(lua_Alloc f, void* ud) {
    return CallSymbol<lua_State*, lua_Alloc, void*>("lua_newstate", f, ud);
}

void lua_close(lua_State* L) { return CallSymbol<void, lua_State*>("lua_close", L); }

lua_State* lua_newthread(lua_State* L) {
    return CallSymbol<lua_State*, lua_State*>("lua_newthread", L);
}

lua_CFunction lua_atpanic(lua_State* L, lua_CFunction panicf) {
    return CallSymbol<lua_CFunction, lua_State*, lua_CFunction>("lua_atpanic", L, panicf);
}

int lua_gettop(lua_State* L) { return CallSymbol<int, lua_State*>("lua_gettop", L); }

void lua_settop(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_settop", L, idx);
}

void lua_pushvalue(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_pushvalue", L, idx);
}

void lua_remove(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_remove", L, idx);
}

void lua_insert(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_insert", L, idx);
}

void lua_replace(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_replace", L, idx);
}

int lua_checkstack(lua_State* L, int sz) {
    return CallSymbol<int, lua_State*, int>("lua_checkstack", L, sz);
}

void lua_xmove(lua_State* from, lua_State* to, int n) {
    return CallSymbol<void, lua_State*, lua_State*, int>("lua_xmove", from, to, n);
}

int lua_isnumber(lua_State* L, int idx) {
    return CallSymbol<int, lua_State*, int>("lua_isnumber", L, idx);
}

int lua_isstring(lua_State* L, int idx) {
    return CallSymbol<int, lua_State*, int>("lua_isstring", L, idx);
}

int lua_iscfunction(lua_State* L, int idx) {
    return CallSymbol<int, lua_State*, int>("lua_iscfunction", L, idx);
}

int lua_isuserdata(lua_State* L, int idx) {
    return CallSymbol<int, lua_State*, int>("lua_isuserdata", L, idx);
}

int lua_type(lua_State* L, int idx) { return CallSymbol<int, lua_State*, int>("lua_type", L, idx); }

const char* lua_typename(lua_State* L, int tp) {
    return CallSymbol<const char*, lua_State*, int>("lua_typename", L, tp);
}

int lua_equal(lua_State* L, int idx1, int idx2) {
    return CallSymbol<int, lua_State*, int, int>("lua_equal", L, idx1, idx2);
}

int lua_rawequal(lua_State* L, int idx1, int idx2) {
    return CallSymbol<int, lua_State*, int, int>("lua_rawequal", L, idx1, idx2);
}

int lua_lessthan(lua_State* L, int idx1, int idx2) {
    return CallSymbol<int, lua_State*, int, int>("lua_lessthan", L, idx1, idx2);
}

lua_Number lua_tonumber(lua_State* L, int idx) {
    return CallSymbol<lua_Number, lua_State*, int>("lua_tonumber", L, idx);
}

lua_Integer lua_tointeger(lua_State* L, int idx) {
    return CallSymbol<lua_Integer, lua_State*, int>("lua_tointeger", L, idx);
}

int lua_toboolean(lua_State* L, int idx) {
    return CallSymbol<int, lua_State*, int>("lua_toboolean", L, idx);
}

const char* lua_tolstring(lua_State* L, int idx, size_t* len) {
    return CallSymbol<const char*, lua_State*, int, size_t*>("lua_tolstring", L, idx, len);
}

size_t lua_objlen(lua_State* L, int idx) {
    return CallSymbol<size_t, lua_State*, int>("lua_objlen", L, idx);
}

lua_CFunction lua_tocfunction(lua_State* L, int idx) {
    return CallSymbol<lua_CFunction, lua_State*, int>("lua_tocfunction", L, idx);
}

void* lua_touserdata(lua_State* L, int idx) {
    return CallSymbol<void*, lua_State*, int>("lua_touserdata", L, idx);
}

lua_State* lua_tothread(lua_State* L, int idx) {
    return CallSymbol<lua_State*, lua_State*, int>("lua_tothread", L, idx);
}

const void* lua_topointer(lua_State* L, int idx) {
    return CallSymbol<const void*, lua_State*, int>("lua_topointer", L, idx);
}

void lua_pushnil(lua_State* L) { return CallSymbol<void, lua_State*>("lua_pushnil", L); }

void lua_pushnumber(lua_State* L, lua_Number n) {
    return CallSymbol<void, lua_State*, lua_Number>("lua_pushnumber", L, n);
}

void lua_pushinteger(lua_State* L, lua_Integer n) {
    return CallSymbol<void, lua_State*, lua_Integer>("lua_pushinteger", L, n);
}

void lua_pushlstring(lua_State* L, const char* s, size_t l) {
    return CallSymbol<void, lua_State*, const char*, size_t>("lua_pushlstring", L, s, l);
}

void lua_pushstring(lua_State* L, const char* s) {
    return CallSymbol<void, lua_State*, const char*>("lua_pushstring", L, s);
}

void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n) {
    return CallSymbol<void, lua_State*, lua_CFunction, int>("lua_pushcclosure", L, fn, n);
}

void lua_pushboolean(lua_State* L, int b) {
    return CallSymbol<void, lua_State*, int>("lua_pushboolean", L, b);
}

void lua_pushlightuserdata(lua_State* L, void* p) {
    return CallSymbol<void, lua_State*, void*>("lua_pushlightuserdata", L, p);
}

int lua_pushthread(lua_State* L) { return CallSymbol<int, lua_State*>("lua_pushthread", L); }

void lua_gettable(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_gettable", L, idx);
}

void lua_getfield(lua_State* L, int idx, const char* k) {
    return CallSymbol<void, lua_State*, int, const char*>("lua_getfield", L, idx, k);
}

void lua_rawget(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_rawget", L, idx);
}

void lua_rawgeti(lua_State* L, int idx, int n) {
    return CallSymbol<void, lua_State*, int, int>("lua_rawgeti", L, idx, n);
}

void lua_createtable(lua_State* L, int narr, int nrec) {
    return CallSymbol<void, lua_State*, int, int>("lua_createtable", L, narr, nrec);
}

void* lua_newuserdata(lua_State* L, size_t sz) {
    return CallSymbol<void*, lua_State*, size_t>("lua_newuserdata", L, sz);
}

int lua_getmetatable(lua_State* L, int objindex) {
    return CallSymbol<int, lua_State*, int>("lua_getmetatable", L, objindex);
}

void lua_getfenv(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_getfenv", L, idx);
}

void lua_settable(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_settable", L, idx);
}

void lua_setfield(lua_State* L, int idx, const char* k) {
    return CallSymbol<void, lua_State*, int, const char*>("lua_setfield", L, idx, k);
}

void lua_rawset(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_rawset", L, idx);
}

void lua_rawseti(lua_State* L, int idx, int n) {
    return CallSymbol<void, lua_State*, int, int>("lua_rawseti", L, idx, n);
}

int lua_setmetatable(lua_State* L, int objindex) {
    return CallSymbol<int, lua_State*, int>("lua_setmetatable", L, objindex);
}

int lua_setfenv(lua_State* L, int idx) {
    return CallSymbol<int, lua_State*, int>("lua_setfenv", L, idx);
}

void lua_call(lua_State* L, int nargs, int nresults) {
    return CallSymbol<void, lua_State*, int, int>("lua_call", L, nargs, nresults);
}

int lua_pcall(lua_State* L, int nargs, int nresults, int errfunc) {
    return CallSymbol<int, lua_State*, int, int, int>("lua_pcall", L, nargs, nresults, errfunc);
}

int lua_cpcall(lua_State* L, lua_CFunction func, void* ud) {
    return CallSymbol<int, lua_State*, lua_CFunction, void*>("lua_cpcall", L, func, ud);
}

int lua_load(lua_State* L, lua_Reader reader, void* dt, const char* chunkname) {
    return CallSymbol<int, lua_State*, lua_Reader, void*, const char*>("lua_load", L, reader, dt,
                                                                       chunkname);
}

int lua_dump(lua_State* L, lua_Writer writer, void* data) {
    return CallSymbol<int, lua_State*, lua_Writer, void*>("lua_dump", L, writer, data);
}

int lua_yield(lua_State* L, int nresults) {
    return CallSymbol<int, lua_State*, int>("lua_yield", L, nresults);
}

int lua_resume(lua_State* L, int narg) {
    return CallSymbol<int, lua_State*, int>("lua_resume", L, narg);
}

int lua_status(lua_State* L) { return CallSymbol<int, lua_State*>("lua_status", L); }

int lua_gc(lua_State* L, int what, int data) {
    return CallSymbol<int, lua_State*, int, int>("lua_gc", L, what, data);
}

int lua_error(lua_State* L) { return CallSymbol<int, lua_State*>("lua_error", L); }

int lua_next(lua_State* L, int idx) { return CallSymbol<int, lua_State*, int>("lua_next", L, idx); }

void lua_concat(lua_State* L, int n) {
    return CallSymbol<void, lua_State*, int>("lua_concat", L, n);
}

lua_Alloc lua_getallocf(lua_State* L, void** ud) {
    return CallSymbol<lua_Alloc, lua_State*, void*>("lua_getallocf", L, *ud);
}

void lua_setallocf(lua_State* L, lua_Alloc f, void* ud) {
    return CallSymbol<void, lua_State*, lua_Alloc, void*>("lua_setallocf", L, f, ud);
}

void lua_setlevel(lua_State* from, lua_State* to) {
    return CallSymbol<void, lua_State*, lua_State*>("lua_setlevel", from, to);
}

int lua_getstack(lua_State* L, int level, lua_Debug* ar) {
    return CallSymbol<int, lua_State*, int, lua_Debug*>("lua_getstack", L, level, ar);
}

int lua_getinfo(lua_State* L, const char* what, lua_Debug* ar) {
    return CallSymbol<int, lua_State*, const char*, lua_Debug*>("lua_getinfo", L, what, ar);
}

const char* lua_getlocal(lua_State* L, const lua_Debug* ar, int n) {
    return CallSymbol<const char*, lua_State*, const lua_Debug*, int>("lua_getlocal", L, ar, n);
}

const char* lua_setlocal(lua_State* L, const lua_Debug* ar, int n) {
    return CallSymbol<const char*, lua_State*, const lua_Debug*, int>("lua_setlocal", L, ar, n);
}

const char* lua_getupvalue(lua_State* L, int funcindex, int n) {
    return CallSymbol<const char*, lua_State*, int, int>("lua_getupvalue", L, funcindex, n);
}

const char* lua_setupvalue(lua_State* L, int funcindex, int n) {
    return CallSymbol<const char*, lua_State*, int, int>("lua_setupvalue", L, funcindex, n);
}

int lua_sethook(lua_State* L, lua_Hook func, int mask, int count) {
    return CallSymbol<int, lua_State*, lua_Hook, int, int>("lua_sethook", L, func, mask, count);
}

lua_Hook lua_gethook(lua_State* L) { return CallSymbol<lua_Hook, lua_State*>("lua_gethook", L); }

int lua_gethookmask(lua_State* L) { return CallSymbol<int, lua_State*>("lua_gethookmask", L); }

int lua_gethookcount(lua_State* L) { return CallSymbol<int, lua_State*>("lua_gethookcount", L); }

auto lua_pop(lua_State* L, int n) { return lua_settop(L, (-n) - 1); }

auto lua_newtable(lua_State* L) { return lua_createtable(L, 0, 0); }

auto lua_setglobal(lua_State* L, const char* s) { return lua_setfield(L, LUA_GLOBALSINDEX, s); }

auto lua_getglobal(lua_State* L, const char* s) { return lua_getfield(L, LUA_GLOBALSINDEX, s); }

auto lua_pushcfunction(lua_State* L, lua_CFunction f) { return lua_pushcclosure(L, f, 0); }

auto lua_register(lua_State* L, const char* n, lua_CFunction f) {
    return lua_pushcfunction(L, f), lua_setglobal(L, n);
}

auto lua_strlen(lua_State* L, int i) { return lua_objlen(L, i); }

auto lua_isfunction(lua_State* L, int i) { return lua_type(L, i) == LUA_TFUNCTION; }

auto lua_istable(lua_State* L, int i) { return lua_type(L, i) == LUA_TTABLE; }

auto lua_islightuserdata(lua_State* L, int i) { return lua_type(L, i) == LUA_TLIGHTUSERDATA; }

auto lua_isnil(lua_State* L, int i) { return lua_type(L, i) == LUA_TNIL; }

auto lua_isboolean(lua_State* L, int i) { return lua_type(L, i) == LUA_TBOOLEAN; }

auto lua_isthread(lua_State* L, int i) { return lua_type(L, i) == LUA_TTHREAD; }

auto lua_isnone(lua_State* L, int i) { return lua_type(L, i) == LUA_TNONE; }

auto lua_isnoneornil(lua_State* L, int i) { return lua_type(L, i) <= 0; }

auto lua_pushliteral(lua_State* L, const char* s) {
    return lua_pushlstring(L, s, sizeof(s) / sizeof(char) - 1);
}

auto lua_tostring(lua_State* L, int i) { return lua_tolstring(L, i, NULL); }

auto lua_getregistry(lua_State* L) { return lua_pushvalue(L, LUA_REGISTRYINDEX); }

auto lua_getgccount(lua_State* L) { return lua_gc(L, LUA_GCCOUNT, 0); }

void luaI_openlib(lua_State* L, const char* libname, const luaL_Reg* l, int nup) {
    return CallSymbol<void, lua_State*, const char*, const luaL_Reg*, int>("luaI_openlib", L,
                                                                           libname, l, nup);
}

void luaL_register(lua_State* L, const char* libname, const luaL_Reg* l) {
    return CallSymbol<void, lua_State*, const char*, const luaL_Reg*>("luaL_register", L, libname,
                                                                      l);
}

int luaL_getmetafield(lua_State* L, int obj, const char* e) {
    return CallSymbol<int, lua_State*, int, const char*>("luaL_getmetafield", L, obj, e);
}

int luaL_callmeta(lua_State* L, int obj, const char* e) {
    return CallSymbol<int, lua_State*, int, const char*>("luaL_callmeta", L, obj, e);
}

int luaL_typerror(lua_State* L, int narg, const char* tname) {
    return CallSymbol<int, lua_State*, int, const char*>("luaL_typerror", L, narg, tname);
}

int luaL_argerror(lua_State* L, int numarg, const char* extramsg) {
    return CallSymbol<int, lua_State*, int, const char*>("luaL_argerror", L, numarg, extramsg);
}

const char* luaL_checklstring(lua_State* L, int numArg, size_t* l) {
    return CallSymbol<const char*, lua_State*, int, size_t*>("luaL_checklstring", L, numArg, l);
}

const char* luaL_optlstring(lua_State* L, int numArg, const char* def, size_t* l) {
    return CallSymbol<const char*, lua_State*, int, const char*, size_t*>("luaL_optlstring", L,
                                                                          numArg, def, l);
}

lua_Number luaL_checknumber(lua_State* L, int numArg) {
    return CallSymbol<lua_Number, lua_State*, int>("luaL_checknumber", L, numArg);
}

lua_Number luaL_optnumber(lua_State* L, int nArg, lua_Number def) {
    return CallSymbol<lua_Number, lua_State*, int, lua_Number>("luaL_optnumber", L, nArg, def);
}

lua_Integer luaL_checkinteger(lua_State* L, int numArg) {
    return CallSymbol<lua_Integer, lua_State*, int>("luaL_checkinteger", L, numArg);
}

lua_Integer luaL_optinteger(lua_State* L, int nArg, lua_Integer def) {
    return CallSymbol<lua_Integer, lua_State*, int, lua_Integer>("luaL_optinteger", L, nArg, def);
}

void luaL_checkstack(lua_State* L, int sz, const char* msg) {
    return CallSymbol<void, lua_State*, int, const char*>("luaL_checkstack", L, sz, msg);
}

void luaL_checktype(lua_State* L, int narg, int t) {
    return CallSymbol<void, lua_State*, int, int>("luaL_checktype", L, narg, t);
}

void luaL_checkany(lua_State* L, int narg) {
    return CallSymbol<void, lua_State*, int>("luaL_checkany", L, narg);
}

int luaL_newmetatable(lua_State* L, const char* tname) {
    return CallSymbol<int, lua_State*, const char*>("luaL_newmetatable", L, tname);
}

void* luaL_checkudata(lua_State* L, int ud, const char* tname) {
    return CallSymbol<void*, lua_State*, int, const char*>("luaL_checkudata", L, ud, tname);
}

void luaL_where(lua_State* L, int lvl) {
    return CallSymbol<void, lua_State*, int>("luaL_where", L, lvl);
}

int luaL_checkoption(lua_State* L, int narg, const char* def, const char* const lst[]) {
    return CallSymbol<int, lua_State*, int, const char*, const char* const[]>("luaL_checkoption", L,
                                                                              narg, def, lst);
}

int luaL_ref(lua_State* L, int t) { return CallSymbol<int, lua_State*, int>("luaL_ref", L, t); }

void luaL_unref(lua_State* L, int t, int ref) {
    return CallSymbol<void, lua_State*, int, int>("luaL_unref", L, t, ref);
}

int luaL_loadfile(lua_State* L, const char* filename) {
    return CallSymbol<int, lua_State*, const char*>("luaL_loadfile", L, filename);
}

int luaL_loadbuffer(lua_State* L, const char* buff, size_t sz, const char* name) {
    return CallSymbol<int, lua_State*, const char*, size_t, const char*>("luaL_loadbuffer", L, buff,
                                                                         sz, name);
}

int luaL_loadstring(lua_State* L, const char* s) {
    return CallSymbol<int, lua_State*, const char*>("luaL_loadstring", L, s);
}

lua_State* luaL_newstate() { return CallSymbol<lua_State*>("luaL_newstate"); }

const char* luaL_gsub(lua_State* L, const char* s, const char* p, const char* r) {
    return CallSymbol<const char*, lua_State*, const char*, const char*, const char*>("luaL_gsub",
                                                                                      L, s, p, r);
}

const char* luaL_findtable(lua_State* L, int idx, const char* fname, int szhint) {
    return CallSymbol<const char*, lua_State*, int, const char*, int>("luaL_findtable", L, idx,
                                                                      fname, szhint);
}

auto lua_open() { return luaL_newstate(); }

template <typename Cond>
auto luaL_argcheck(lua_State* L, Cond cond, int numarg, const char* extramsg) {
    return (void)(cond) || luaL_argerror(L, numarg, extramsg);
}

auto luaL_checkstring(lua_State* L, int n) { return luaL_checklstring(L, n, NULL); }

auto luaL_optstring(lua_State* L, int n, const char* d) { return luaL_optlstring(L, n, d, NULL); }

auto luaL_checkint(lua_State* L, int n) { return (int)luaL_checkinteger(L, n); }

auto luaL_optint(lua_State* L, int n, lua_Integer d) { return (int)luaL_optinteger(L, n, d); }

auto luaL_checklong(lua_State* L, int n) { return (long)luaL_checkinteger(L, n); }

auto luaL_optlong(lua_State* L, int n, lua_Integer d) { (long)luaL_optinteger(L, n, d); }

auto luaL_typename(lua_State* L, int i) { return lua_typename(L, lua_type(L, i)); }

auto luaL_dofile(lua_State* L, const char* fn) {
    return luaL_loadfile(L, fn) || lua_pcall(L, 0, LUA_MULTRET, 0);
}

auto luaL_dostring(lua_State* L, const char* s) {
    return luaL_loadstring(L, s) || lua_pcall(L, 0, LUA_MULTRET, 0);
}

auto luaL_getmetatable(lua_State* L, const char* n) {
    return lua_getfield(L, LUA_REGISTRYINDEX, n);
}

template <typename Ret> auto luaL_opt(lua_State* L, Ret (*f)(lua_State*, int), int arg, Ret def) {
    // if it compiles it works HEHEHEHE
    return lua_isnoneornil(L, arg) ? def : f(L, arg);
    // as ive understood, this checks if arg is none or nil,
    // if so it returns the default, else the result of f()
}

} // namespace Lunar::Symbols
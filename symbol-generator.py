functions = """
LUALIB_API void (luaI_openlib) (lua_State *L, const char *libname, const luaL_Reg *l, int nup);
LUALIB_API void (luaL_register) (lua_State *L, const char *libname, const luaL_Reg *l);
LUALIB_API int (luaL_getmetafield) (lua_State *L, int obj, const char *e);
LUALIB_API int (luaL_callmeta) (lua_State *L, int obj, const char *e);
LUALIB_API int (luaL_typerror) (lua_State *L, int narg, const char *tname);
LUALIB_API int (luaL_argerror) (lua_State *L, int numarg, const char *extramsg);
LUALIB_API const char *(luaL_checklstring) (lua_State *L, int numArg, size_t *l);
LUALIB_API const char *(luaL_optlstring) (lua_State *L, int numArg, const char *def, size_t *l);
LUALIB_API lua_Number (luaL_checknumber) (lua_State *L, int numArg);
LUALIB_API lua_Number (luaL_optnumber) (lua_State *L, int nArg, lua_Number def);

LUALIB_API lua_Integer (luaL_checkinteger) (lua_State *L, int numArg);
LUALIB_API lua_Integer (luaL_optinteger) (lua_State *L, int nArg, lua_Integer def);

LUALIB_API void (luaL_checkstack) (lua_State *L, int sz, const char *msg);
LUALIB_API void (luaL_checktype) (lua_State *L, int narg, int t);
LUALIB_API void (luaL_checkany) (lua_State *L, int narg);

LUALIB_API int   (luaL_newmetatable) (lua_State *L, const char *tname);
LUALIB_API void *(luaL_checkudata) (lua_State *L, int ud, const char *tname);

LUALIB_API void (luaL_where) (lua_State *L, int lvl);
LUALIB_API int (luaL_checkoption) (lua_State *L, int narg, const char *def, const char *const lst[]);

LUALIB_API int (luaL_ref) (lua_State *L, int t);
LUALIB_API void (luaL_unref) (lua_State *L, int t, int ref);

LUALIB_API int (luaL_loadfile) (lua_State *L, const char *filename);
LUALIB_API int (luaL_loadbuffer) (lua_State *L, const char *buff, size_t sz, const char *name);
LUALIB_API int (luaL_loadstring) (lua_State *L, const char *s);

LUALIB_API lua_State *(luaL_newstate) (void dummy);

LUALIB_API const char *(luaL_gsub) (lua_State *L, const char *s, const char *p, const char *r);

LUALIB_API const char *(luaL_findtable) (lua_State *L, int idx, const char *fname, int szhint);
"""

macros = """

"""

class Function:
    def __init__(self, rettype, name, argtypes, argnames):
        self.rettype = rettype
        self.name = name
        self.argtypes = argtypes
        self.argnames = argnames

    def __str__(self):
        res = self.rettype + " " + self.name + "("
        args = []

        for tup in zip(self.argtypes, self.argnames):
            args.append(tup[0] + " " + tup[1])

        res = res + ", ".join(args) + ") { "
        res = res + "return CallSymbol<" + ", ".join([self.rettype] + self.argtypes) + ">("
        res = res + "\"" + self.name + "\""

        if len(self.argtypes) > 0:
            res = res + ", " + ", ".join(self.argnames)

        res = res + "); }"
        
        return res

def parseFunction(line):
    left, right = line.split(") (")

    left = left[len("LUALIB_API "):]
    rettype, name = left.split("(")
    
    rettype = rettype.strip()
    name = name.strip()

    argtypes = []
    argnames = []
    
    for arg in right[:-2].split(", "):
        args = arg.rsplit(" ", 1)
        typ, nmn = args[0].strip(), args[1].strip()

        if nmn[0] == "*":
            nmn = nmn[1:]
            typ = typ + "*"
        
        argnames.append(nmn)
        argtypes.append(typ)

    return Function(rettype, name, argtypes, argnames)


def doFunctions():
    for line in functions.split("\n"):
        if line != "":
            print(parseFunction(line), "\n")

doFunctions()


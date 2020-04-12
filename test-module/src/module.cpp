#include <lunar.hpp>

LUNAR_MODULE_OPEN() {
    if (Lunar::Loader::Initialize())
        return 0;

    Lunar::State state(L);

    state.RunString("print(\"Hello from C++\")");
    state.RunString("print(1 ++ 4)", [](std::string err) {
        puts("Error!");
        puts(err.c_str());
    });

    return 0;
}

LUNAR_MODULE_CLOSE() {
    (void)L;
    Lunar::Loader::Deinitialize();
    return 0;
}

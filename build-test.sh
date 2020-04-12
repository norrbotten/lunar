cd test-module
premake5 gmake2

cd makefiles
make config=release

cd ..
premake5 verify
premake5 install

cd test-module
premake5 gmake2

cd makefiles
make

cd ..
premake5 verify
premake5 install

g++ -ggdb `pkg-config --cflags opencv` -o `basename demo.cpp .cpp` demo.cpp `pkg-config --libs opencv`

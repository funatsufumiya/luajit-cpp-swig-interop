# LuaJIT / C++ interop using SWIG

This is tiny example interop between LuaJIT and C++

## Usage

```bash
$ cmake -B build -DCMAKE_BUILD_TYPE=Debug
$ cmake --build build --parallel 8
$ ./build/luajit-cpp-swig-interop

C++ add called with: 5.5, 7.3
Sum:	12.8
C++ multiply called with: 4, 6
Product:	24
Hello, LuaJIT User!
```


## Note

Whole code is generated by coding assistent AI (Cody).
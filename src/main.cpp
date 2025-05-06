#include <iostream>
#include <fstream>
#include <string>
#include <lua.hpp>

std::string readFile(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + path);
    }
    return std::string(std::istreambuf_iterator<char>(file), 
                      std::istreambuf_iterator<char>());
}

extern "C" {
    extern int luaopen_example(lua_State* L);
}

int main() {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    
    luaopen_example(L);
    lua_setglobal(L, "example");
    
    try {
        std::string luaCode = readFile("scripts/test.lua");
        if (luaL_dostring(L, luaCode.c_str()) != 0) {
            std::cerr << "Error executing Lua script: " << lua_tostring(L, -1) << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    lua_close(L);
    return 0;
}

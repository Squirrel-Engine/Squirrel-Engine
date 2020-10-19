#include <iostream>

namespace Squirrel{
    char* convertStdStringToConst(std::string str){
        char* cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        return cstr;
    }

}

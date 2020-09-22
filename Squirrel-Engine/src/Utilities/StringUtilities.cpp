//
// Created by Fatih Canbekli on 22.09.2020.
//

#include <iostream>

namespace Squirrel{
    char* convertStdStringToConst(std::string str){
        return const_cast<char*>(str.c_str());
    }

}

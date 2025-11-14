#include "tools.h"
#include <iostream>

void errif(bool condition,const char* errorMessage){
    if(condition){
        std::cout << errorMessage<< std::endl;
        exit(EXIT_FAILURE);
    }
}
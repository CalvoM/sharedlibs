#include "cppmath.h"

CPPMather::CPPMather(int start){
    this->val = start;
}

void CPPMather::incr(){
    this->val++;
}

void CPPMather::decr(){
    this->val--;
}

int CPPMather::value() const {
    return this->val;   
}
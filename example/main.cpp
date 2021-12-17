#include "cppmath.h"
#include <iostream>
using std::cout;

int main() {
    CPPMather math(5);
    math.incr();
    math.incr();
    math.incr();
    math.incr();
    math.decr();
    cout << math.value() << std::endl;
}
#include <iostream>
#include "math_lib/math_lib.h"

int main()
{
    auto value = math::add(3.5, 9.2);
    std::cout << "value = " << value << '\n';

    return 0;
}

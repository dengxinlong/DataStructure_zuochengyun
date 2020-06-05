#include <iostream>

#include <time.h>
#include <stdlib.h>

int main(void)
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        std::cout << rand() % 10 / 10.0 << " ";
    }
    std::cout << std::endl;

    return 0;
}
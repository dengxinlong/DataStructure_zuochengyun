#include <time.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
       cout <<  rand() % 10 / 10.0 << " ";
    }
    cout << endl;

}


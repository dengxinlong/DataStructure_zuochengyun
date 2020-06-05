#include <iostream>
#include <string>

using namespace std;

class PaperFold
{
public:
    static void paperFold(int num)
    {
        if (!num) return;
        printProcess(1, num, true);
    }

private:
    static void printProcess(int i, int num, bool down)
    {
        if (i > num) return;
        printProcess(i + 1, num, true);
        cout << (down ? "down" : "up") << endl;
        printProcess(i + 1, num, false);
    }
};

int main(void)
{
    int num = 4;
    PaperFold::paperFold(num);

    return 0;
}
#include <iostream>

using namespace std;

class CTest
{
public:
    CTest() : m_chData('\0'), m_nData(0)
    {
    }
    virtual void mem_fun() {}

private:
    char m_chData;
    int m_nData;
    static char s_chData;
};

char CTest::s_chData = '\0';

int main(void)
{
    cout << sizeof(CTest);

    return 0;
}
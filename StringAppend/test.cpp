#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int
main(void)
{
    vector<string> strs{"a", "b"};
    std::sort(strs.begin(), strs.end(),
        [] (string s1, string s2)
        { return (s1 + s2).compare(s2 + s1); });
    for (auto str : strs) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
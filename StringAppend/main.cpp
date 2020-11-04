/*
 * 给定一个字符串类型的数组strs，找到一种拼接方式，使得把所有字符串拼接起来后形成的字符串具有最低的字典序
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Comp
{
public:
    static bool
    appendCom(string s1, string s2)
    {
        return s1.append(s2) <= s2.append(s1);
    }
};

// 贪心，对于字符串数组中的每个字符串，如果str1+str2 <= str2+str1, 按照这种比较规则排序后，排序后的所有元素直接拼接，拼接出来的字符串具有最小字典序
class StringAppend
{
public:
    static string
    stringAppend(vector<string> & strs)
    {
        std::sort(strs.begin(), strs.end(),
            [](string s1, string s2) -> bool
            { return (s1 + s2) <= (s2 + s1); });

        string ret;
        for (auto str : strs) {
            ret.append(str);
        }
        return ret;
    }
};

int
main(void)
{
    vector<string> strs{"b", "ba"};


    cout << StringAppend::stringAppend(strs) << endl;
}
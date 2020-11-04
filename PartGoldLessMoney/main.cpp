/*
 * 说明：一块金条切成两半，需要花费和长度数值一样的铜板。
 *      比如长度为20的金条，不管切成长度多大的两半，都要花费20个铜板。一群人想要整分整块金条，怎么切分最省铜板
 * 例子：给定数组{10, 20, 30}，代表一共三个人，整块金条长度为10+20+30。金条要分成10，20，30三个部分。如果先把长度60的金条分成10和50，花费60，再把长度50的金条分成20和30，花费，一共花费110铜板
 *      但是如果先把长度60的金条分成30和30，花费60，再把长度30金条分成10和20，花费30，一共花费90铜板。
 *      输入一个数组，返回分割的最小代价
 */

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class PartGoldLessMoney
{
public:
    static int
    partGold(vector<int> & nums)
    {
        priority_queue<int, std::vector<int>, std::greater<int>> helpQue;
        for (auto elem : nums) {
            helpQue.push(elem);
        }
        cout << helpQue.size() << endl;
        int ret = 0;
        int cur = 0;
        while (helpQue.size() > 1) {
            cur = helpQue.top();
            helpQue.pop();
            cur += helpQue.top();
            helpQue.pop();
            ret += cur;
            helpQue.push(cur);
        }
        return ret;
    }
};

int
main(void)
{
    vector<int> nums{10, 20, 30};
    cout << PartGoldLessMoney::partGold(nums) << endl;

    return 0;
}
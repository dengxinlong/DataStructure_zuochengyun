/*
 * 题目：参数1，正数数组costs；参数2，正数数组profits；参数3，正数k；参数4，正数m
 *      costs[i]表示i号项目的花费；profits[i]表示i号项目在扣除花费之后还能挣到的钱，
 *      k表示你不能并行，只能串行的最多做k个项目；m表示你的初始资金
 * 说明：你每做完一个项目，马上获得的收益，可以支持你去做下一个项目。
 * 输出：你最后获得的最大钱数
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



class IPO
{
public:
    class Node
    {
    public:
        Node() {}
        Node(int cost, int profit)
        : _cost(cost)
        , _profit(profit)
        {}

        int _cost;
        int _profit;
    };

    class CompGreater
    {
    public:
        bool operator()(Node & item1, Node & item2) { return item1._cost > item2._cost; }
    };

    class CompLess
    {
    public:
        bool operator()(Node & item1, Node & item2) { return item1._profit < item2._profit; }
    };

    int
    getprofit(vector<int> costs, vector<int> profits, int k, int m)
    {
        if (profits.size() != costs.size()) return 0;
        priority_queue<Node, vector<Node>, CompGreater> costHeap;
        for (int i = 0; i < costs.size(); i++) {
            costHeap.push(Node(costs[i], profits[i]));
        }
        priority_queue<Node, vector<Node>, CompLess> profitHeap;
        for (int i = 0; i < k; i++) {
            while (!costHeap.empty() && costHeap.top()._cost <= m) { // 把当前能做的都压入到profitHeap(按照收益的大根堆)中
                Node item = costHeap.top();
                profitHeap.push(item);
                costHeap.pop();
            }
            if (profitHeap.empty()) return m;
            m += profitHeap.top()._profit;
            profitHeap.pop();
        }
        return m;
    }
// private:
//     class Node
//     {
//     public:
//         Node() {}
//         Node(int cost, int profit)
//         : _cost(cost)
//         , _profit(profit)
//         {}

//         int _cost;
//         int _profit;
//     };
};

int
main(void)
{
    IPO ipo;
    vector<int> costs{0, 1, 1};
    vector<int> profits{1, 2, 3};
    int k = 2;
    int m = 0;
    cout << ipo.getprofit(costs, profits, k, m) << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

//Z字形打印矩阵
class ZigZagPrintMatrix
{
public:
    static void zigZagPrintMatrix(const vector<vector<int>> & nums)
    {
        if (nums.size() < 1)
            return;
        int AR = 0;
        int AC = 0;
        int BR = 0;
        int BC = 0;
        bool flag = true;
        while (AR < nums.size()) {
            printEdge(nums, AR, AC, BR, BC, flag); //打印一条直线上面的点
            AR = AC == nums[0].size() - 1 ? AR + 1 : AR;        //两个点坐标的更新顺序需要注意
            AC = AC == nums[0].size() - 1 ? AC : AC + 1;
            BC = BR == nums.size() - 1 ? BC + 1 : BC;
            BR = BR == nums.size() - 1 ? BR : BR + 1;
            flag = !flag;
        }
        cout << endl;
    }

private:
    static void printEdge(const vector<vector<int>> & nums, int AR, int AC,
                                                            int BR, int BC,
                                                            bool flag) //打印一条变，即从A点到B点所形成直线上的点
    {
        if (flag) {
            while (BC <= AC) {
                cout << nums[BR--][BC++] << " ";
            }
        } else {
            while (AC >= BC) {
                cout << nums[AR++][AC--] << " ";
            }
        }
    }
};

int main(void)
{
    vector<vector<int>> nums;
    vector<int> vec;
    for (int i = 1; i < 5; i++)
        vec.push_back(i);
    nums.push_back(vec);

    vec.clear();
    for (int i = 5; i < 9; i++)
        vec.push_back(i);
    nums.push_back(vec);

    vec.clear();
    for (int i = 9; i < 13; i++)
        vec.push_back(i);
    nums.push_back(vec);

    vec.clear();
    for (int i = 13; i < 17; i++)
        vec.push_back(i);
    nums.push_back(vec);

    ZigZagPrintMatrix::zigZagPrintMatrix(nums);

    return 0;
}
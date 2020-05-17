#include <iostream>
#include <vector>

using namespace std;

/*
 *问题描述：（荷兰国旗问题）
            给定一个数组arr，和一个数num，请把小于num的数放在数组的
            左边，等于num的数放在数组的中间，大于num的数放在数组的
            右边。
 */

class Solution
{
public:
    static void dutchFlag(vector<int> & nums, int value)
    {
        int less = -1, more = nums.size(), cur = 0;
        while (cur < more) {
            if (nums[cur] < value) {
                swap(nums[++less], nums[cur++]);
            } else if (nums[cur] == value){
                cur++;
            } else {
                swap(nums[--more], nums[cur]);
            }
        }
    }

};

int main(void)
{
    vector<int> nums{3, 1, 4, 2, 9, 0, -1, 4, 2, 3, 4, 4, 2, 5, 6, 8};
    int value = 4;
    Solution::dutchFlag(nums, value);
    for (auto elem : nums) {
        cout << elem << " ";
    }
    cout << endl;
}
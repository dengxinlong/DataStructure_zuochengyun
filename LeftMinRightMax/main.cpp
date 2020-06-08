#include <iostream>
#include <vector>

using namespace std;

/*
 *问题描述：将小于value的数移动到数组的左边，将大于value的数移动的数组的右边
 */
class Solution
{
public:
    static void leftMinRightMax(vector<int> & nums, int value)
    {
        // for (int cur = 0, i = -1; cur < nums.size(); cur++) {
        //     if (nums[cur] < value) {
        //         swap(nums[++i], nums[cur]);
        //     }
        // }
        int less = -1;
        int equalMore = nums.size();
        for (int i = 0; i < nums.size();) {
            if (nums[i] < value) {
                less++;
                i++;
            } else {
                std::swap(nums[i], nums[--equalMore]);
            }
        }
    }
};

int main(void)
{
    vector<int> nums{3, 0, 1, 8, 0, -2, 4, 9};
    int value = 4;
    Solution::leftMinRightMax(nums, value);
    for (auto elem : nums) {
        cout << elem << " ";
    }
    cout << endl;
}
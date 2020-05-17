#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Solution
{
public:
    static T getMax(const vector<T> & nums)
    {
        return getMax(nums, 0, nums.size() - 1);
    }

private:
    static T getMax(const vector<T> & nums, int low, int high)
    {
        if (low == high)
            return nums[low];
        int middle = low + ((high - low) >> 1);
        T maxLeft = getMax(nums, low, middle);
        T maxRight = getMax(nums, middle + 1, high);
        return nums[maxLeft] >  nums[maxRight] ? nums[maxLeft] : nums[maxRight];
    }
};

int main(void)
{
    vector<int> nums{3, 4, 1, -3, 5, 3};
    cout << Solution<int>::getMax(nums) << endl;
}
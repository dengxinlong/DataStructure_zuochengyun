#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 *问题描述：给定一个数组，求如果排序之后，相邻两数的最大差值，要求时
           间复杂度O(N)，且要求不能用非基于比较的排序。
 */

template<class T>
class Solution
{
public:
    static int getConnectedNumMax_1(vector<T> & nums) //直接使用排序算法，然后依次遍历得到最终答案，时间复杂度为O(N*logN)
    {
        if (nums.size() < 2)
            return 0;
        std::sort(nums.begin(), nums.end());

        int max = nums[1] - nums[0];
        for (int i = 2; i < nums.size(); i++) {
            max = nums[i] - nums[i - 1] > max ? nums[i] - nums[i - 1] : max;
        }
        return max;
    }

    //利用桶排序的思想，总共有N个数，找到这个数组的最大值和最小值设置N ＋１个桶，然后把这Ｎ个数等分到Ｎ＋１个桶里面，同时至少存在一个空桶，这个空桶的目的就是使得保证想连两数的最大值不可能存在同一个桶里面，但是并不能保证答案在空桶的旁边
    //当有三个以上的数进入桶里面的时候，只保存进入这个桶里面的数的最大值和最小值，同时，设置一个变量bool，标识该桶里面是否有数进去过，这样在遍历桶求结果的过程中，结果只会出现在相连两个有数桶，用后一个非空桶的最小值减去前一个非空桶的最大值，最终得到结果
    static int getConnectedNumMax_2(vector<T> & nums)
    {
        int length = nums.size();
        if (length < 2)
            return 0;
        int maxValue = nums[0];
        int minValue = nums[0];
        for (int i = 1; i < length; ++i) { //找到当前数组的最大值和最小值
            maxValue = nums[i] > maxValue ? nums[i] : maxValue;
            minValue = nums[i] < minValue ? nums[i] : minValue;
        }
        if (maxValue == minValue)
            return 0;

        vector<bool> has(length + 1, false);       //三个桶，相当于一个桶里面有三个变量，第一个bool表示该桶是否有数，第二个变量表示当前进入到该桶当中的所有数中的最大值，下面的mins类似
        vector<int> maxs(length + 1, 0);
        vector<int> mins(length + 1, 0);

        int belong = -1;
        for (int i = 0; i < length; i++) { //把所有元素都放入到某个桶里面
            belong = bucket(nums[i], length, minValue, maxValue); //计算当前数属于哪个桶
            maxs[belong] = has[belong] ? max(nums[i], maxs[belong]) : nums[i];
            mins[belong] = has[belong] ? min(nums[i], mins[belong]) : nums[i];
            has[belong] = true;
        }
        int ret = 0;
        int lastMax = maxs[0];  //maxs[0]位置一定有数
        for (int i = 1; i < has.size(); i++) { //遍历桶，得出结果
            if (has[i]) {
                ret = max(ret, mins[i] - lastMax);
                lastMax = maxs[i];
            }
        }
        return ret;
    }

private:
    static int bucket(int value, int length, int min, int max)
    {
        return (int)((value - min) * length / (max - min));
    }

    static int max(int value1, int value2)
    {
        return value1 > value2 ? value1 : value2;
    }

    static int min(int value1, int value2)
    {
        return value1 < value2 ? value1 : value2;
    }

};




int main(void)
{
    vector<int> nums{4, 1, 0, 1, -2, 8, 3};
    int max = Solution<int>::getConnectedNumMax_1(nums);
    cout << max << endl;

    max = Solution<int>::getConnectedNumMax_2(nums);
    cout << max << endl;
    return 0;
}
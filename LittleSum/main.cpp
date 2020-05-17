#include <iostream>
#include <vector>

using namespace std;

/*
 *问题描述：小和问题
 *         在一个数组当中，每个数左边比当前数小的数累加起来，叫做这个数组的小和。求一个数组的小和
 */

/*
 *例子：[1,3,4,2,5]
        1左边比1小的数，没有；
        3左边比3小的数，1；
        4左边比4小的数，1、3；
        2左边比2小的数，1；
        5左边比5小的数，1、3、4、2；
        所以小和为1+1+3+1+1+3+4+2=16
 */

class Solution
{
public:
    //直接暴力破解，时间复杂度O(n^2)
    static int littleSum_1(const vector<int> & nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    sum += nums[j];
                }
            }
        }

        return sum;
    }

    //利用归并排序中的归并过程来计算，时间复杂度为O(N*lonN)，空间复杂度为O(N)
    static int littleSum_2(vector<int> & nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    // static int mergeSort(vector<int> & nums)
    // {
    //     return mergeSort(nums, 0, nums.size() - 1);
    // }

    static int mergeSort(vector<int> & nums, int low, int high)
    {
        if (low == high)
            return 0;
        int mid = low + ((high - low) >> 1);
        return mergeSort(nums, low, mid)
                 + mergeSort(nums, mid + 1, high)
                 + merge(nums, low, high);
    }

    static int merge(vector<int> & nums, int low, int high)
    {
        vector<int> helps(high - low + 1);
        int mid = low + ((high - low) >> 1);
        int i = low, j = mid + 1, k = 0;
        int sum = 0;
        while (i <= mid && j <= high) {
            if (nums[i] < nums[j]) {
                sum += nums[i] * (high - j + 1); //计算小和
                helps[k++] = nums[i++];
            } else {
                helps[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            helps[k++] = nums[i++];
        }
        while (j <= high) {
            helps[k++] = nums[j++];
        }
        for (int i = 0; i < helps.size(); ++i) {
            nums[low + i] = helps[i];
        }
        return sum;
    }

};

int main(void)
{
    vector<int> nums{1, 3, 4, 2, 5};
    int sum = Solution::littleSum_1(nums);
    cout << sum << endl;
    cout << Solution::littleSum_2(nums) << endl;
    return 0;
}
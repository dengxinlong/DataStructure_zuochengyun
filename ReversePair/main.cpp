#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 *问题描述：在一个数组中，左边的数如果比右边的数大，则折两个数构成一个逆序对，请打印所有逆序
           对。
 */

class Solution
{
public:
    //暴力破解
    static vector<vector<int>> reversePair_1(vector<int> & nums)
    {
        vector<vector<int>> rets;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] > nums[i])
                    rets.push_back(vector<int>{nums[j], nums[i]});
            }
        }
        return rets;
    }

    //根据归并排序的的思想，利用归并排序中的归并过程来解决
    static vector<vector<int>> reversePair_2(vector<int> & nums)
    {
        vector<vector<int>> rets;
        return mergeSort(nums, 0, nums.size() - 1);
    }
private:
    static vector<vector<int>> mergeSort(vector<int> & nums, int low, int high)
    {
        if (low == high)
            return vector<vector<int>>{0};
        int mid = low + ((high - low) >> 1);

        vector<vector<int>> leftPair = mergeSort(nums, low, mid);
        vector<vector<int>> rightPair = mergeSort(nums, mid + 1, high);
        vector<vector<int>> sumPair = merge(nums, low, high);
        mergeVector(leftPair, rightPair);
        mergeVector(leftPair, sumPair);
        return leftPair;
    }

    static void mergeVector(vector<vector<int>> & nums1, const vector<vector<int>> & nums2)
    {
        for (auto elem : nums2) {
            nums1.push_back(elem);
        }
    }

    static vector<vector<int>> merge(vector<int> & nums, int low, int high)
    {
        vector<int> helps(high - low + 1);
        int mid = low + ((high - low) >> 1);
        int i = low, j = mid + 1, k = 0;
        vector<vector<int>> rets;
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                helps[k++] = nums[i++];
            } else {
                for (int index = i; index <= mid; index++) { //添加逆序对
                    rets.push_back(vector<int>{nums[index], nums[j]});
                }
                helps[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            helps[k++] = nums[i++];
        }
        while (j <= high) {
            helps[k++] = nums[j++];
        }
        for (int i = 0; i < helps.size(); i++) {
            nums[low + i] = helps[i];
        }
        return rets;
    }
};

int main(void)
{
    vector<int> nums{1, 4, 9, 1, 4, 5};
    vector<vector<int>> rets = Solution::reversePair_2(nums);
    for (auto nums : rets) {
        for (auto elem : nums)
            cout << elem << " ";
        cout << endl;
    }
    return 0;
}
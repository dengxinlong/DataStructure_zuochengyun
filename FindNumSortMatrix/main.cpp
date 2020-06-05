#include <iostream>
#include <vector>

using namespace std;

/*
 *问题描述：在一个行和列都已经排好序的数组中查找一个数，存在则返回true，不存在则返回false
 */
class FindNumSortMatrix
{
public:
    //暴力破解，时间复杂度O(N * M)
    static bool findNumSortMatrix_1(const vector<vector<int>> & nums, int value)
    {
        if (nums.size() < 1)
            return false;
        for (auto vec : nums) {
            for (auto elem : vec) {
                if (elem == value) return true;
            }
        }
        return false;
    }

    //二分查找，时间复杂O(N * logM)
    static bool findNumSortMatrix_2(const vector<vector<int>> & nums, int value)
    {
        if (nums.size() < 1)
            return false;
        for (int i = 0; i < nums.size(); i++) {
            if (binarySearch(nums[i], value)) return true;
        }
    }

    //根据数组的特性进行查找，时间复杂度为O(N + M)
    static bool findNumSortMatrix_3(const vector<vector<int>> & nums, int value)
    {
        if (nums.size() < 1)
            return false;

        int indexR = 0;
        int indexC = nums[0].size() - 1;        //定位到第一行的最右边的点
        while (indexC >= 0 && indexR <= nums.size() - 1) {
            if (value == nums[indexR][indexC]) {
                return true;
            } else if (value < nums[indexR][indexC]) {
                indexC--;
            } else {
                indexR++;
            }
        }
        return false;
    }

private:
    static bool binarySearch(const vector<int> & nums, int value)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] < value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low] == value;
    }
};

int main(void)
{
    vector<vector<int>> nums{{1, 2, 3, 7}, {5, 6, 6, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    cout << FindNumSortMatrix::findNumSortMatrix_2(nums, 9) << endl;
    return 0;
}
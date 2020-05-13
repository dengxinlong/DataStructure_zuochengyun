#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> generateArray(int maxSize, int maxValue)
{
    srand(time(NULL));
    vector<int> nums(rand() % 10 / 10.0 * maxSize);

    int cap = nums.size();
    for (int i = 0; i < cap; i++) {
        nums.push_back(rand() % 10 / 10.0 * maxValue);
    }

    return nums;
}

void print(const vector<int> & nums)
{
    for (const auto elem : nums) {
        cout << elem << " ";
    }
    cout << endl;
}

bool compare(vector<int> & nums1, vector<int> & nums2)
{
    if (nums1.size() != nums2.size())
        return false;
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    print(nums1);
    print(nums2);
    for (int i = 0; i < nums1.size(); i++) {
        if (nums1[i] != nums2[i])
            return false;
    }
    return true;
}

class Solution
{
public:
    static vector<int> notToA1(vector<int> & nums1, vector<int> & nums2)
    {
        vector<int> rets;
        for (int i = 0; i < nums2.size(); i++) {
            int j = 0;
            for (; j < nums1.size(); j++) {
                if (nums1[j] == nums2[i]) break;
            }
            if (j == nums1.size()) rets.push_back(nums2[i]);
        }

        return rets;
    }

    static vector<int> notToA2(vector<int> & nums1, vector<int> & nums2)
    {
        vector<int> rets;
        for (int i = 0; i < nums2.size(); i++) {
            //在nums1数组中进行二分查找
            int low = 0, high = nums1.size() - 1;
            while (low < high) {
                int mid = low + ((high - low + 1) >> 1);
                if (nums1[mid] > nums2[i]) high = mid - 1;
                else low = mid;
            }
            if (nums1[low] != nums2[i]) rets.push_back(nums2[i]);
        }

        return rets;
    }

    //利用归并排序的思想
    static vector<int> notToA3(vector<int> & nums1, vector<int> & nums2)
    {
        vector<int> rets;
        std::sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) i++;
            else rets.push_back(nums2[j++]);
        }
        // if (nums2[j] == nums1[nums1.size() - 1]) j++;
        while (j < nums2.size()) {
            rets.push_back(nums2[j++]);
        }

        return rets;
    }
};

void binarySearch(const vector<int> & nums, int value)
{
    //在nums1数组中进行二分查找
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + ((high - low + 1) >> 1);
        if (nums[mid] > value)
            high = mid - 1;
        else
            low = mid;
    }
    if (nums[low] != value)
        cout << "not" << endl;
    else
        cout << "do" << endl;
}

int main(void)
{
    vector<int> nums1 = generateArray(20, 50);
    vector<int> nums2 = generateArray(10, 60);
    std::sort(nums1.begin(), nums1.end());
    cout << "nums1: " << endl;
    print(nums1);
    cout << "nums2: " << endl;
    print(nums2);
    // vector<int> nums1{1, 2, 4, 8, 9}, nums2{3, 5, 6, 9, 10};
    vector<int> rets1 = Solution::notToA1(nums1, nums2);
    vector<int> rets2 = Solution::notToA3(nums1, nums2);
    cout << "rets1: " << endl;
    print(rets1);
    cout << "rets2: " << endl;
    print(rets2);
    cout << compare(rets1, rets2) << endl;
    return 0;
}
#include <time.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
class QuickSortClassic
{
public:
    static void quickSort(vector<T> & nums)
    {
        quickSort(nums, 0, nums.size() - 1);
    }

private:
    static void quickSort(vector<T> & nums, int low, int high)
    {
        if (low >= high)
            return;
        // srand(time(NULL));
        // swap(nums[(int)(low + (rand() % 10 / 10.0) * (high - low + 1))], nums[high]);
        // rand() % 10
        int pos = partition(nums, low, high);
        quickSort(nums, low, pos - 1);
        quickSort(nums, pos + 1, high);
    }

    static int partition(vector<T> & nums, int low, int high)
    {
        int less = low - 1, cur = low;
        while (cur < high) {
            if (nums[cur] <= nums[high])
                swap(nums[++less], nums[cur++]);
            else
                cur++;
        }
        swap(nums[high], nums[++less]);
        return less;
    }
};

template<class T>
class QuickSortAdvance
{
public:
    static void quickSort(vector<T> & nums)
    {
        quickSort(nums, 0, nums.size() - 1);
    }
private:
    static void quickSort(vector<T> & nums, int low, int high)
    {
        if (low >= high)
            return;
        vector<int> pos = partition(nums, low, high);
        quickSort(nums, low, pos[0] - 1);
        quickSort(nums, pos.at(1) + 1, high);
    }

    static vector<int> partition(vector<T> & nums, int low, int high)
    {
        int less = low - 1, more = high;
        while (low < more) {
            if (nums[low] < nums[high])
                swap(nums[++less], nums[low++]);
            else if (nums[low] == nums[high])
                low++;
            else
                swap(nums[--more], nums[low]);
        }
        swap(nums[more], nums[high]);
        return vector<int>{less + 1, more}; //返回等于最后一个数范围
    }

};



int main(void)
{
    vector<int> nums1{ 1, -1, -4, -2, 6, 4, 8, 3};
    QuickSortClassic<int>::quickSort(nums1);
    sort(nums1.begin(), nums1.end());
    for (auto elem : nums1) {
        cout << elem << " ";
    }
    cout << endl;

    vector<int> nums2{3, 1, -1, -4, -2, 6, 4, 8};
    QuickSortAdvance<int>::quickSort(nums2);
    for (auto elem : nums2) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
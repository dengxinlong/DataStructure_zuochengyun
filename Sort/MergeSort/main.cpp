#include <iostream>
#include <vector>

using namespace std;

template<class T>
class MergeSort
{
public:
    static void mergeSort(vector<T> & nums)
    {
        if (nums.size() < 2)
            return;
        mergeSort(nums, 0, nums.size() - 1);
    }

private:
    static void mergeSort(vector<T> & nums, int low, int high)
    {
        if (low == high)
            return;
        int mid = low + ((high - low) >> 1);
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, high);
    }

    static void merge(vector<T> & nums, int low, int high)
    {
        vector<T> helps(high - low + 1);
        int mid = low + ((high - low) >> 1);
        int i = low, j = mid + 1, k = 0;
        while (i <= mid && j <= high) {
            helps[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];    //这里的比较加上 = ，使得该排序算法是稳定的
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
    }

};

int main(void)
{
    vector<int> nums{1, 3, 0, -1, 9, 3, 2, 1};
    MergeSort<int>::mergeSort(nums);
    for (auto elem : nums)
        cout << elem << " ";
    cout << endl;

    return 0;
}
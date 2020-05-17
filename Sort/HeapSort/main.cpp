#include <iostream>
#include <vector>

using namespace std;

template<class T>
class HeapSort
{
public:
    static void heapSort(vector<T> & nums)
    {
        if (nums.size() < 2)
            return;
        for (int i = 0; i < nums.size(); i++) { //将数组调整为大根堆
            heapInsert(nums, i);
        }
        int heapSize = nums.size();
        swap(nums[0], nums[--heapSize]);
        while (heapSize > 0) {
            heapify(nums, 0, heapSize);
            swap(nums[0], nums[--heapSize]);
        }
    }

private:
    static void heapInsert(vector<T> & nums, int index)
    {
        while (nums[index] > nums[(index - 1) / 2]) {
            swap(nums[index], nums[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    static void heapify(vector<int> & nums, int index, int heapSize)
    {
        int left = index * 2 + 1;
        while (left < heapSize) {
            int largest = left + 1 < heapSize && nums[left] < nums[left + 1] ? left + 1 : left;
            largest = nums[index] > nums[largest] ? index : largest;
            if (largest == index) break;
            swap(nums[index], nums[largest]);
            index = largest;
            left = index * 2 + 1;
        }
    }
};

int main(void)
{
    vector<int> nums{1, 3, 1, 1, 6, 9, 0, -1};
    HeapSort<int>::heapSort(nums);
    for (auto elem : nums) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
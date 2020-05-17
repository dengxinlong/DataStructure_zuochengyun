#include <iostream>
#include <vector>

using  namespace std;

template<class T>
class SelectSort
{
public:
    static void selectSort(vector<T> & nums)
    {
        if (nums.size() < 2)
            return;

        int minIndex;
        for (int i = 0; i < nums.size() - 1; ++i) {
            minIndex = i;
            for (int j = i + 1; j < nums.size(); ++j) {
                minIndex = nums[minIndex] > nums[j] ? j : minIndex;
            }
            swap(nums[minIndex], nums[i]);
        }
    }
};

int main(void)
{
    vector<int> nums{1, 0, -1, 4, 8, 9, -3};
    SelectSort<int>::selectSort(nums);
    for (auto elem : nums)
        cout << elem << " ";
    cout << endl;

    return 0;
}
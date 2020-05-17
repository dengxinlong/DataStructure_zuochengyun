#include <iostream>
#include <vector>

using  namespace std;

template<class T>
class InsertSort
{
public:
    static void insertSort(vector<T> & nums)
    {
        if (nums.size() < 2)
            return;

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i; j > 0 && nums[j] < nums[j - 1]; j--) {
                swap(nums[j], nums[j - 1]);
            }
        }
    }
};

int main(void)
{
    vector<int> nums{1, 0, -1, 4, 8, 9, -3};
    InsertSort<int>::insertSort(nums);
    for (auto elem : nums)
        cout << elem << " ";
    cout << endl;

    return 0;
}
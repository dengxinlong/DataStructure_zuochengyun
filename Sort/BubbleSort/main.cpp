#include <iostream>
#include <vector>

using namespace std;

template<class T>
class BubbleSort
{
public:
    static void bubbleSort(vector<T> & nums)
    {
        for (int i = nums.size() - 1; i > 0; i--) {
             for (int j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1])
                    swap(nums[j], nums[j + 1]);
            }
        }

    }
};


int main(void)
{
    vector<int> nums{3, 1, 0, -1, 4, 1, 9};
    BubbleSort<int>::bubbleSort(nums);
    for (auto elem : nums)
        cout << elem << " ";
    cout << endl;
    return 0;
}
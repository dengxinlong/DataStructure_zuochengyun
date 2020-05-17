#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> nums1{1, 3, 4, 5, 6};
    vector<int> nums2{3, 4, 5, 9};
    nums1 += nums2;
    for (auto elem : nums1) {
        cout << elem << " ";
    }
    cout << endl;
}
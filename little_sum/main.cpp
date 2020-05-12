#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int littleSum_1(const vector<int> & nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    sum += nums[j];
                }
            }
        }

        return sum;
    }

    static int littleSum_2(const vector<int> & nums)
    {
        int sum = 0;
    }

};

int main(void)
{
    vector<int> nums{1, 3, 4, 2, 5};
    int sum = Solution::littleSum_1(nums);
    cout << sum << endl;

    return 0;
}
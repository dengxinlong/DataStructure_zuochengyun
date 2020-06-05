#include <iostream>
#include <vector>

using namespace std;

//将一个矩阵顺时钟旋转90度
class RotateSquareMatrix
{
public:
    static void Rotate(vector<vector<int>> & nums)
    {
        int topLeftCornerRow = 0;
        int topLeftCornerCol = 0;
        int bottomRightCornerRow = nums.size() - 1;
        int bottomRightCornerCol = nums[0].size() - 1;
        while (topLeftCornerRow < bottomRightCornerRow) {
            rotateEdge(nums, topLeftCornerRow++, topLeftCornerCol++, bottomRightCornerRow--, bottomRightCornerCol--);
        }
    }

    static void printMatrix(const vector<vector<int>> & nums)
    {
        for (auto vec : nums) {
            for (auto elem : vec) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

private:
    static void rotateEdge(vector<vector<int>> & nums, int topLeftCornerRow, int topLeftCornerCol,
                                                       int bottomRightCornerRow, int bottomRightCornerCol)
    {
        int times = bottomRightCornerCol - topLeftCornerCol;
        for (int i = 0; i < times; i++) {  //依次找到某个数的往后的几个连续的数，这几个连续的数需要连续变换的；变换的时候从逆着变换，这样容易理解和书写代码
            int temp = nums[topLeftCornerRow][i + topLeftCornerCol];
            nums[topLeftCornerRow][i + topLeftCornerCol] = nums[bottomRightCornerRow - i][topLeftCornerCol];
            nums[bottomRightCornerRow - i][topLeftCornerCol] = nums[bottomRightCornerRow][bottomRightCornerCol - i];
            nums[bottomRightCornerRow][bottomRightCornerCol - i] = nums[topLeftCornerRow + i][bottomRightCornerCol];
            nums[topLeftCornerRow + i][bottomRightCornerCol] = temp;
        }
    }
};

int main(void)
{
    vector<vector<int>> nums;
    vector<int> vec;
    for (int i = 1; i < 5; i++)
        vec.push_back(i);
    nums.push_back(vec);

    vec.clear();
    for (int i = 5; i < 9; i++)
        vec.push_back(i);
    nums.push_back(vec);

    vec.clear();
    for (int i = 9; i < 13; i++)
        vec.push_back(i);
    nums.push_back(vec);

    vec.clear();
    for (int i = 13; i < 17; i++)
        vec.push_back(i);
    nums.push_back(vec);

    RotateSquareMatrix::printMatrix(nums);
    cout << endl;
    RotateSquareMatrix::Rotate(nums);
    RotateSquareMatrix::printMatrix(nums);


    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

//螺旋打印二维数组
/*
 *例子:  1  2  3  4  5  6
         7  8  9 10 11 12
        13 14 15 16 17 18
        19 20 21 22 23 24
        25 26 27 28 29 30
 *结果：1 2 3 4 5 6 12 18 24 30 29 28 27 26 25 19 13 7 8 9 10 11 17 23 22 21 20 14 15 16
 */

class PrintMatrixSpiralOrder
{
public:
    static void printMatrixSpiralOrder(const vector<vector<int>> & nums)
    {
        if (nums.size() < 1)
            return;
        int topLeftCornerRow = 0;
        int topLeftCornerCol = 0;
        int bottomRightCornerRow = nums.size() - 1;
        int bottomRightCornerCol = nums[0].size() - 1;
        while (topLeftCornerRow <= bottomRightCornerRow && topLeftCornerCol <= bottomRightCornerCol) {
            printEdge(nums, topLeftCornerRow++, topLeftCornerCol++, bottomRightCornerRow--, bottomRightCornerCol--);

        }
        cout << endl;
    }

private:
    static void printEdge(const vector<vector<int>> & nums, int topLeftCornerRow, int topLeftCornerCol,
                                                            int bottomRightCornerRow, int bottomRightCornerCol)
    {
        if (topLeftCornerRow == bottomRightCornerRow) { //现在只有一行，对应到二维数组中即只有一个数组
            for (int i = topLeftCornerCol; i <= bottomRightCornerCol; i++) {
                cout << nums[bottomRightCornerRow][i] << " ";
            }
        } else if (topLeftCornerCol == bottomRightCornerCol) { //现在只有一列，对应到二维数组中即有n个一维数组，每个数组只有一个元素
            for (int i = topLeftCornerRow; i <= bottomRightCornerRow; i++) {
                cout << nums[i][bottomRightCornerCol] << " ";
            }
        } else { //完整的二维数组
            //下面的for循环中，i 的初值可能容易搞混，这时可以使用两个变量，其中一个变量为curRow：用于上下遍历
            //另一个变量为curCol：用于左右遍历
            for (int i = topLeftCornerCol; i < bottomRightCornerCol; i++) {
                cout << nums[topLeftCornerRow][i] << " ";
            }
            for (int i = topLeftCornerRow; i < bottomRightCornerRow; i++) {
                cout << nums[i][bottomRightCornerCol] << " ";
            }
            for (int i = bottomRightCornerCol; i > topLeftCornerCol; i--) {
                cout << nums[bottomRightCornerRow][i] << " ";
            }
            for (int i = bottomRightCornerRow; i > topLeftCornerRow; i--) {
                cout << nums[i][topLeftCornerCol] << " ";
            }
        }
    }
};

int main(void)
{
    vector<vector<int>> nums;
    vector<int> vec;
    for (int i = 1; i < 7; i++) {
        vec.push_back(i);
    }
    nums.push_back(vec);

    vec.clear();
    for (int i = 7; i < 13; i++) {
        vec.push_back(i);
    }
    nums.push_back(vec);

    vec.clear();
    for (int i = 13; i < 19; i++) {
        vec.push_back(i);
    }
    nums.push_back(vec);

    vec.clear();
    for (int i = 19; i < 25; i++) {
        vec.push_back(i);
    }
    nums.push_back(vec);

    vec.clear();
    for (int i = 25; i < 31; i++) {
        vec.push_back(i);
    }
    nums.push_back(vec);

    // vec.clear();
    // for (int i = 25; i < 31; i++) {
    //     vec.push_back(i);
    // }
    // nums.push_back(vec);

    // vector<vector<int>> nums;
    // vector<int> vec{1};
    // nums.push_back(vec);

    // vec.clear();
    // vec.push_back(2);
    // nums.push_back(vec);

    // vec.clear();
    // vec.push_back(3);
    // nums.push_back(vec);

    // vec.clear();
    // vec.push_back(4);
    // nums.push_back(vec);

    // vec.clear();
    // vec.push_back(5);
    // nums.push_back(vec);
    PrintMatrixSpiralOrder::printMatrixSpiralOrder(nums);

    return 0;
}
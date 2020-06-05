#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size()) return 0;
        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ret++;
                    infect(i, j, grid);
                }
            }
        }
        return ret;
    }

private:
    void infect(int i, int j, vector<vector<char>> & grid)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1') return;
        grid[i][j] = '2';

        infect(i, j - 1, grid);
        infect(i - 1, j, grid);
        infect(i, j + 1, grid);
        infect(i + 1, j, grid);
    }
};

int main(void)
{
    Solution so;
    vector<vector<char>> grid{{'1', '1', '1', '1', '0'},
                             {'1', '1', '0', '1', '0'},
                            {'1', '1', '0', '0', '0'}};
    cout << so.numIslands(grid) << endl;

    return 0;
}
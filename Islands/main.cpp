#include <iostream>
#include <vector>
#include <queue>
#include <utility>


//三种方法：深度优先搜索；广度优先搜索；并差集

//方法一：深度优先搜索
class Island
{
public:
    static int getNums(std::vector<std::vector<int>> nums)
    {
        if (!nums.size()) return 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                if (nums[i][j] == 1) {
                    ret++;
                    infect(i, j, nums);
                }
            }
        }
        return ret;
    }

private:
    static void infect(int i, int j, std::vector<std::vector<int>> & nums)
    {
        if (i < 0 || j < 0 || i >= nums.size() || j >= nums[0].size() || nums[i][j] != 1) return;
        nums[i][j] = 2;
        infect(i, j - 1, nums);
        infect(i - 1, j, nums);
        infect(i, j + 1, nums);
        infect(i + 1, j, nums);
    }
};

//方法二：广度优先搜索
class Island_2
{
public:
    static int getNums(std::vector<std::vector<std::string>> & nums)
    {
        if (!nums.size()) return 0;
        int isLand = 0;
        int nr = nums.size();
        int nc = nums[0].size();
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (nums[i][j] == "1") {
                    isLand++;
                    std::queue<std::pair<int, int>> helpQue;
                    helpQue.push({i, j});
                    nums[i][j] = "0";
                    while (!helpQue.empty()) {
                        auto rc = helpQue.front();
                        helpQue.pop();
                        int r = rc.first, c = rc.second;
                        if (r - 1 >= 0 && nums[r - 1][c] == "1") {
                            helpQue.push({r - 1, c});
                            nums[r - 1][c] = "0";
                        }
                        if (c - 1 >= 0 && nums[r][c - 1] == "1") {
                            helpQue.push({r, c - 1});
                            nums[r][c - 1] = "0";
                        }
                        if (r + 1 < nr && nums[r + 1][c] == "1") {
                            helpQue.push({r + 1, c});
                            nums[r + 1][c] = "0";
                        }
                        if (c + 1 < nc && nums[r][c + 1] == "1") {
                            helpQue.push({r, c + 1});
                            nums[r][c + 1] = "0";
                        }
                    }

                }
            }
        }
        return isLand;
    }
};

//方法三：并查集
class UnionFind {
public:
    UnionFind(std::vector<std::vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                } else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {    //可以优化
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                std::swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
    int count;
};

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid);
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r-1][c] == '1') uf.unite(r * nc + c, (r-1) * nc + c);
                    if (r + 1 < nr && grid[r+1][c] == '1') uf.unite(r * nc + c, (r+1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c+1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
                }
            }
        }

        return uf.getCount();
    }
};

int main(void)
{
    std::vector<std::vector<std::string>> nums{{"1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","0","1","0","1","1"},{"0","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","0"},{"1","0","1","1","1","0","0","1","1","0","1","1","1","1","1","1","1","1","1","1"},{"1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},{"1","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},{"1","0","1","1","1","1","1","1","0","1","1","1","0","1","1","1","0","1","1","1"},{"0","1","1","1","1","1","1","1","1","1","1","1","0","1","1","0","1","1","1","1"},{"1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","0","1","1"},{"1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1"},{"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},{"0","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1"},{"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},{"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},{"1","1","1","1","1","0","1","1","1","1","1","1","1","0","1","1","1","1","1","1"},{"1","0","1","1","1","1","1","0","1","1","1","0","1","1","1","1","0","1","1","1"},{"1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","0"},{"1","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","0","0"},{"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},{"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},{"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"}};
    std::cout << Island_2::getNums(nums) << std::endl;

    return 0;
}
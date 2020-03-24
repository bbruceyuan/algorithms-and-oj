#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        int count = 0;

        // 使用 bfs 来做
        m = 0, n = 0;
        dfs(m, n, k, visit, count);

        return count;
    }

    void dfs(int m, int n, int k,
             vector<vector<bool>> &visit,
             int &count) {

        std::pair<int, int> p(m, n);
        if (m < 0 || n < 0 || m > visit.size() -1 || n > visit[0].size() -1 || visit[m][n] || sum(p) > k ) {
            // 递归中止条件
            return;
        }
        count += 1;
        visit[m][n] = true;

        dfs(m +1, n, k, visit, count);
        // bfs(m -1, n, k, visit, count);
        dfs(m, n + 1, k, visit, count);
        // bfs(m, n - 1, k, visit, count);
    }

    int sum(std::pair<int, int> p) {
        int res = 0;
        while (p.first) {
            res =  res + p.first % 10;
            p.first /= 10;
        }
        while (p.second) {
            res = res + p.second % 10;
            p.second /= 10;
        }
        return res;
    }

    int movingCountBfs(int m, int n, int k) {
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        std::queue<std::pair<int, int>> nodes;
        std::pair<int, int> p(0, 0);
        int count = 0;
        nodes.push(p);
        visit[p.first][p.second] = true;
        bfs(m, n, k, count, visit, nodes);
        return count;
    }

    void bfs(int m, int n, int k, int &count, vector<vector<bool>> &visit, std::queue<std::pair<int, int>> &nodes) {
        std::pair<int, int> p, tmp;

        while (!nodes.empty()) {
            p = nodes.front();
            nodes.pop();
            if (sum(p) <= k) {
                count++;
            } else {
                break;
            }
            tmp = std::make_pair(p.first + 1, p.second);

            if (p.first + 1 >= 0 && p.first + 1 < visit.size() && p.second >= 0
                && p.second < visit[0].size() && !visit[p.first + 1][p.second]
                && sum(tmp) <= k
            ) {
                // 把纵向增加
                visit[p.first + 1][p.second] = true;
                nodes.push(tmp);
            }
            tmp = std::make_pair(p.first, p.second + 1);
            if (p.first >= 0 && p.first < visit.size() && p.second + 1>= 0
                && p.second + 1< visit[0].size() && !visit[p.first][p.second + 1]
                && sum(tmp) <= k
            ) {
                // 把纵向增加
                visit[p.first][p.second + 1] = true;
                nodes.push(tmp);
            }

        }
    }

};

int main () {
    Solution solution;

    cout << solution.movingCount(16, 8, 4) << endl;
    cout << solution.movingCountBfs(16, 8, 4) << endl;
    return 0;
}

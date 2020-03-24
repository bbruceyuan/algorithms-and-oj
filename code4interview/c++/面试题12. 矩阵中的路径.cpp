#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (std::size_t i = 0; i < board.size(); i++) {
            for (std::size_t j = 0; j < board[0].size(); j++) {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool dfs (vector<vector<char>> &board, size_t i, size_t j, const string& word, size_t idx) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || word[idx] != board[i][j]) {
            return false;
        }
        if (idx == word.size() -1) {
            return true;
        }

        char tmp = board[i][j];
        board[i][j] = '$';

        bool res = dfs (board, i +1, j, word, idx+1) || dfs(board, i-1, j, word, idx+1) ||
                dfs (board, i, j -1, word, idx +1) || dfs(board, i, j+1, word, idx+1);
        board[i][j] = tmp;
        return res;
    }
};

int main () {
    Solution solution;
//    vector<vector<char>> b{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> b{{'A'}};
    std::string s = "Ab";

    cout << solution.exist(b, s) << endl;
    return 0;
}
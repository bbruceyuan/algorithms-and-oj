#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <limits>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;



class Solution {
public:
    vector<string> permutation (string s) {
        // 使用回溯 进行剪枝
        vector<string> res;
        permutationRecursive(s, res, 0);
        return res;
    }

    void permutationRecursive(string &s, vector<string> &res, std::size_t idx) {
        if (idx == s.size() -1) {
            res.push_back(s);
            return;
        }
        for (std::size_t i = idx; i < s.size(); i++) {
            // 用当前的字符和后面所有的字符做交换
            if (!isSwap(s, idx, i)) continue;
            std::swap(s[idx], s[i]);
            permutationRecursive(s, res, idx + 1);
            std::swap(s[idx], s[i]);
        }
    }

    bool isSwap(string str,int start,int end)
    {
        for(;start < end; start++)
        {
            if(str[start] == str[end])
                return false;
        }
        return true;
    }

    vector<string> combination (const string &s) {
        // 使用回溯，但是没有考虑字符重复的情况
        vector<string> res;
        for (int i = 0; i <= s.size(); i++) {
            // i 表示有 排列几个 字符
            string tmp;
            combinationRecursive(res, s, 0, i, tmp);
        }
        return res;
    }

    void combinationRecursive (vector<string> &res, const string &s, int start, int k, string &tmp) {
        // 这种行为比较好理解一点
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            tmp.push_back(s[i]);
            combinationRecursive(res, s, i+1, k, tmp);
            tmp.pop_back();
        }
    }

    void combinationRecursive2 (vector<string> &res, const string &s, int start, int k, string &tmp) {
        // 如果 k  == 0
        if (k == 0) {
            res.push_back(tmp);
            return;
        }
        for (int i = start; i < s.size() - k + 1; i++) {
            tmp.push_back(s[i]);
            combinationRecursive(res, s, i+1, k -1, tmp);
            tmp.pop_back();
        }
    }


    vector<string> permutation2(string s) {
        // 使用 Set 进行去重
        std::set<string> res;
        vector<bool> visited(s.size(), false);
        string tmp;
        permutationBack(s, tmp, res, visited);
        return vector<string>(res.begin(), res.end());
    }

    void permutationBack (string &s, string &tmp, std::set<string> &res, vector<bool> &visited) {
        // 递归中止条件
        if (tmp.size() == s.size()) {
            res.insert(tmp);
            return;
        }
        for (std::size_t i = 0; i < s.size(); i++) {
            if (visited[i] == true ) continue;
            tmp.push_back(s[i]);
            visited[i] = true;
            permutationBack (s, tmp, res, visited);
            tmp.pop_back();
            visited[i] = false;
        }
    }
};


int main() {
//    [8,9,2,3,7,0,5,4,6,1]
//    [6,8,2,1,3,9,0,7,4,5]
//    vector<int> a {8,9,2,3,7,0,5,4,6,1}, b {6,8,2,1,3,9,0,7,4,5};
    std::string s {"aab"};
    Solution solution;
    auto res = solution.combination(s);
    for (auto item: res) {
        cout << item << endl;
    }
    return 0;
}
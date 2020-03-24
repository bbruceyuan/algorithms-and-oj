#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    string reverseLeftWords(string s, int n) {
        size_t lenIdx = s.size() - 1, originalLen = s.size();
        int k = n;
        s.resize(s.size() + n);
        while (k) {
            s[lenIdx + k] = s[k -1];
            k--;
        }
        return s.substr(n, originalLen);
    }
};

int main() {
    Solution solution;
    cout << solution.reverseLeftWords("abcdef", 2);
    return 0;
}

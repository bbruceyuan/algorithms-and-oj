#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int sumNums(int n) {
        int ans = n;
        ans && (ans += sumNums(n -1));
        return ans;
    }
};

int main() {
    Solution solution;


    return 0;
}
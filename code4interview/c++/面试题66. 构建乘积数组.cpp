#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> res(a.size(), 1);
        int tmp = 1;

        for (int i = 0; i < a.size(); i++) {
            res[i] = tmp;
            tmp = tmp * a[i];
        }
        tmp = 1;
        for (int i = a.size() -1; i > -1; i--) {
            res[i] *= tmp;
            tmp *= a[i];
        }
        return res;

    }
};

int main() {
    Solution solution;
    return 0;
}
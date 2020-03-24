#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count(0);

        unsigned int flag = 1;
        while (flag) {
            if (n & flag)
                count++;
            flag = flag << 1;
        }

        return count;
    }

    int hammingWeight2(uint32_t n) {
        int count(0);

        while (n) {
            count++;
            n = (n -1) & n;
        }
        return count;
    }

};

int main () {
    Solution solution;
    int a{2};
    // 其实要无符号整数才可以这么做
    int c = a & 1;
    cout << c << endl;

//    cout << solution.hammingWeight(a) << endl;
    return 0;
}
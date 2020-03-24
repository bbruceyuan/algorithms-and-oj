#include <iostream>
using namespace std;


class Solution {
public:
    int fib (int n) {
        // 这个其实可以看成是一个优化过后的 dp 问题。
        int a = 0, b = 1;
        int tmp;
        for (std::size_t i = 0; i < n; i++) {
            tmp = a + b;
            a = b;
            b = tmp;
        }
        a = a % 1000000007;
        return a;
    }
    int fibRecursive(int n) {
        // 用来学习递归，会超时
        if (n <= 1) {
            return n;
        }
        return fibRecursive(n - 1) + fibRecursive(n-2);
    }
};


bool isTrue(int n) {
    Solution s;

    return s.fib(n) == s.fibRecursive(n);
}


int main () {
    Solution solution;
    for (int i = 0; i < 15; i++) {
        cout << isTrue(i) << endl;
    }
//    cout << solution.fibRecursive(5) << endl;
    return 0;
}
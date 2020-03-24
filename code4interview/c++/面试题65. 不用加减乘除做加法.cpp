#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        // 要使用 unsigned int， 不然好像会溢出
        while (a != 0) {
            int noCarryPlus = a ^ b  ; // 不进位加法
            a = (unsigned int)(a & b ) << 1 ; // 进位
            b = noCarryPlus ;
        }
        return b ;
    }
};

int main() {
    Solution solution;


    return 0;
}
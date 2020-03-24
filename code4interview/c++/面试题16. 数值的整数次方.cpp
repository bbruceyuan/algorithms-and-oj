#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        int i = n;
        while (i) {
            if (i & 1) res = res * x;
            x = x * x;
            i /= 2;
        }
        return n > 0 ? res : 1 /res;
    }
};


int main() {
//    string s = "[1,2,3,null,null,4,5]";



//    string str = "hello world";
//    cout << s.find_last_not_of("world");

    return 0;
}
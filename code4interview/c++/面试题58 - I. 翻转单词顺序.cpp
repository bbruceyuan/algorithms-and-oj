#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;


/*
    其实可以又比较多的做法
    方法一： 反转两次字符，第一次反转所有，第二次反转单词。不使用额外空间
    方法二：split(" ") concat
    方法三： 直接和我写的一样，遇到一个空格加到 ans 里面
*/


class Solution {
public:
    string reverseWords(string s) {
        // 最简单的方法，申明新的结果
        if(s.empty())return s;
        int len = 0;
        string res;
        for(int m = s.size()-1; m >=0; m--) {
            if(s[m]==' ' && len!=0) {
                res += s.substr(m + 1, len) + " ";
                len = 0;
                continue;
            }
            if(s[m]!= ' ')len++;
        }
        if( len !=0 )
            res += s.substr(0, len) + " ";
        if(res.size() > 0 )
            res.erase(res.size() - 1, 1);
        return res;
    }
};


int main() {
    Solution solution;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string replaceSpace(string s) {
        string::size_type pos(0);
        while (true) {
            if((pos=s.find(' ', pos))!=string::npos) {
                s.replace(pos,1,"%20");//替换
                pos += 3;
            }
            else break;
        }
        return s;
    }

    string replaceSpace2(string s) {
        if (s.empty()) return s;
        int spaceCount = 0;
        for (const auto & i: s) {
            if (i == ' ')spaceCount++;
        }
        std::size_t oldLen = s.size();

        std::size_t newLen = s.size() + spaceCount * 2;
        s.resize(newLen);
        while (oldLen != newLen) {
            --oldLen;
            if (s[oldLen] == ' ') {
                s[--newLen] = '0';
                s[--newLen] = '2';
                s[--newLen] = '%';
            } else
                s[--newLen] = s[oldLen];
        }
        return s;
    }
};

int main() {
    Solution solution;
    string s = "hello  world";

    cout << solution.replaceSpace2(
            "We are happy.") << endl;
    return 0;
}

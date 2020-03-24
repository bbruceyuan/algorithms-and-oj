#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto c:s) mp[c]++;
        for(auto c:s){
            if(mp[c]==1) return c;
        }
        return ' ';
    }
    
};


int main() {
    Solution solution;
    return 0;
}
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[null]";
        std::queue<TreeNode *> s;
        s.push(root);
        string ans = "[";

        TreeNode *cur;
        while (!s.empty()) {
            cur = s.front();
            s.pop();
            if (cur) {
                ans += std::to_string(cur->val);
                ans += ",";
            } else
                ans += "null,";

            if (cur) {
                s.push(cur->left);
                s.push(cur->right);
            }
        }

        ans.pop_back();
        ans += "]";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string valString = data.substr(1, data.length() - 2);

        auto tmpRes = split(valString, ',');
        if (tmpRes[0] == "null") {
            return nullptr;
        }
        auto root = new TreeNode(std::stoi(tmpRes[0]));
        std::size_t idx = 0, leftIdx, rightIdx;
        // 进行反序列化
        std::queue<TreeNode*> s;

        s.push(root);
        while (!s.empty() && idx < tmpRes.size()) {
            auto cur = s.front();
            s.pop();
            if (cur== nullptr) continue;
            leftIdx = idx + 1;
            rightIdx = idx + 2;

            if (leftIdx < tmpRes.size() && tmpRes[leftIdx] != "null")
                cur->left = new TreeNode(std::stoi(tmpRes[leftIdx]));
            else
                cur->left = nullptr;
            s.push(cur->left);

            if (rightIdx < tmpRes.size() && tmpRes[rightIdx] != "null")
                cur->right = new TreeNode(std::stoi(tmpRes[rightIdx]));
            else
                cur->right = nullptr;
            s.push(cur->right);
            idx = rightIdx;
        }
        return root;
    }

    std::vector<std::string> split(const std::string& s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        // 需要 import sstream
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }
};



int main() {
//    string s = "[1,2,3,null,null,4,5]";
    string s = "[5,2,3,null,null,2,4,3,1]";

    Codec tree;

    auto root = tree.deserialize(s);
    auto res = tree.serialize(root);
    cout << res << endl;

//    string str = "hello world";
//    cout << s.find_last_not_of("world");

    return 0;
}
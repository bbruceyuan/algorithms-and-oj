
#include <stack>
using namespace std;


class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int res;
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        if (!s2.empty()) {
            res = s2.top();
            s2.pop();
            return res;
        } else {
            // 如果 s2 为空
            if (s1.empty()) return -1;
            else {
                // 那么把  s1 的元素压入 s2 中
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                res = s2.top();
                s2.pop();
                return res;
            }
        }
    }

};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        st.push(x);
        if (miniStack.empty() || x <= miniStack.top() ) {
            miniStack.push(x);
        }
    }

    void pop() {
        int top = st.top();
        st.pop();
        if (top == miniStack.top()) {
            miniStack.pop();
        }
    }

    int top() {
        return st.top();
    }

    int min() {
        return miniStack.top();
    }

private:
    stack<int> st;
    stack<int> miniStack;
};


int main() {
    MinStack s;
//    stack<int> s2;
//
//    cout << s.top() << endl;
//    return 0;

    s.push(-2);
    s.push(0);
    s.push(-3);

    cout << s.min() << endl;
    s.pop();
    cout << s.top() << endl;


    return 0;
}
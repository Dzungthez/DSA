#include <bits/stdc++.h>

using namespace std;
// assume default DS in stack is int
class TwoStackToQueue {
private:
    stack<int> st1;
    stack<int> st2;

public:
    bool empty() {
        return st1.empty();
    }
    int size() {
        return st1.size();
    }
    void push(int val) {
        st1.push(val);
    }
    int back() {
        return st1.top();
    }
    int front() {
        int n = st1.size();
        int a = n;
        while (n && !st1.empty()) {
            st2.push(st1.top());
            st1.pop();
            n--;
        }
        int x = st2.top();
        while(a  && !st2.empty()) {
            st1.push(st2.top());
            st2.pop();
            a--;
        }
        return x;

    }
    void pop() {
        int n = st1.size();
        int a = n;
        while (n && !st1.empty()) {
            st2.push(st1.top());
            st1.pop();
            n--;
        }
        st2.pop();
        while(a - 1 > 0 && !st2.empty()) {
            st1.push(st2.top());
            st2.pop();
            a--;
        }
    }

};

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    TwoStackToQueue myQ;
    myQ.push(1);
    myQ.push(2);
    myQ.push(5);

    cout << myQ.front();
    myQ.pop();
    cout << myQ.front();
    return 0;
}
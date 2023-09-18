#include <bits/stdc++.h>

using namespace std;
// assume default DS in stack is int
class TwoQueueToStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    bool empty() {
        return q1.empty();
    }
    int size() {
        return q1.size();
    }
    void push(int val) {
        q1.push(val);
    }
    int top() {
        return q1.back();
    }
    void pop() {
        int n = q1.size();
        int tmp = n;
        while(n - 1 && !q1.empty()) {
            int x = q1.front();
            q2.push(x);
            q1.pop();
            n--;
        }
        q1.pop();
        while(tmp - 1 && !q2.empty()) {
            int x = q2.front();
            q1.push(x);
            q2.pop();
            tmp--;
        }
    }

};

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    TwoQueueToStack mySt;
    mySt.push(1);
    mySt.push(2);
    mySt.push(5);

    cout << mySt.top();
    mySt.pop();
    cout << mySt.top();
    return 0;
}
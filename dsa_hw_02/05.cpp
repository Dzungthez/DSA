#include <bits/stdc++.h>

using namespace std;
typedef struct Node* node;
struct Node{
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = nullptr;
    }
};
class MyStack{
public:
    node head;
    MyStack(){
        head = nullptr;}
    void push(int x){
        if (!head){
            head = new Node(x); return;
        }
        node ans = new Node(x);
        ans->next = head;
        head = ans;

    }
    void pop(){
        if (!head) return;
        if (head && !head->next) head = nullptr;
        else head = head->next;
    }
    void printreverse(node head){
        if (!head) return;
        if (head && !head->next){
            cout << head->val << " ";
            return;
        }
        printreverse(head->next);
        cout << head->val << " ";
        
    }
    void printlist(){
        node tmp = head;
        printreverse(tmp);
    }

};


int main() {
    ios :: sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    MyStack st;

    int n; cin >> n;
    cin.ignore();
    while(n--){
        string s; getline(cin,s );
        if (s[1] == 'u'){
            int x = (s[5] - 48);
            st.push(x);
        }
        else{
            st.pop();
        }
    }
    st.printlist();

    return 0;
}
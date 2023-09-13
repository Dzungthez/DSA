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
class MyQueue{
public:
    node head;
    MyQueue(){
        head = nullptr;}
    void enqueue(int x){
        if (!head){
            head = new Node(x); return;
        }
        node tmp = head;
        while(tmp  && tmp->next){
            tmp = tmp->next;
        }
        tmp->next = new Node(x);

    }
    void dequeue(){
        if (head && !head->next) head = nullptr;
        else head = head->next;
    }
    void printlist(){
        node tmp = head;
        while(tmp){
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
    }

};


int main() {
    ios :: sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    MyQueue q1;

    int n; cin >> n;
    cin.ignore();
    while(n--){
        string s; getline(cin, s);
        if (s[0] == 'e'){
            int x = (s[8] - 48);
            q1.enqueue(x);
        }
        else{
            q1.dequeue();
        }
    }
    q1.printlist();

    return 0;
}
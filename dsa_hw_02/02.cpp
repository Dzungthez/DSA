#include <bits/stdc++.h>

using namespace std;
typedef struct Node* node;
struct Node{
    int val;
    Node* next;

    Node(int val_){
        val = val_;
        next = nullptr;
    }
    Node(int val_, node next_ ){
        val = val_;
        next = next_;

    }
};

class Linked_List {
public:

    Node* head;
    Linked_List(){
        head = nullptr;
    }
    Linked_List(node a){
        head = a;
    }
    Linked_List(int val_){
        head = new Node(val_);
    }
    void insert(int pos, int x){
        if (head == nullptr){
            head = new Node(x);
            return;
        }
        if (pos == 0){
            node ans = new Node(x, head);
            head = ans;
            return;
        }
        int i = 0;
        node ans = new Node(x);
        node tmp = head;
        while (i < pos-1){
            tmp = tmp->next;
            i++;
        }
        ans->next = (tmp->next ? tmp->next : nullptr);
        tmp->next = ans;

    }
    void delete_ (int pos){
        if (pos == 0){
            head = head->next;
            return;
        }
        int i = 0;
        node tmp = head;
        while (i < pos-1){
            tmp = tmp->next;
            i++;
        }
        if (tmp->next && tmp->next->next) {
            tmp->next = tmp->next->next;
        } else {
            tmp->next = nullptr;
        }

    }

    void printlist(){
        node tmp = head;
        while (tmp){
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
    }
};

bool handleInp(string s) {
    if (s[0] == 'i') return true;
    return false;
}
// p-7, x- 9

int main() {
    ios :: sync_with_stdio(0);
   cin.tie(NULL);
   freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    cin.ignore();
    Linked_List list_;
    while(t--) {
        string s; getline(cin, s);
        bool Insert = handleInp(s);
        if (Insert){
            int pos = (s[7]-48);
            int x = (s[9] - 48);
            list_.insert(pos, x);

        }
        else{
            int pos = (s[7]- 48);
            list_.delete_(pos);
        }
    }
    list_.printlist();


    return 0;
}

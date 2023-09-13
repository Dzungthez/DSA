#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(int val) {
        value = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int count_triplets() {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return 0;
        }

        int cnt = 0;
        Node* prev = head;
        Node* cur = head->next;
        Node* next = (cur->next ? cur->next : nullptr);
        while(next)
        {
            int a = prev->value, b = cur->value,c = next->value;
            if (a + b+ c == 0) cnt++;
            prev = cur;
            cur = next;
            next = next->next;
        }
        return cnt;
    }
};


int main() {
    ios :: sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    DoublyLinkedList list;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        list.insert(num);
    }

    int count = list.count_triplets();
    cout << count << endl;

    return 0;

   

    return 0;
}
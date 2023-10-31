#include <bits/stdc++.h>

class BinaryHeap {
private:
    vector<int> heap;
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void swimUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

public:
    
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        swimUp(index);
    }

    int deleteMin() {
        if (heap.empty()) {
            throw std::runtime_error("empty");
        }
        int minValue = heap[0];
        int lastIndex = heap.size() - 1;
        heap[0] = heap[lastIndex];
        heap.pop_back();
        int index = 0;

        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < lastIndex && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }

            if (rightChild < lastIndex && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }

        return minValue;
    }

    void printAll() {
        for (int i : heap) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    BinaryHeap heap;

    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(7);
    heap.insert(20);

    heap.printAll();

    int minElement = heap.deleteMin();
    cout << minElement << endl;
    heap.printAll();
    return 0;
}

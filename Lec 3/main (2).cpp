#include <iostream>
using namespace std;

class Queue {
private:
    int *arr, front, rear, capacity, size;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    // Thêm phần tử vào cuối hàng đợi - O(1)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Hàng đợi đầy " << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng " << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng " << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {#include <iostream>
using namespace std;

class Queue {
private:
    int *arr, front, rear, capacity, size;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Hàng đợi đầy " << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng " << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng " << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng " << endl;
            return;
        }
        cout << "Hàng đợi: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
    }

    void freeMemory() {
        delete[] arr;
    }
};


        if (isEmpty()) {
            cout << "Hàng đợi rỗng " << endl;
            return;
        }
        cout << "Hàng đợi: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
    }

    void freeMemory() {
        delete[] arr;
    }
};


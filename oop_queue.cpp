#include <iostream>
using namespace std;

#define MAX 3

/*
 * Class representing a Queue
 * 
 */
class Queue {
private:
    int line[MAX];
    int front, rear, size;

public:
    Queue(): front(0), rear(0), size(0) {
        for (int i = 0; i < MAX; i++)
            line[i] = 0;
    }
    /*
     * Initiates the queue with initial elem
     * 
     * @param {int} value Data to be inserted
     */
    Queue(int value): front(0), rear(0), size(1) {
        line[front] = value;
        for (int i = 1; i < MAX; i++)
            line[i] = 0;
    }

    /*
     * Check if the queue is full
    */
    bool isFull() {
        return size == MAX;
    }

    /*
     * Check if the queue is empty 
    */
    bool isEmpty() {
        return size == 0;
    }

    /*
     * Inserts a new elem in the front of the queue
     * 
     * @param {int} value Data to be queued
     */
    void enqueue(int value) {
        if (!isFull()) {
            if(!isEmpty())
                front++;
            if (front == MAX)
                front = 0;
            line[front] = value;
            size++;
        } else {
            throw "Overflow!!!\nQueue is full.";
        }
        return;
    }

    /*
     * Removes and returns the oldest elem from the rear of the queue
     * 
     * Null 
     */
    int dequeue() {
        if(!isEmpty()) {
            int temp = line[rear];
            line[rear] = 0;
            rear++;
            if (rear == MAX)
                rear = 0;
            size--;
            return temp;
        } else {
            throw "Underflow!!!\nQueue is empty.";
        }
    }
};

int main() {
    Queue* q = new Queue;
    int x = 0;
    try {
        q->enqueue(20);
        q->enqueue(30);
        x = q->dequeue();
        q->enqueue(40);
        q->enqueue(50);
        x = q->dequeue();
        cout << "Dequeued: " << x << endl;
    } catch (const char* err) {
        cout << "Error: " << err << endl;
    }
    return 0;
}
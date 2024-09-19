//
// Created by Jace Dunn on 9/17/24.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 10

class my_queue
{
    int* arr;		// array to store queue elements
    int capacity;	// maximum capacity of the queue
    int front;		// front points to front element in the queue (if any)
    int rear;		// rear points to last element in the queue
    int count;		// current size of the queue

public:
    my_queue(int size = SIZE); 	// constructor
    ~my_queue();   				// destructor

    void dequeue();
    void enqueue(int x);
    int peek() const;
    int size() const;
    bool isEmpty() const;
    bool isFull() const;
};

// Constructor to initialize queue
inline my_queue::my_queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
inline my_queue::~my_queue()
{
    delete[] arr; // you are not required to test this function;
    // however, are there issues with it?
    // yes delete[] is required
}

// Utility function to remove front element from the queue
inline void my_queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return;
    }

    cout << "Removing " << arr[front] << '\n';

    front = (front + 1) % capacity;
    count--;
}

// Utility function to add an item to the queue
inline void my_queue::enqueue(int x)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        return;
    }

    cout << "Inserting " << x << '\n';

    rear = (rear + 1) % capacity;
    arr[rear] = x;
    count++;
}

// Utility function to return front element in the queue
inline int my_queue::peek() const
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return numeric_limits<int>::min();
    }
    return arr[front];
}

// Utility function to return the size of the queue
inline int my_queue::size() const
{
    return count;
}

// Utility function to check if the queue is empty or not
inline bool my_queue::isEmpty() const
{
    return (size() == 0);
}

// Utility function to check if the queue is full or not
inline bool my_queue::isFull() const
{
    return (size() == capacity); // my need to get rid of -1 here
}





#endif //QUEUE_H

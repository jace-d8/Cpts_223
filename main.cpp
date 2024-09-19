// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn

#include <queue>

#include "testQueue.h"

// define default capacity of the queue


// main function
int main()
{
    // call your test functions here!

    testQueue testQueue;
    testQueue.test_dequeue();
    testQueue.test_enqueue();
    testQueue.test_peek();
    testQueue.test_peekEmpty();
    testQueue.test_dequeueEmpty();
    testQueue.test_enqueueFull();

    testQueue.test_isEmpty();
    testQueue.test_isFull();
    testQueue.test_size();

    return 0;
}


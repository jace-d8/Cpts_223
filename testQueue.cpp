//
// Created by Jace Dunn on 9/17/24.
//

#include "testQueue.h"
#include "queue.h"

/* Test ID: Empty queue check - EQC
Unit: queue::isEmpty ()
Description: test to determine if queue::isEmpty () returns 1 if a queue object
is empty.
Test steps:
1. Construct an empty queue object
2. Invoke queue::isEmpty ()
3. Conditionally evaluate the value returned by queue::isEmpty ()
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is still empty
Expected result: queue is empty; 1 is returned
Actual result: queue is empty; 1 is returned
Status: passed
*/
void testQueue::test_isEmpty()
{
	cout << "test_isEmpty" << endl;
	my_queue q;
	my_queue q2;
	q.enqueue(1);
	if (q.isEmpty())
	{
		cout<<"test failed"<<endl;
	}else
	{
		cout<<"test passed"<<endl;
	}
	if (q2.isEmpty())
	{
		cout<<"test passed"<<endl;
	}else
	{
		cout<<"test failed"<<endl;
	}

}

/* Test ID: Full queue check - FQC
Unit: queue::isFull ()
Description: test to determine if queue::isFull () returns 1 if a queue object
is full.
Test steps:
1. Construct an full queue object
2. Invoke queue::isFull ()
3. Conditionally evaluate the value returned by queue::isFull ()
Test data: size = 10
Precondition: queue object is full
Postcondition: queue object is still full
Expected result: queue is empty; 1 is returned
Actual result: queue is empty; 1 is returned
Status: passed
*/
void testQueue::test_isFull()
{
	cout << "test_isFull" << endl;
	my_queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.enqueue(10);
	if(q.isFull())
	{
		cout<<"test passed"<<endl;
	}else
	{
		cout<<"test failed"<<endl;
	}
	my_queue q2;
	if (q2.isFull())
	{
		cout<<"test failed"<<endl;
	}else
	{
		cout<<"test passed"<<endl;
	}
}

void testQueue::test_size()
{
	cout << "test_size" << endl;
	my_queue q;
	q.enqueue(1);
	if(q.size() == 1)
	{
		cout<<"test passed"<<endl;
	}else
	{
		cout<<"test failed"<<endl;
	}
	q.enqueue(2);
	if(q.size() == 2)
	{
		cout<<"test passed"<<endl;
	}else
	{
		cout<<"test failed"<<endl;
	}
}

void testQueue::test_enqueue()
{
	my_queue q;
	q.enqueue(1);

}
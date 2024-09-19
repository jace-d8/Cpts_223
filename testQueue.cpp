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
	if (q.isEmpty())
	{
		cout<<"test passed"<<endl;
	}else
	{
		cout<<"test failed"<<endl;
	}
	q.enqueue(1);
	if (q.isEmpty())
	{
		cout<<"test failed"<<endl;
	}else
	{
		cout<<"test passed"<<endl;
	}

}

/* Test ID: Full queue check - FQC
Unit: queue::isFull ()
Description: test to determine if queue::isFull () returns 1 if a queue object
is full.
Test steps:
1. Construct a full queue object
2. Invoke queue::isFull ()
3. Conditionally evaluate the value returned by queue::isFull ()
Test data: size = 10
Precondition: queue object is full
Postcondition: queue object is still full
Expected result: queue is full; 1 is returned
Actual result: queue is full; 1 is returned
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

/* Test ID: Size check - SC
Unit: queue::size ()
Description: test to determine if queue::size () returns 1 if a queue object size == 1.
Test steps:
1. Construct an queue of size 1
2. Invoke queue::size ()
3. Conditionally evaluate the value returned by queue::size ()
Test data: size = 1
Precondition: queue object size is 1
Postcondition: queue object size is still 1
Expected result: queue size is 1; 1 is returned
Actual result: queue size is 0; 0 is returned
Status: failed
*/
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
}

/* Test ID: dequeue check - DC
Unit: queue::dequeue ()
Description: test to determine if queue::dequeue decreases size by 1 after execution
Test steps:
1. Construct an queue of size 3
2. Invoke queue::dequeue ()
3. Conditionally evaluate the value returned by queue::dequeue ()
Test data: size = 3
Precondition: queue object size is 3
Postcondition: queue object size is 2
Expected result: queue size is 2; 2 is returned
Actual result: queue size is 2; 2 is returned
Status: passed
*/
void testQueue::test_dequeue()
{
	cout << "test_dequeue" << endl;
	my_queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.dequeue();
	if(q.size() == 2)
	{
		cout<<"test passed"<<endl;
	}else
	{
		cout<<"test failed"<<endl;
	}

}

/* Test ID: Size check - SC
Unit: queue::size ()
Description: test to determine if queue::size () returns 1 if a queue object size == 1.
Test steps:
1. Construct an queue of size 1
2. Invoke queue::size ()
3. Conditionally evaluate the value returned by queue::size ()
Test data: size = 1
Precondition: queue object size is 1
Postcondition: queue object size is still 1
Expected result: queue size is 1; 1 is returned
Actual result: queue size is 0; 0 is returned
Status: failed
*/
void testQueue::test_peek()
{
	cout << "test_peek" << endl;
	my_queue q;
	q.enqueue(1029384756);
	if(q.peek() == 1029384756)
	{
		cout<<"test passed"<<endl;
	}else
	{
		cout<<"test failed"<<endl;
	}
}

/* Test ID: Size check - SC
Unit: queue::size ()
Description: test to determine if queue::size () returns 1 if a queue object size == 1.
Test steps:
1. Construct an queue of size 1
2. Invoke queue::size ()
3. Conditionally evaluate the value returned by queue::size ()
Test data: size = 1
Precondition: queue object size is 1
Postcondition: queue object size is still 1
Expected result: queue size is 1; 1 is returned
Actual result: queue size is 0; 0 is returned
Status: failed
*/
void testQueue::test_enqueue()
{
	cout << "test_enqueue" << endl;
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

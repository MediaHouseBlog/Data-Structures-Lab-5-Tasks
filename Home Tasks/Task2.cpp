#include <iostream>
using namespace std;

#define MAX_SIZE 5 

class Queue{
private:
	int front, rear;
	int arr[MAX_SIZE];
	
public:
	Queue(){
		front = -1;
		rear = -1;
	}
	bool isFull(){
		return rear == MAX_SIZE - 1;
	}
	bool isEmpty(){
		return front == -1 || front > rear;
	}
	void enqueue(int value){
		if(isFull()){
			cout << "Queue is full, cannot enqueue " << value << endl;
			return;
		}
		if(front == -1) front = 0;
		arr[++rear] = value;
	}
	int dequeue(){
		if(isEmpty()){
			cout << "Queue is empty, cannot dequeue" << endl;
			return -1;
		}
		return arr[front++];
	}
};

int main(){
	Queue q1;
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.enqueue(50);
    
	cout << q1.dequeue() << endl;
	cout << q1.dequeue() << endl;
	cout << q1.dequeue() << endl;
    
	q1.enqueue(60); // This will output "Queue is full"
	q1.enqueue(70); // This will output "Queue is full"
    
	cout << q1.dequeue() << endl;
	cout << q1.dequeue() << endl;
	cout << q1.dequeue() << endl; // Empty error
	cout << q1.dequeue() << endl; // Empty error
	cout << q1.dequeue() << endl; // Empty error
	cout << q1.dequeue() << endl; // Empty error
	
	return 0;
}
/*
  TASK 2(c):
	In a linear queue, the 'rear' pointer only moves forward. When it reaches the end of the array 
	(MAX_SIZE - 1), it reports the queue as "full", completely ignoring the empty spaces left at the 
	front by previous dequeues. A Circular Queue solves this by using the modulo operator (%) to 
	wrap the rear pointer back to the beginning of the array, reusing the freed space.
*/
#include <iostream>
using namespace std;

class Stack{
private:
	int cap;
	int* arr;
	int top = -1;
public:
	Stack(int c){
		cap = c;
		arr = new int[cap];
	}
	bool isFull(){
		return top == cap-1;
	}
	bool isEmpty(){
		return top == -1;
	}
	void push(int val){
		if(isFull()) return;
		arr[++top] = val;
	}
	int pop(){
		if(isEmpty()) return 0;
		return arr[top--];
	}
	int peek(){
		if(isEmpty())return 0;
		return arr[top];
	}
	~Stack(){
		delete[] arr;
	}
};

class Queue{
private:
	Stack stackIn;
	Stack stackOut;
	
public:
	Queue():stackIn(100), stackOut(100){	}
	void enqueue(int x){
		if(!stackIn.isFull()) stackIn.push(x);
	}
	int dequeue(){
		if(stackOut.isEmpty()){
			while(!stackIn.isEmpty()){
				stackOut.push(stackIn.pop());
			}
		}
		return stackOut.pop();
	}
};

int main(){
	Queue q;
	q.enqueue(1); 
	q.enqueue(2); 
	q.enqueue(3); 
	cout << "Output: " << q.dequeue() << ", ";
	q.enqueue(4);
	cout << q.dequeue() << ", ";
	cout << q.dequeue() << ", ";
	cout << q.dequeue() << endl;
	
	return 0;
}
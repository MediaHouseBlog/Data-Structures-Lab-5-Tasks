#include <iostream>
#include <string>
using namespace std;

class TicketCounter {
	private:
		int front;
		int rear;
		int N;
		string* arr; 

	public:
		TicketCounter(int size){
			N = size;
			arr = new string[N];
			front = -1;
			rear = -1;
		}
		
		bool isEmpty(){
			if(front == -1) return true;
			else return false;
		}
		
		bool isFull(){
			if((rear + 1) % N == front) return true;
			else return false;
		}
		
		void enqueue(string name){
			if(isFull()){
				cout << "-> Queue is full, cannot add " << name << endl;
				return;
			}
			if(isEmpty()){
				front = 0;
				rear = 0;
			} else {
				rear = (rear + 1) % N;
			}
			arr[rear] = name;
			cout << "-> " << name << " added to queue" << endl;
		}
		
		string dequeue(){
			if(isEmpty()){
				return ""; 
			}
			string servedCustomer = arr[front];
			if(front == rear){
				front = -1;
				rear = -1;
			} else {
				front = (front + 1) % N;
			}
			return servedCustomer;
		}
		
		void displayQueue(){
			if(isEmpty()){
				cout << "-> Queue is empty" << endl;
				return;
			}
			cout << "-> ";
			int i = front;
			while(i != rear){
				cout << arr[i] << ", ";
				i = (i + 1) % N;
			}
			cout << arr[rear] << endl;
		}
		
		~TicketCounter(){
			delete[] arr;
		}
};

int main(){
	int n;
	cout << "Enter N (Max customers): ";
	cin >> n;
	
	TicketCounter tc(n);
	int choice;
	string name;
	
	while(true){
		cout << "\nMenu:\n1. Add Customer\n2. Serve Customer\n3. View Queue\n4. Exit\nChoice: ";
		cin >> choice;
		
		if(choice == 1){
			cout << "Add Customer: ";
			cin >> name;
			tc.enqueue(name);
		}
		else if(choice == 2){
			cout << "Serve Customer" << endl;
			string served = tc.dequeue();
			if(served != ""){
				cout << "-> Serving " << served << endl;
			}
		}
		else if(choice == 3){
			cout << "View Queue" << endl;
			tc.displayQueue();
		}
		else if(choice == 4){
			break;
		}
		else{
			cout << "Invalid choice!" << endl;
		}
	}
	
	return 0;
}
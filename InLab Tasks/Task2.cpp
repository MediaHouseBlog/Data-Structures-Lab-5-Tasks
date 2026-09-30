#include <iostream>
#include <string>
using namespace std;

struct Node{
	string url;
	Node* next;
	
	Node(string val){
		url = val;
		next = nullptr;
	}
};

class BrowserHistory{
	private:
		Node* top;
		
	public:
		BrowserHistory(){
			top = nullptr;
		}
		
		bool isEmpty(){
			if(top == nullptr) return true;
			else return false;
		}
		
		void visit(string val){
			Node* n = new Node(val);
			if(top == nullptr){
				top = n;
				cout << "Now at: " << val << endl;
				return;
			}
			n->next = top;
			top = n;
			cout << "Now at: " << val << endl;
		}
		
		void goBack(){
			if(isEmpty() || top->next == nullptr){
				cout << "No previous page in history" << endl;
				return;
			}
			Node* temp = top;
			top = top->next;
			delete temp;
			
			cout << "Back to: " << top->url << endl;
		}
		
		string currentPage(){
			if(isEmpty()){
				cout << "History is empty" << endl;
				return "";
			}
			return top->url;
		}
		
		~BrowserHistory(){
			while(!isEmpty()){
				Node* temp = top;
				top = top->next;
				delete temp;
			}
		}
};

int main(){
	BrowserHistory history;
	
	history.visit("google.com");
	history.visit("github.com");
	history.visit("docs.com");
	
	history.goBack();
	history.goBack();
	history.goBack();
	
	return 0;
}
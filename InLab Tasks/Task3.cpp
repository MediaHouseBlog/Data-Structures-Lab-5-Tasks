#include <iostream>
#include <string>
using namespace std;

struct Node{
	char data;
	Node* next;
	
	Node(char val){
		data = val;
		next = nullptr;
	}
};

class CharStack{
	private:
		Node* top;
		
	public:
		CharStack(){
			top = nullptr;
		}
		bool isEmpty(){
			if(top == nullptr) return true;
			else return false;
		}
		void push(char val){
			Node* n = new Node(val);
			if(top == nullptr){
				top = n;
				return;
			}
			n->next = top;
			top = n;
		}
		char pop(){
			if(isEmpty()){
				return '\0';
			}
			Node* temp = top;
			char val = top->data;
			top = top->next;
			delete temp;
			return val;
		}
		char peek(){
			if(isEmpty()){
				return '\0';
			}
			return top->data;
		}
		~CharStack(){
			while(!isEmpty()){
				pop();
			}
		}
};

bool isBalanced(string exp){
	CharStack s;
	for(int i = 0; i < exp.length(); i++){
		if(exp[i] == '('){
			s.push('(');
		} else if(exp[i] == ')'){
			if(s.isEmpty()) return false;
			s.pop();
		}
	}
	return s.isEmpty();
}

int precedence(char op){
	if(op == '^') return 3;
	else if(op == '*' || op == '/') return 2;
	else if(op == '+' || op == '-') return 1;
	else return -1;
}

string infixToPostfix(string exp){
	CharStack s;
	string result = "";
	
	for(int i = 0; i < exp.length(); i++){
		char c = exp[i];
		
		// If operand, append directly to result
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
			result += c;
		}
		else if(c == '('){
			s.push(c);
		}
		else if(c == ')'){
			while(!s.isEmpty() && s.peek() != '('){
				result += s.pop();
			}
			s.pop(); 
		}
		else{
			while(!s.isEmpty() && s.peek() != '('){
				int precStack = precedence(s.peek());
				int precCurrent = precedence(c);
				
				// Left-to-right operators
				if(c != '^' && precStack >= precCurrent){
					result += s.pop();
				}
				// Right-to-left operator (^)
				else if(c == '^' && precStack > precCurrent){
					result += s.pop();
				}
				else{
					break;
				}
			}
			s.push(c);
		}
	}
	
	while(!s.isEmpty()){
		result += s.pop();
	}
	
	return result;
}

void processExpression(string exp){
	cout << "Input:  " << exp << endl;
	if(!isBalanced(exp)){
		cout << "Output: Invalid Expression\n" << endl;
	} else {
		cout << "Output: " << infixToPostfix(exp) << "\n" << endl;
	}
}

int main(){
	processExpression("A+B*C");
	processExpression("(A+B)*(C-D)");
	processExpression("A+B*(C^D-E)");
	processExpression("A+B*(C-D"); 
	
	return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int cap;
    int* arr;
    int top = -1;
public:
    Stack(int c) {
        cap = c;
        arr = new int[cap];
    }
    bool isFull() { return top == cap - 1; }
    bool isEmpty() { return top == -1; }
    void push(int val) {
        if (isFull()) return;
        arr[++top] = val;
    }
    int pop() {
        if (isEmpty()) return 0;
        return arr[top--];
    }
    int peek() {
        if (isEmpty()) return 0;
        return arr[top];
    }
    ~Stack() { delete[] arr; }
};

void evalPost(string post) {
    cout << "Input:  " << post << "\n";
    Stack st(100);
    int len = post.length();
    
    for (int i = 0; i < len; i++) {
        char c = post[i];
        
        if (c >= '0' && c <= '9') {
            st.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (st.isEmpty()) {
                cout << "Output: Error: Malformed expression\n\n";
                return;
            }
            int rightOp = st.pop();
            
            if (st.isEmpty()) {
                cout << "Output: Error: Malformed expression\n\n";
                return;
            }
            int leftOp = st.pop();
            
            int res = 0;
            
            if (c == '*')      res = leftOp * rightOp;
            else if (c == '/') res = leftOp / rightOp;
            else if (c == '+') res = leftOp + rightOp;
            else if (c == '-') res = leftOp - rightOp;
            
            st.push(res);
        }
    }
    
    if (st.isEmpty()) {
        cout << "Output: Error: Malformed expression\n\n";
        return;
    }
    
    int fRes = st.pop();
    
    if (st.isEmpty()) {
        cout << "Output: " << fRes << "\n\n";
    } else {
        cout << "Output: Error: Malformed expression\n\n";
    }
}

int main() {
    evalPost("23*54*+");
    evalPost("62/");
    evalPost("9+");
    
    return 0;
}
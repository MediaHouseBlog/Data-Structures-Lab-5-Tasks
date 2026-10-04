#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char* cArr;
    int cap;
    int top;
public:
    Stack(int c) {
        cap = c;
        cArr = new char[c];
        top = -1;
    }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == cap - 1; }
    void push(char c) {
        if (isFull()) return;
        cArr[++top] = c;
    }
    char pop() {
        if (!isEmpty()) return cArr[top--];
        return -1;
    }
    char peek() {
        if (!isEmpty()) return cArr[top];
        return -1;
    }
    ~Stack() { delete[] cArr; }
};

bool isBalanced(string expr) {
    Stack st(expr.length());
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (st.isEmpty()) return false;
            
            char top = st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.isEmpty();
}

void checkExpression(string expr) {
    cout << "Input:  " << expr << "\n";
    if (isBalanced(expr)) {
        cout << "Output: Balanced\n";
    } else {
        cout << "Output: Not Balanced\n";
    }
    cout << endl;
}

int main() {
    checkExpression("{A+(B*C)-[D/E]}");
    checkExpression("{A+(B*C)-[D/E]");
    checkExpression("(A+B]");
    
    return 0;
}
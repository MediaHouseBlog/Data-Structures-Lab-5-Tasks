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

bool isOperator(char c) {
    return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
}

int getPrecedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string reverseString(string t) {
    string r;
    int len = t.length();
    r.resize(len);
    for (int i = 0; i < len; i++) {
        r[i] = t[len - i - 1];
        if (r[i] == '(') r[i] = ')';
        else if (r[i] == ')') r[i] = '(';
    }
    return r;
}

bool isBalanced(string expr) {
    Stack st(expr.length());
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
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

string infixToPrefix(string t) {
    t = reverseString(t);
    Stack st(200);
    string prefix;
    for (int i = 0; i < t.length(); i++) {
        char c = t[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            prefix += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                prefix += st.pop();
            }
            if (!st.isEmpty() && st.peek() == '(') st.pop();
        } else if (isOperator(c)) {
            while (!st.isEmpty() && st.peek() != '(' &&
                   ((c == '^' && getPrecedence(st.peek()) >= getPrecedence(c)) ||
                    (c != '^' && getPrecedence(st.peek()) > getPrecedence(c)))) {
                prefix += st.pop();
            }
            st.push(c);
        }
    }
    while (!st.isEmpty()) {
        prefix += st.pop();
    }
    return reverseString(prefix);
}

void testConversion(string expr) {
    cout << "Input:  " << expr << "\n";
    if (isBalanced(expr)) {
        cout << "Output: " << infixToPrefix(expr) << "\n\n";
    } else {
        cout << "Output: Invalid (Unbalanced)\n\n";
    }
}

int main() {
    testConversion("A+B*C");
    testConversion("(A+B)*(C-D)");
    testConversion("A+B*(C^D-E)");
    return 0;
}

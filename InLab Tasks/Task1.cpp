#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
private:
    string tasks[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(string task) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }

        tasks[++top] = task;
        cout << "\"" << task << "\" pushed into stack" << endl;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return "";
        }

        return tasks[top--];
    }

    string peek() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return "";
        }

        return tasks[top];
    }

    // Task (a)
    void display() {
        if (isEmpty()) {
            cout << "No pending tasks." << endl;
            return;
        }

        cout << "Pending tasks (top to bottom):" << endl;

        int count = 1;

        for (int i = top; i >= 0; i--) {
            cout << count << ". " << tasks[i] << endl;
            count++;
        }
    }

    // Task (b)
    void undoLastTask() {
        if (isEmpty()) {
            cout << "No task to remove." << endl;
            return;
        }

        string task = pop();

        cout << "Removed: <" << task << ">" << endl;
    }

    // Task (c)
    bool search(string task) {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return false;
        }

        int above = 0;

        // Start from top because top is the most recent task
        for (int i = top; i >= 0; i--) {

            if (tasks[i] == task) {
                cout << "Task found: " << task << endl;
                cout << "Tasks above it: " << above << endl;
                return true;
            }

            above++;
        }

        cout << "Task was not found." << endl;
        return false;
    }

    void addTask(string task) {
        push(task);
    }
};

int main() {
    Stack s;

    int choice = -1;

    while (choice != 5) {

        cout << "\n1. Add Task" << endl;
        cout << "2. Remove Last Task" << endl;
        cout << "3. View All Tasks" << endl;
        cout << "4. Search Task" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {

            case 1: {
                string task;

                cout << "Enter task: ";
                getline(cin, task);

                s.addTask(task);
                break;
            }

            case 2: {
                s.undoLastTask();
                break;
            }

            case 3: {
                s.display();
                break;
            }

            case 4: {
                string task;

                cout << "Enter task to search: ";
                getline(cin, task);

                s.search(task);
                break;
            }

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid input." << endl;
        }
    }

    return 0;
}

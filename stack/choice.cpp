#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int data[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (!isFull()) {
            top++;
            data[top] = value;
            cout << "Element " << value << " pushed onto the stack." << endl;
        } else {
            cout << "Stack Overflow. Cannot perform the push operation." << endl;
        }
    }

    void pop() {
        if (!isEmpty()) {
            int poppedValue = data[top];
            top--;
            cout << "Element " << poppedValue << " popped from the stack." << endl;
        } else {
            cout << "Stack Underflow. Cannot perform the pop operation." << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Elements in the stack:";
            for (int i = 0; i <= top; i++) {
                cout << " " << data[i];
            }
            cout << endl;
        }
    }
}; 

int main() {
    Stack myStack;
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int element;
                cout << "Enter the element to push onto the stack: ";
                cin >> element;
                myStack.push(element);
                break;
            case 2:
                myStack.pop();
                break;
            case 3:
                myStack.display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please choose again." << endl;
        }
    }

    return 0;
}

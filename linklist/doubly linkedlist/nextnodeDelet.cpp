#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;
    node(int data) {
        this->data = data;
        next = NULL; 
        prev = NULL; 
    }
};

class linkedlist {
public:
    node* head = NULL; 
    node* tail = NULL; 
    int count = 0;

    void insertAtEnd(int data) {
        node* newNode = new node(data);
        node* temp = head;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            head->prev = NULL;
            count++;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->prev = newNode->prev;
            count++;
        }
    }

    void display() {
        node* temp = head;
        cout << "Your linked list is: ";

        for (int i = 0; i < count; i++) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteNextNode(int n) {
        node* temp = head;
        if (head->next == NULL) {
            cout << "Does not have the next element" << endl;
            return;
        }

        while (temp != NULL) {
            if (temp->next->data == n) {
                temp->next->next = temp->next->next->next;
                count--;
                break;
            }
            temp = temp->next;
        }
        while (temp->next != NULL) {

            if (temp->data == n) {
                cout << "No next element" << endl;
            }
            temp = temp->next;
        }
    }
};

int main() {
    linkedlist obj;
    cout << "Enter the number of nodes you want to insert: ";
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cout << "Enter your " << i << "st node element: ";
        int data;
        cin >> data;
        obj.insertAtEnd(data);
    }

    obj.display();

    int element;
    cout << "Enter the element to delete its next node: ";
    cin >> element;
    obj.deleteNextNode(element);

    cout << "After deleting the next element " << element << ":" << endl;
    obj.display();

    return 0;
}

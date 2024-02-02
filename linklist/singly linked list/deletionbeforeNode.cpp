//create a linked list for n numbber of node and take
// input from user and delete a node before the 
//value 45;
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
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    void display() {
        node* temp = head;
        cout << "Your linked list is: ";

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    void deleteprevNode(int n) {
        node* temp = head;

        while (temp != NULL && temp->next != NULL) {
            if (temp->next->data == n) {
                if (temp->next == tail) {
                    tail = temp;
                    delete temp->next;
                    temp->next = NULL;
                }
                else {
                    node* toDelete = temp->next;
                    temp->next = temp->next->next;
                    temp->next->prev = temp;
                    delete toDelete;
                }
                count--;
                break;
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
    cout << "Enter the element to delete its previous node: ";
    cin >> element;
    obj.deleteprevNode(element);

    cout << "After deleting the previous element " << element << ":" << endl;
    obj.display();

    return 0;
}
//creat a linked list for n number of node 
//and display even node and odd node saperatly 

//create a circular linked list for n input and display and data alternatively
//


//create a single linedlist in reverse order 
//create a double linked list for n number of nodes and check whether node is palandrom or not
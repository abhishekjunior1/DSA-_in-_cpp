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
            tail->prev = temp;
            temp=temp->next;
            count++;
        }
        tail->next=NULL;
        cout<<tail->data<<" ";

    }

    void display() {
        node* temp = tail;
        cout << "Your linked list is: ";
        while(temp!=NULL){
            cout << temp->data << " -> ";
            temp = temp->prev;

        }
        // for (int i = 0; i < count; i++) {
          
        // }
        cout << "NULL" << endl;
    }
    
  // void rev()
  // {
  //   node *temp=tail;
  //   while(temp->prev!=NULL)
  //   {
  //     cout<<temp->data<<" ";
  //     temp=temp->prev;

    

  
   
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
    // obj.rev();
    return 0;
}

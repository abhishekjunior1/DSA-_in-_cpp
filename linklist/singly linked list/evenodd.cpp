
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
    void odd()
    {
      node *temp=head;
      while(temp!=NULL)
      {
        if(temp->data %2!=0)
        {
          cout<<temp->data<<"-> "<<" ";
        }
        
        temp=temp->next;
      }
    }
    void even()
    {
      node *temp=head;
      while(temp!=NULL)
      {
        if(temp->data %2==0)
        {
          cout<<temp->data<<"->"<<" ";
        }
        
        temp=temp->next;
      }
      
    }

    void pal()
    {
      while(head!=tail && tail!=head->prev)
      {
        if(head->data!=tail->data)
        {
          cout<<"not a pallindrome ";
          return;
        }
        else{
          head=head->next;
          tail=tail->prev;
          cout<<"it is palendrom: ";
        }
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
    cout<<"Odd node: ";
    obj.odd();
    cout<<endl;
    cout<<"even node : ";
    obj.even();
    cout<<endl;
    obj.pal();
    cout<<endl;
    // obj.rev();


    return 0;
}
//creat a linked list for n number of node 
//and display even node and odd node saperatly 


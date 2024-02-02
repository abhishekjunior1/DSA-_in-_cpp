
#include<iostream>
using namespace std;

class node {
public:
    string  data;
    node* next;
    node* prev;
    node(string  data) {
        this->data = data;
        next = NULL; 
        prev = NULL; 
    }
};

class linkedlist 
{
public:
    node* head = NULL; 
    node* tail = NULL; 
    int count = 0;

    void insertAtEnd(string data) {
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

    void display()
     {
        node* temp = head;
        cout << "Your linked list is: ";

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }


   void alter()
   {
    node *temp=head;
    cout<<"After Deleting Alternate node is :"<<" ";
    for(int i=1;i<=count;i++)
    {
      if(i%2==0)
      {
        temp=temp->next;
      }
      else{
        cout<<temp->data<<"->"<<" ";
        temp=temp->next;
      }
   }
   cout<<"NULL";
   }
       
  
};

int main() {
    linkedlist obj;
    cout << "Enter the number of nodes you want to insert: ";
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cout << "Enter your " << i << "st node element: ";
        string  data;
        cin >> data;
        
        
        obj.insertAtEnd(data);
    }

    // obj.display();
    obj.alter();

    return 0;
}

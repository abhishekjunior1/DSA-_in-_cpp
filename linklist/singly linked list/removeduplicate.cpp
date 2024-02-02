#include<iostream>
#include<cmath>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) 
    {
      this->data=data;
      next=NULL;
    }
};

class linkedlist {
public:
    node* head = nullptr;
    node* tail = nullptr;
    int count =0;
    void insert(int data) {
        node* newnode = new node(data);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
            count++;
        }
        else {
            tail->next = newnode;
            tail = newnode;
            count++;
        }
    }

    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void duplicate()
    {
      
      node * temp1=head;
        for(int i=0;i<count;i++)
        {
          int flag=1;
          node * temp2 =temp1->next;
          for(int j=i+1;j<count;j++)
          { 
            if(temp1->data==temp2->data)
            {
              flag++;
              // break;
            }
            temp2=temp2->next;
          }
          if(flag==1)
          cout<<temp1->data<<" ";
          temp1=temp1->next;
        }
    }
};

int main() {
    linkedlist obj;
    cout<<"enter value of n: ";
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        obj.insert(data);
    }

    obj.display();
    obj.duplicate();
}

#include<iostream>
#include<queue>
using namespace std;
struct node{
    public:
    int data;
    struct node * next;
};
struct node * front=NULL;
struct node * rear=NULL;
void  enqueue()
    {
        int x;
        cout<<"Enter the data: ";
        cin>>x;
        
        if(rear==NULL)
        {
        struct node * newnode=new node();
        newnode ->data=x;
        newnode->next=NULL;
        front=rear=newnode;
        }
        else{
            struct node * newnode=new node();
            newnode ->data=x;
            newnode->next=NULL;
            rear->next=newnode;
            rear=newnode;

        }
        
    }

    void dequeue()
    {
        struct node * temp=front;
        if(front ==NULL)
        {
            cout<<"Underflow";
            return;
        }
        else if(temp->next!=NULL)
        {
            temp=temp->next;
            cout<<front->data;
            free(front);
            front=temp;
        }
        else{
            cout<<"deleted item:"<<front->data;
            free(front);
            front=rear=NULL;
        }

    }
    void display()
    {
        if(front ==NULL)
        {
            cout<<"Underflow";
            return;
        }
        struct node * temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
int main()
{
    
    while(true)
    {
        cout<<"Enter the choice: ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                
                enqueue();
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                cout << "Exiting the program." << endl;
                return 0;
            }
            default:
            {
                cout<<"Invalid choice ";
                break;
            }

        }
    }


}

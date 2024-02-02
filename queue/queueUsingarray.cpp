#include<iostream>
#include<queue>
using namespace std;
#define max 10
class queue1{
    int *arr;
    int front;
    int rear;
    public:
    queue1()
    {
        arr=new int [max];
        front=-1;
        rear=-1;
    }
    void  enqueue(int data)
    {
        
        if(rear==max-1)   
        {
        cout<<"overflow";
        return;
        }
        else if(front==-1 && rear==-1){
            front =rear=0;
            arr[rear]=data;
        }
        else{
            rear++;
            arr[rear]=data;
        }

    }
    void dequeue()
    {
        if(front==-1){
            cout<<"underflow";
            return;
        }
        else if(front==rear)
        {
            front=rear=-1;
        }
        else{
            int val=arr[front];
            front++;
            cout<<"deleted item is"<<val<<endl;
        }
    }

    void display()
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i];
        }
        cout<<endl;
    }


};
int main()
{
    queue1 obj;
    while(true)
    {
        cout<<"Enter the choice: ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter data: ";
                int data;
                cin>>data;
                obj.enqueue(data);
                break;
            }
            case 2:
            {
                obj.dequeue();
                break;
            }
            case 3:
            {
                obj.display();
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
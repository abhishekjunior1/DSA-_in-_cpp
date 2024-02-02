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
    void  enqueuefront(int data)
    {
        
        if((front==0 && rear==max-1) && (front==rear+1)){
            cout<<"queue is full ";
            return;
        }
        
        else if(front==-1 && rear==-1){
            front =rear=0;
            arr[front]=data;
        }
        else if(front==0){
            front=max-1;
            arr[front]=data;
        }
        else{
            front--;
            arr[front]=data;
        }

    }
    void  enqueuerear(int data)
    {
        
        if((front==0 && rear==max-1) && (front==rear+1)){
            cout<<"queue is full ";
            return;
        }
        
        else if(front==-1 && rear==-1){
            front =rear=0;
            arr[rear]=data;
        }
        else if(rear=max-1){
            rear=0;
            arr[rear]=data;
        }
        else{
            rear++;
            arr[rear]=data;
        }

    }



    void dequeuefront()
    {
        if(front==-1 && rear==-1){
            cout<<"empty Queue";
            return;
        }
        else if(front==rear)
        {
            front=rear=-1;
        }
        else if(front==max-1)
        {
            cout<<arr[front];
            front=0;
        }
        else{
            cout<<arr[front];
            front++;
        }
    }


    void dequeuerear()
    {
        if(front==-1 && rear==-1){
            cout<<"empty Queue";
            return;
        }
        else if(front==rear)
        {
            front=rear=-1;
        }
        else if(rear==0)
        {
            cout<<arr[rear];
            rear=max-1;
        }
        else{
            cout<<arr[rear];
            rear--;
        }
    }


    void display()
    {
        int i=front;
        while(i!=rear)
        {
            cout<<arr[i]<<" ";
            i=(i+1)%max;
        }
        cout<<arr[rear]<<" ";
    }


};
int main()
{
    queue1 obj;
    obj.enqueuefront(2);
    obj.enqueuefront(5);
    obj.enqueuerear(12);
    obj.enqueuerear(13);
    obj.enqueuefront(14);
    obj.enqueuefront(15);
    obj.display();


}
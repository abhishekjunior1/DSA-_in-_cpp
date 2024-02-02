#include<iostream>
#include<limits.h>
using namespace std;


class Stack{
    public:
    int capacity;
    int *arr;
    int top;
    Stack(int size)
    {
        this->capacity=size;
        arr=new int [size];
        top=-1;
    }
    void push(int data)
    {
        if(top==capacity-1)
        {
            cout<<"overflow\n";
            return;
        }
        else{
            top++;
            arr[top]=data;
        }
    }
    void pop()
    {
        if(top==-1){
            cout<<"Underflow\n";
            return;
        }
        else
        {
            top--;
        }
    }
    int peek()
    {
        if(top==-1)
        {
            cout<<"underflow\n";
            return false ;
        }
        else
        return arr[top];
    }
    bool isempty()
    {
        return(top==-1);
        
    }
    bool isfull()
    {
        return top==capacity-1;
    }
};
int main(){
    Stack *obj=new Stack(5);
    for(int i=0;i<5;i++)
    {
        int data;
        cin>>data;
        obj->push(data);
    }
    for(int i=0;i<5;i++)
    {
        cout<<obj->peek()<<" ";
        obj->pop();

    }
    cout<<"\n";
    cout<<obj->peek();

return 0;
}
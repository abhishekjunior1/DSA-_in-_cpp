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
            return INT_MIN ;
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
    obj->push(10);
    obj->push(11);
    obj->push(12);
    obj->push(13);
    cout<<obj->peek()<<endl;
    obj->push(20);
    obj->push(100);
    cout<<obj->peek()<<endl;
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    cout<<obj->peek()<<endl;
    cout<<obj->isempty()<<endl;
    cout<<obj->isfull();

return 0;
}
#include<iostream>
using namespace std;
struct node{
  int data ;
  node* next;
};
struct node *head,*temp;//they are like int head and temp but pointer
int main()
{
  int choice;
  head=NULL;//default value of head is null 
  while(choice)
  {
    node *newnode=new node(); //it will point newly created node
    cout<<"Enter the data: ";
    cin>>newnode->data;
    newnode->next=NULL;//default is null
    if(head==NULL) 
    {
      head = newnode;
      temp = newnode;
    }
    else{
      temp->next=newnode;
      temp=newnode;
    }
      cout<<"do you  want to continue :(0,1):";
      cin>>choice;
  }
  temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<"->";
    temp=temp->next;
  }

  return 0;
}
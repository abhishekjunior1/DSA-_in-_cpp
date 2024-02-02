#include<iostream>
using namespace std;
struct node{
  int data;
  struct node *prev;
  struct node *next;
 
};
struct node *temp, * head=NULL;

void insertathead(int val){
  struct  node * temp= new node();
  temp->data=val;
  if(head==NULL)
  {
    head=temp;
    head->next=nullptr;
    head->prev=nullptr;
  }
  else{
     temp->next=head;
     head=temp;
     
  }


}
int main()
{
  int choice ;
  cout<<"enter the choice :";
  cin>>choice;
  while (choice)
{


  struct  node * newnode= new node();
  cout<<"enter the data: ";
  cin>>newnode->data;
  if (head==NULL)
  {
    head=temp=newnode;
    newnode->next=NULL;
    newnode->prev=NULL;

  }
  else{
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
    temp=newnode;
  }
  cout<<"enter the choice : ";
  cin>>choice;
}
cout<<endl;
temp=head;
cout<<"header linkedlist: ";
while(temp!=NULL)
{
  cout<<temp->data<<" ";
  temp=temp->next;

}
insertathead(11);
node * avail=NULL;
if (avail==NULL)
{
  cout<<"memory overflaw";
 
}


return 0;
}
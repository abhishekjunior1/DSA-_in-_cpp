#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node *next;
  node(int data)
  {
    this->data=data;
    next=NULL;
  }

};


class linkedlist{
public:
node *head=NULL;
node *tail=NULL;
int count=0;
void inseratend(int data)
{
  node *newnode=new node(data);
  node *temp=head;
  if(head==NULL){
   head=newnode;
   tail=newnode;
   count++;
  }
  else
  {
    tail->next=newnode;
    tail=newnode;
    count++;

  }
}
void display()
{
  node *temp=head;
  cout<<"your linked list is ";
  
  for(int i=0;i<count;i++)
  {
    cout<<temp->data<<"->"<<" ";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}
void delet()
{
  node *temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<"->"<<" ";
    temp=temp->next->next;
  }
  cout<<"NULL"<<endl;
}


};
int main()
{
  linkedlist obj;
  // obj.inseratend(10);
  // obj.inseratend(11);
  // obj.inseratend(12);
  // obj.inseratend(13);
  // obj.inseratend(14);
  // obj.inseratend(2);
  cout<<"enter no of data u want to insert: ";
  int m;
  cin>>m;
  for(int i=1;i<=m;i++)
  {
    cout<<"enter your "<<i<<"st element: "<<endl;
    int data;
    cin>>data;
    obj.inseratend(data);
  }
   obj.display();
   obj.delet();
   cout<<"after deelting: "<<endl;
   obj.display();
  


}
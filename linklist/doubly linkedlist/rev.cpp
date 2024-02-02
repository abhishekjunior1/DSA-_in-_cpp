#include<iostream>
#include<algorithm>
using namespace std;

class node{
  public:
  int data;
  node *next;
  node *prev;
  node (int data)
  {
    this->data=data;
    next=NULL;
    prev=NULL;
  }
};

class linkedlist{
public:
node *head=NULL;
node *tail=NULL;
node *a;
void atend(int data)
{
  node *newnode= new node(data);
  
  if(head==NULL)
  {
    head=newnode;
    tail=newnode;
    head->prev=NULL;
    
  }
  else
  {
      //  node *temp = tail;  
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;

  }
 
 
}

void display()
{
  node *temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<"->"<<" ";
    temp=temp->next;
  }
  cout<<endl; 
  
}

void rev()
{
  node *temp=tail;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ->"<<" ";
    temp=temp->prev;
  }
}
void count()
{

}
void dup()//1,2,2,4,2
{
  cout<<"removing duplicate: ";
   node *fix=head;
   node *temp=head->next;
   while(temp!=NULL){
    if(fix->data!=temp->data)
    {
      cout<<fix->data<<" "<<"->";
      fix=fix->next;
      temp=temp->next;
     }
    else{
      fix=fix->next;
      temp=temp->next;
      }
   }

}

 

};
int main()
{
 linkedlist ll;
 int n;
 cin>>n;
  for(int i=0;i<n;i++)
  {
    int data;
    cin>>data;
    ll.atend(data);
  }
  ll.display();
  // cout<<endl;
  ll.rev();
  cout<<endl;
  ll.dup();

  
  

}
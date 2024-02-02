#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data=data;
        left=right=nullptr;
    }
};
int k=-1;
node * create(int arr[])
{
    k++;
    if(k==6)
    return nullptr;
    node * root= new node(arr[k]);
    root->left=create(arr);
    root->right=create(arr);
    return root;
};
int main()
{
    int ar[6]={30,17,15,1,5,10};
    node * root=create(ar);
    cout<<root->data;
    

}
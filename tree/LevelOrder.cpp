#include<iostream>
using namespace std;
#include<queue>
#include<limits.h>
class node{
    public:
    int data;
    node * left,*right;
    node(int data)
    {
        this->data=data;
        left=right=nullptr;
    }
};
int i=-1;
node * create(int arr[])
{
     i++;
     if(arr[i]==-1)
     return nullptr;
     node * root= new  node (arr[i]);
     root->left=create(arr);
     root->right=create(arr);
     return root;

}
void levelOrder(node * root)//in one line 
{
    queue<node*>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty())
    {
        node * temp=q.front();
        q.pop();
        if(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            if(temp->left!=nullptr)
            q.push(temp->left);
            if(temp->right!=nullptr)
            q.push(temp->right);
        }
        else if(temp==nullptr);
        {
            q.push(NULL);
            if(q.empty())
            break;

        }
    }

}
void levelOrderNLine(node * root)//new line 
{
   
    queue<node *>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty())
    {
        node * temp=q.front();
        q.pop();
        if(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            if(temp->left!=nullptr)
            q.push(temp->left);
            if(temp->right!=nullptr)
            q.push(temp->right);
        }
        else if(temp==nullptr)
        {
            cout<<endl;
            if(q.empty())//end ke li check kr rehe hai 
            break;
            else 
            q.push(nullptr);//agr null milta hai tho just add null;
        }
    }

}
void searchMax(node* root) {
    if (!root)
        return;

    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int max = INT_MIN;
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            node* temp = q.front();
            q.pop();
            
            if (temp->data > max) {
                max = temp->data;
            }

            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
        }

        cout << max << " ";
    }
}



int main()
{
    int arr[]={1,2,-1,-1,3,-1,-1};
     node * root=create(arr);
     levelOrder(root);//------->use this method
//     //  cout<<"Aak naya linr "<<endl;  
//      levelOrderNLine(root);
//      cout<<"Printing Max in each node : "<<endl;
//      searchMax(root);


}
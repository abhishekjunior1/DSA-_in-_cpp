#include <iostream>
using namespace std;
#include<stack>
stack<int>st;
stack<int>stt;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        left = right = NULL;
    }
};
 node * Build_binarytree(node* root, int data) {
        if (root == NULL) {
            node *newnode = new node(data);
            return newnode;
        }

        if (data < root->data) {
            root->left = Build_binarytree(root->left, data);//recursive  left child  ke lia
        } else if (data >= root->data) {
            root->right = Build_binarytree(root->right, data);
        }

        return root;
    }
 void inorder(node * root)
{
    if(root==nullptr)
    return;
    inorder(root->left);
    st.push(root->data);
    inorder(root->right);
}
 void inorderr(node * root)
{
    if(root==nullptr)
    return;
    inorderr(root->left);
    stt.push(root->data);
    inorderr(root->right);
}

int  main() {
    int n;
    cout << "enter the value of n " << endl;
    cin >> n;

    node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = Build_binarytree(root, data);
    }
    // cout<<root->data;
    int m;
    cout<<"ENter the 2nd sixe ";
    cin>>m;
    node * root1=nullptr;
    for (int i = 0; i < m; i++) {
        int data;
        cin >> data;
        root1 = Build_binarytree(root1, data);
    }
    inorder(root);
    inorderr(root1);
    if(n!=m)
    cout<<"not equal";
    else
    {
        while(st.size()!=1)
        {
            if(st.top()==stt.top())
            {
                st.pop();
                stt.pop();
            }
            else
            {
                cout<<"not equal ";
                break;
            }
        }
    }
    if(st.top()==stt.top())
    cout<<"equal ";
}

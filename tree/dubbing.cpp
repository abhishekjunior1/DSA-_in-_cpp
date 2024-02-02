#include <iostream>
using namespace std;
#include<stack>
stack<int>st;

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
    

int  main() {
    int n;
    cout << "Enter the number of data you wish to enter: " << endl;
    cin >> n;

    node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = Build_binarytree(root, data);
    }
    cout<<root->data;

}

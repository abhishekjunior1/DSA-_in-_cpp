#include <iostream>
using namespace std;
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
    node * findmin(node * root)
    {
        node * temp=root;
        while(temp->left!=nullptr)
        {
            temp=temp->left;
        }
        return temp;

    }


 

    node* deletee(node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deletee(root->left, data);
    else if (data > root->data)
        root->right = deletee(root->right, data);
    else { // equal or found it
        if (root->left == NULL) {// 1 child 
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) { //1 child 
            node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        else//2 child  
        {
        node* temp = findmin(root->right);
        root->data = temp->data;
        root->right = deletee(root->right, temp->data);
        }
    }
    return root;
}
void inorderTraversal(node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
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
    
        cout << "Before Deletion : " << endl;
        inorderTraversal(root);

        root = deletee(root, 3);

        cout << "\nAfter Deletion : " << endl;
        inorderTraversal(root);
}

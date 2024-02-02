#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node *root=NULL;

    void preorder(Node *newnode) {//newnode=head
        if (newnode == NULL)
            return;
        cout << newnode->data << "->";
        preorder(newnode->left);
        preorder(newnode->right);
    }

    void postorder(Node *newnode) {
        if (newnode == NULL)
            return;
        postorder(newnode->left);
        postorder(newnode->right);
        cout << newnode->data << "->";
    }

    void inorder(Node *newnode) {
        if (newnode == NULL)
            return;
        inorder(newnode->left);
        cout << newnode->data << "->";
        inorder(newnode->right);
    }
};

int main() {
    BinaryTree tree;
    tree.root = new Node(20);
    tree.root->left = new Node(30);
    tree.root->right = new Node(40);
    tree.root->left->left = new Node(50);
    tree.root->right->right = new Node(60);


    cout << "Inorder traversal ";
    tree.inorder(tree.root);

    cout << "\nPreorder traversal ";
    tree.preorder(tree.root);

    cout << "\nPostorder traversal ";
    tree.postorder(tree.root);

    return 0;
}

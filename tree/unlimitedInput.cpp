#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

node* create() {
    int data;
    cin >> data;

    if (data == -1)
        return nullptr;

    node* root = new node(data);

    cout << "Enter left data: ";
    root->left = create();

    cout << "Enter right data: ";
    root->right = create();

    return root;
}

int main() {
    node* root = create();
    return 0;
}

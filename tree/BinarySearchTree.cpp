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

class Implementation {
public:
    node* Build_binarytree(node* root, int data) {
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

    void inorder(node* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(node* root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(node* root) {
        if (root == NULL) {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    node* search(node* root, int key) {
        if (root == NULL || root->data == key) {
            return root;
        }

        if (key < root->data) {
            return search(root->left, key);
        }
        if(key >= root->data)
          return search(root->right, key);
    }

    

    node* findlargest(node* root) {
        // if (root == NULL || root->right == NULL) {
        //     return root;
        // }
        // return findlargest(root->right);
        while(root->right!=nullptr)
        {
            root=root->right;
        }
        return root;
    }

    node* deletee(node* root, int data) {
        if (root == NULL) {
            cout << "Value not found" << endl;
            return root;
        }

        if (data < root->data) {
            root->left = deletee(root->left, data);
        } else if (data >= root->data) {
            root->right = deletee(root->right, data);
        } else {
            node* temp = root;
            if (root->left == NULL && root->right == NULL)
                root = NULL;
            else if (root->left != NULL)
                root = root->left;
            else
                root = root->right;

            free(temp);
        }
        return root;
    }

    int findlevel(node * root , int data,int level)
    {   
        if(root==NULL)
        return 0;
        if(root->data==data)
        return level;
        if(data<root->data)
        {
           return  findlevel(root->left,data,level+1);
           
        }
        else{
            return findlevel(root->right,data,level+1);

        }



    }
};

int main() {
    Implementation obj;
    int n;
    cout << "Enter the number of data you wish to enter: " << endl;
    cin >> n;

    node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = obj.Build_binarytree(root, data);
    }

    cout << "Preorder: ";
    obj.preorder(root);
    cout << endl;

    cout << "Postorder: ";
    obj.postorder(root);
    cout << endl;

    cout << "Inorder: ";
    obj.inorder(root);
    cout << endl;

    cout << "Enter the element you want to search: ";
    int searchKey;
    cin >> searchKey;

    node* searchResult = obj.search(root, searchKey);

    if (searchResult != NULL) {
        cout << "Element " << searchKey << " is found in the tree." << endl;
    } else {
        cout << "Element " << searchKey << " is not found in the tree." << endl;
    }

    // int data1;
    // cout << "Enter the element you want to delete: ";
    // cin >> data1;
    // root = obj.deletee(root, data1);

    // cout << "Inorder after deletion: ";//to check sach mi delete hua ke nhi..
    // obj.inorder(root);
    cout<<endl;


   cout<< obj.findlevel(root,3,0);

    return 0;
}

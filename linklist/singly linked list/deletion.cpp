#include<iostream>
using namespace std;

struct node {
  int data;
  node* next;
};

struct node *head = nullptr;
struct node *temp = nullptr;

int main() {
  int choice = 1; // Initialize choice to 1
  int count = 1; // Initialize count to 1
  int val;
  node* pos = nullptr; // Initialize pos to nullptr
  int flag = 0;

  while (choice) {
    node* newnode = new node();
    cout << "Enter the data: ";
    cin >> newnode->data;
    newnode->next = nullptr;
    if (head == nullptr) {
      head = newnode;
      temp = newnode;
    }
    else {
      temp->next = newnode;
      temp = newnode;
    }
    cout << "Do you want to continue (0,1): ";
    cin >> choice;
    count++; // Increment the count
  }

  temp = head;
  cout << "Linked List: ";
  while (temp != nullptr) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;

  cout << "Enter the value to search: ";
  cin >> val;

  temp = head;
  count = 1; // Reset count to 1 for the search loop
  while (temp != nullptr) {
    if (val == temp->data) {
      pos = temp;
      flag = 1; // Set flag to 1 when element is found
      break;    // Exit the loop when element is found
    }
    temp = temp->next;
    count++;
  }

  if (flag == 1) {
    cout << "Element found at node no: " << count << " Having address " << pos << endl;
  }
  else {
    cout << "Element not found." << endl;
  }

  return 0;
}

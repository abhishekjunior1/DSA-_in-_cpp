#include<iostream>
using namespace std;

class stack
{
public:
    int top = -1;

    int push(int arr[], int data, int size)
    {
        if (top == size - 1)
        {
            cout << "Overflow :" << endl;
            return -1;
        }
        else
        {
            top++;
            arr[top] = data;
            return 1; 
        }
    }

    void pop(int arr[], int &i, int temp[])
    {
        if (top == -1)
        {
            cout << "Underflow: ";
            return;
        }
        else
        {
            int a = arr[top];
            temp[i] = a;
            i++;
            top--;
        }
    }

   void display(int arr[], int n)
     {
        cout << "Printing data: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    cout << "Capacity: ";
    int size;
    cin >> size;

    stack obj;
    cout << "Enter the number of data you wish to enter: ";

    int arr[size];

    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        a = obj.push(arr, data, size);

    }

    if (a != -1) 
    {
        obj.display(arr, n);
        cout << endl;

        int temp[n];
        int i = 0;
        for(int j=0;j<n;j++)
        obj.pop(arr, i, temp);

        cout << "Popped element Printing: " << endl;
        obj.display(temp, n);
    }

    return 0;
}

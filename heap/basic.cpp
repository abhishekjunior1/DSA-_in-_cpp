#include <iostream>
using namespace std;
#include<algorithm>
#define max 100
class insert
{
public:
    int arr[max];
    int size = 0;//my arr will start from 1 position 
    void insertion(int data)
    {
        size++;

                                                            
        int i = size; //for insertion i is there
        arr[size] = data;
        while (i >1)
        {
            int parent =i/2;

            if(arr[parent]<arr[i]){
            swap(arr[parent],arr[i]);
            i= parent;
            }
          
        }
    }


    // void deletion()
    // {

    //     if (size == 0) {
    //     cout << "Heap is empty. Cannot delete." << endl;
    //     return;
    //      }
    //     arr[1]=arr[size];
    //     size--;
    //     int i=1;
    //     while(true)
    //     {
    //         int leftchild=2*i;
    //         int rightchild=2*i +1;
    //         if(leftchild <=size && arr[leftchild]>arr[i])
    //         {
    //             swap(arr[leftchild],arr[i]);
    //             i=leftchild;
    //         }
    //         else if(rightchild <=size && arr[rightchild]>arr[i])
    //         {
    //            swap(arr[rightchild],arr[i]);
    //             i=rightchild; 
    //         }
    //         else {
    //             break;
    //         }
    //     }
    // }


    void deletion()//0r
{
    if (size == 0) {
        cout << "Heap is empty. Cannot delete." << endl;
        return;
    }
    arr[1] = arr[size];
    size--;

    int i = 1;
    while (true) {
        int largest = i;  // Assume the current node is the largest
        int leftchild = 2 * i;
        int rightchild = 2 * i + 1;

        if (leftchild <= size && arr[leftchild] > arr[largest]) {
            largest = leftchild;
        }
        if (rightchild <= size && arr[rightchild] > arr[largest]) {
            largest = rightchild;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest; // Update the parent index
        } else {
            break;
        }
    }
}


    void display()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

int main()
{
    insert obj;
    obj.insertion(2);
    obj.insertion(3);
    obj.insertion(5);
    obj.insertion(10);
    obj.display();
    cout<<endl;
    obj.deletion();
    obj.display();
    cout<<endl;
    obj.deletion();
    obj.display();
    

    
}
#include<iostream>
using namespace std;

void printt(int [], int );
void merge(int [], int , int , int );
void mergesort(int [], int , int );

void printt(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int index = left;
    int temp[10];
    
    while(i <= mid && j <= right)
    {
        if(arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    
    while(i <= mid)
    {
        temp[index] = arr[i];
        index++;
        i++;
    }
    
    while(j <= right)
    {
        temp[index] = arr[j];
        index++;
        j++;
    }
    
    int p = left;
    while(p < index)
    {
        arr[p] = temp[p];
        p++;
    }
}

void mergesort(int arr[], int left, int right)
{
    // int mid;
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int s;
    cout<<"Enter the sixe of array plx: ";
    cin >> s;
    int arr[s];
    for(int i = 0; i < s; i++)
        cin >> arr[i];
    
    cout << "Original Array: ";
    printt(arr, s);
    
    mergesort(arr, 0, s - 1);
    
    cout << "Sorted Array: ";
    printt(arr, s);
    
    return 0;
}

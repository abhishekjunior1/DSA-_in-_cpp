#include<iostream>
using namespace std;
#include<algorithm>

int  partining(int [],int ,int );
void quick(int [],int,int);



int partining(int arr[],int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
        start++;
        while(arr[end]>pivot)
        end--;
        if(start<end)
        {
            swap(arr[start],arr[end]);
        }

    }
    swap(arr[lb],arr[end]);
    return end;


}
void quick(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partining(arr,lb,ub);
        quick(arr,lb,loc-1);
        quick(arr,loc+1,ub);
    }
}
void print(int arr[])
{
    for(int i=0;i<9;i++)
    cout<<arr[i]<<"  ";
}


int main()
{
    int arr[]={7,6,10,5,9,2,1,15,7};
    quick(arr,0,8);
    print(arr);

}
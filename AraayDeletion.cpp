#include<iostream>
using namespace std;
#include<unordered_set>
#include<algorithm>
int main()
{
    int n;
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++)
    cin>>arr1[i];


    int m;
    cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++ )
    cin>>arr2[i];

    int k=m+n;
    int mer[k];
    int count=0;
    for(int i=0;i<n;i++)
    {
    mer[count]=arr1[i];
    count++;
    }



    for(int i=0;i<m;i++)
    {
    mer[count]=arr2[i];
    count++;
    }

//     unordered_set<int>se;
//     for(int i=0;i<k;i++)
//    {
//     se.insert(mer[i]);
//    }
//    unordered_set<int>::iterator i;
//    for(i=se.begin();i!=se.end();i++)
//    cout<<*i<<" ";
for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (mer[i] == mer[j]) {
                for (int shift = j; shift < k - 1; shift++) {
                    mer[shift] = mer[shift + 1];
                }
                k--; 
                j--; //aak element chut raha tha;
            }
        }
    }

    for(int i=0;i<k;i++)
    cout<<mer[i]<<" ";
}
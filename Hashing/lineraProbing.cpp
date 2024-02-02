#include <iostream>
using namespace std;
// Linear probing  
int main()
{
    int tableSize = 10;
    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++)
    {
        hashTable[i] = -1;
    }

    for (int i = 0; i < 10; i++)  
    {
        int data;
        cin>>data;
        int index=data%10;
        if(hashTable[index]==-1)
        hashTable[index]=data;
        else{
            while(hashTable[index]!=-1)
            {
                index++;
                if(index==10)
                index=0;
            }
            hashTable[index]=data;
        }
    }

    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i] != 1)
        {
            cout<<hashTable[i]<<" ";

        }
    }
    return 0;
}
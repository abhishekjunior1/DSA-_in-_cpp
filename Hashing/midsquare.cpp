#include<iostream>
using namespace std;

int main() {
    int k;  
    cout << "Enter the number of keys (k): ";
    cin >> k;
    
    int size;  
    cout << "Enter the size of the hash table: ";
    cin >> size;

    int hashtable[size];  
    for (int i = 0; i < size; i++) {
        hashtable[i] = -1;  
    }

    for (int i = 0; i < k; i++) {
        int key;
        cin >> key;
        int index = key * key;
        while (index >= size) {
            index = index / 10;
            if (index >= size) {
                int n;
                if (index > 1000)
                    n = 1000;
                else if (index > 100)
                    n = 100;
                else
                    n = 10;
                index = index % n;
            }
        }

        // Linear probing
        if (hashtable[index] == -1) {
            hashtable[index] = key;
        } else {
            while (hashtable[index] != -1) {
                index++;
                if (index == size)
                    index = 0;
            }
            hashtable[index] = key;
        }
        cout << "\nAddress of " << key << " is: " << index;
    }

    // Printing keys index-wise
    for (int i = 0; i < size; i++) {
        if (hashtable[i] != -1)
            cout << "\nIndex " << i << ": key = " << hashtable[i];
    }

    return 0;
}
#include<iostream>
using namespace std;
int sum(int s, int n)
{
    if (n == 0)
    return s;
    sum(s + n, n - 1);
}

int main()
{
    int n = 4;
    int s = 0;
    int result = sum(s, n);
    cout << "Sum: " << result << endl;

    return 0;
}

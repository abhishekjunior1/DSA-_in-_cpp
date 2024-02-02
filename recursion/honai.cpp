#include<iostream>
using namespace std;
int movement (int n,char s,char aux,char d)
{
    if(n==1)
    {
        cout<<"Move disk 1 from "<<s<<" to "<<d<<endl;
        return 1;
    }
    int moves =0;
    moves+=movement(n-1,s,d,aux);//move n-1
    cout<<"move disk "<<n<<" from "<<s<<" to "<<d<<endl;
    moves++;//move the largest disk from source to destination
    moves+=movement(n-1,aux,s,d);//move n-1
    return moves;

}


int main()
{
    int n;
    cout<<"Enter number of disk: ";
    cin>>n;

    char source='A';
    char auxiliry='B';
    char destination='C';
    int tot= movement(n,source,auxiliry,destination);
    cout<<"total movment is :"<<tot;



}
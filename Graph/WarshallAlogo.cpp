
#include<iostream>
using namespace std;
void transitiveClosure(int** graph,int n){
    int **closure = new int*[n];
    for(int i=0;i<n;i++){
        closure[i] = new int[n];
        for(int j=0;j<n;j++){
            closure[i][j] = graph[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){//---------->change the logic for floydes warshall algo..(notebook)
                closure[i][j]= closure[i][j] || (closure[i][k] && closure[k][j]);
            }
        }
    }
    cout<<"Transitive Closure Matrix: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<closure[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        delete[] closure[i];
    }
    delete[] closure;
}
int main(){
    int n;
    cin>>n;
    int** graph = new int*[n];
    for(int i=0;i<n;i++){
        graph[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    transitiveClosure(graph,n);
    for(int i=0;i<n;i++){
        delete[] graph[i];
    }
    delete[] graph;
    return 0;
}

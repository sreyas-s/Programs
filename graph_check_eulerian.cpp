//given a graph-check if it is eulerian.

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    //number of vertices.
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    //read the adjacency matrix also.
    //check if degree of every vertex is even.
    int degree=0;
    int flag=0;
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                degree+=a[i][j];
            }
            if((degree%2)!=0){
                flag=1;
                break;
            }
            else{
                degree=0;
                continue;
            }
        }
    if(flag==1){
        //it means that degree of some vertex is odd and graph is not eulerian.
        cout<<"false";
    }
    else{
        cout<<"true";
    }
    return 0;
}

//dfs of graph
//graph-given as adjacency matrix, then converted to adj list.

#include<iostream>
#include<vector>
using namespace std;

void dfs(int, int *, int *, int);

int main(){
    int n;
    cout<<"Number of vertices?"<<endl;
    cin>>n;
    int adjmat[n][n];
    cout<<"Enter the adjacency matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adjmat[i][j];
        }
    }
    int curr=0;
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    dfs(curr, &(adjmat[0][0]), visited, n);
    return 0;
}

void dfs(int curr, int *adjmat, int *visited, int n){
    cout<<curr<<" ";
    visited[curr]=1;
    //find the neighbors of curr-if they are not visited-do dfs on them.
    for(int i=0;i<n;i++){
        if(*(adjmat+(curr*n)+i)==1){
            if(visited[i]==0){
                //then call dfs.
                dfs(i, adjmat, visited, n);
            }
        }
    }
}


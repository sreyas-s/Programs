//given a graph-perform bfs traversal of the graph.
//graph-given as adjacency matrix.

#include<iostream>
#include<queue>
using namespace std;

void bfs(int *, int);

int main(){
    int n;
    cout<<"Number of vertices?"<<endl;
    cin>>n;
    //vertices -numbered from 0 to n-1.
    int adjmat[n][n];
    cout<<"Enter the adjacency matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adjmat[i][j];
        }
    }
    //now, we have the adjacency matrix.
    //we can call a function to do the bfs traversal of the graph.
    bfs(&adjmat[0][0], n);
    return 0;
   
}

void bfs(int *adjmat, int n){
    queue<int> q;//queue for storing vertices.
    int visited[n];//visited array.
    //we have to initialize the array to be all 0s.
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    //we have to start with a vertex.
    int curr=0;
    //now, current vertex is 0. we are starting with 0.
    //push that into queue.
    q.push(curr);
    //after pushing-it means it has been added to queue and so it is visited.
    //make the visited[curr] as 1.
    visited[curr]=1;
    while(!q.empty()){
        curr=q.front();
        cout<<curr<<" ";
        //add neighbors of current to queue.
        //to check neighbors of curr-we have to use the adjacency matrix.
        for(int i=0;i<n;i++){
            //if(adjmat[curr][i]==1){
            if(*(adjmat+(curr*n)+i)==1){
                //we have to push i to queue if it is not visited.
                if(visited[i]==0){
                    q.push(i);
                    visited[i]=1;
                }
            }
            else{
                continue;
            }
        }
        //so, we have added neighbors of curr-if they are not visited before.
        q.pop();
    }
}

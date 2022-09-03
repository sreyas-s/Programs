//to find dfs traversal of graph
//graph-given as adjacency list.

#include<iostream>
#include<vector>
using namespace std;

void dfs(int, vector<int> *, int *);

int main(){
    int n;
    int m;
    cout<<"Number of vertices?"<<endl;
    cin>>n;
    vector<int> adj[n]; //adjacency list declaration.-array of vectors.
    cout<<"Number of edges?"<<endl;
    cin>>m;
    int u,v;
    cout<<"Enter them"<<endl;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //adjacency list creation is done.
    int curr=0;
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    dfs(curr, adj, visited);
    return 0;
}

void dfs(int curr, vector<int> adj[], int *visited){
    //no stack or queue required-it is gonna be a recursive function-so inbuilt stack.
    visited[curr]=1;
    cout<<curr<<" ";
    vector<int>::iterator itr;
    for(itr=adj[curr].begin();itr!=adj[curr].end();itr++){
        //look at the outgoing edges from curr-and if any of those nodes's visited is 0, visit it.
        if(visited[*itr]==0){
            dfs(*itr, adj, visited);
        }
    }
}

//detect cycle in an undirected graph.

#include<iostream>
#include<vector>
using namespace std;

bool checkcycle(int, vector<int>*, int *, int);

int main(){
    int n,m;
    cout<<"Number of vertices?"<<endl;
    cin>>n;
    cout<<"Number of edges"<<endl;
    cin>>m;
    int u,v;
    vector<int> adj[n];
    cout<<"Enter them"<<endl;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int curr=0;
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    int parent=-1;//initially.
    bool val;
    val=checkcycle(curr, adj, visited, parent);
    if(val==true){
        cout<<"Cycle detected"<<endl;
    }
    else{
        cout<<"No cycle"<<endl;
    }
    //supplying the current node, adjacency list, visited array, parent of the current node.
    return 0;
}

bool checkcycle(int curr, vector<int> adj[], int *visited, int parent){
    visited[curr]=1;
    bool value;
    vector<int>::iterator itr;
    for(itr=adj[curr].begin();itr!=adj[curr].end();itr++){
        if(visited[*itr]==0){
            value=checkcycle(*itr, adj, visited, curr);
            if(value){
                return true;
            }
        }
        else{
            //that means visited =1.
            //if we find a visited node and whose parent is not curr. then cycle.
            if(parent!=*itr){//*itr is previously visited node. if that node is not my parent, cycle.
                return true;
            }
        }
    }
    return false;
}


//given a graph-perform bfs traversal of the graph.
//graph-given as adjacency list.

#include<iostream>
#include<queue>
using namespace std;

void bfs(int *, int);

int main(){
    int n;
    cout<<"Number of vertices?"<<endl;
    cin>>n;
    //vertices -numbered from 0 to n-1.
    vector<int> adj[n];
    vector<int>::iterator itr;
    int m;
    cout<<"How many edges?"<<endl;
    cin>>m;
    cout<<"Enter them"<<endl;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //we can call a function to do the bfs traversal of the graph.
    //If I call-how will I pass adjacency list as parameter to function.????
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
        //traverse through the adjacency list row of curr.
        for(itr=adj[curr].begin();itr!=adj[curr].end();itr++){
            if(visited[*itr]==0){
                q.push(*itr);
                visited[*itr]=1;
            }
            else{
                continue;
            }
        }
        //so, we have added neighbors of curr-if they are not visited before.
        
        q.pop();
    }
    return 0;
   }

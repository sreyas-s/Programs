#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

bool comp(pair<pair<int, int>, int>, pair<pair<int, int>, int>);
bool checkcycle(int, vector<int> *, int *, int);

int main(){
    int n,m;
    cin>>n>>m;
    int edgenum, src, dest, weight;
    vector<pair<int, int>> adj[n+1]; //as there are n vertices.
    for(int i=0;i<m;i++){
        cin>>edgenum>>src>>dest>>weight;
        adj[src].push_back({dest, weight});
        adj[dest].push_back({src, weight});
        }
    vector<pair<int, int>>::iterator itr, it;
    vector<pair<int,int>> edgepair;
    for(int i=1;i<(n+1);i++){
        for(itr=adj[i].begin();itr!=adj[i].end();itr++){
            if(find(edgepair.begin(), edgepair.end(), make_pair((*itr).first, i))==edgepair.end()){
                    edgepair.push_back(make_pair(i,(*itr).first));
                }
            }
        } //we have edgepairs now as vector.
    vector<pair<pair<int, int>, int>> edgepair_with_weights;
    for(it=edgepair.begin(); it!=edgepair.end();it++){
        for(itr=adj[(*it).first].begin();itr!=adj[(*it).first].end();itr++){
            if((*itr).first==(*it).second){
                break;
            }
            else{
                continue;
            }
        }
        edgepair_with_weights.push_back({{(*it).first, (*it).second}, (*itr).second});
    }//now, we have edgepairs with weights also. now we need to sort that.
    vector<pair<pair<int, int>, int>>::iterator itv;
    sort(edgepair_with_weights.begin(), edgepair_with_weights.end(), comp);
    //sorting according to edge weights also done.
    vector<pair<int, int>> mstedges; //we have to find suitable edges to add to mst and add to this vector.
    //add one by one and after adding-check for cycle.
    //vertex set is from 1 to n.
    vector<int> trialmstadj[n+1];
    vector<int> realmstadj[n+1];
    for(itv=edgepair_with_weights.begin(); itv!=edgepair_with_weights.end();itv++){
        //for each of the itv's first only we need.-that is the pair.
        int u,v;
        u=(*itv).first.first;
        v=(*itv).first.second;
        //add edge u,v and check for cycle.
        trialmstadj[u].push_back(v);
        trialmstadj[v].push_back(u);
        //at each step, trial mst adj list is getting built.
        //now, check for cycle.
        int curr=1;
        int visited[n+1];
        for(int i=1;i<n+1;i++){
            visited[i]=0;
        }
        int parent=-1;//initially.
        bool val;
        val=checkcycle(curr, trialmstadj, visited, parent);
        if(val==true){
            //cout<<"Cycle detected"<<endl;
            trialmstadj[u].pop_back();
            trialmstadj[v].pop_back();
        }
        else{
           // cout<<"No cycle"<<endl;
           //That means we can actually add that edge.
            realmstadj[u].push_back(v);
            realmstadj[v].push_back(u);
            mstedges.push_back({u,v});
        }
    }
    //now, we have to print the mst edges.and cost of mst.
    vector<pair<int, int>>::iterator style;
    cout<<"MST edges:"<<endl;
    for(style=mstedges.begin();style!=mstedges.end();style++){
        cout<<(*style).first<<","<<(*style).second<<endl;
    }
    //now, have to print the cost of mst.
    int mst_cost=0;
     for(style=mstedges.begin();style!=mstedges.end();style++){
        //for each pair find the weight part by traversing in edgepair_with_weights.
        for(itv=edgepair_with_weights.begin(); itv!=edgepair_with_weights.end();itv++){
            if(*style==(*itv).first){
                mst_cost+=(*itv).second;
            }
            else{
                continue;
            }
        }
    }
    cout<<"\nCost of MST:"<<mst_cost<<endl;
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
       
       
bool comp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
    if(p1.second<=p2.second){
        return true;
    }
    else{
        return false;
    }
}

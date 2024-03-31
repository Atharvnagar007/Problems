// Minimum Cost Path
// A weighted directed graph can be represented with g nodes nodes numbered from 0 to g nodes - 1 and g edges edges where the th edge connects the nodes numbered g from[i] to g to[i] and has a weight g weight[i]. The cost of a particular path between two nodes is defined as the maximum weight of any edge that exists in the path.
// Given g nodes, g edges, g from, g to, and max edges, find the minimum cost of a path from the node 0 to g nodes - 1 that contains at most max_edges edges. If no such path exists, report -1.
// Example
// Suppose g nodes = 4, g edges=5, max_edges = 2, g from [0, 1, 0, 2, 21, g to [1, 3, 2, 3, 2], and g weight = [5, 6, 6, 5, 5].
// The optimal path is from node 0 to 1 to 3 with the weights of the edges 5 and 6 respectively. Thus, the cost of the path is 6. Another path with cost 6 is 0 to 2 to 3. Note that the path 0 to 1 to 2 to 3 has a cost 5 but can not be chosen as the number of edges in the path i.e. 3 is greater than max_edges =2.
// Thus, the answer is 6.

#include<bits/stdc++.h>
using namespace std;
bool solve(int k,vector<pair<int,int>> adj[],int dest,int limit){
    queue<pair<int,int>> q;
    q.push({0,0});
    map<int,int> vis;
    vis[0]=1;
    int taken =0;

    while(!q.empty()){
        int sz=q.size();
        while(sz--){
     auto [curr,wt]=q.front();
     q.pop();
     if(curr==dest){
        return (taken<=k);
     }
    
        vis[curr]=1;
        for(auto[nbrs,wt]:adj[curr]){
            if(!vis[nbrs] && wt<=limit){
                q.push({nbrs,wt});
            }
     }
     
        }
     taken++;  

    }
     return false;
}
int getMinCost(int MaxEdges,int g_nodes,vector<int> g_from,vector<int> g_to,vector<int> g_weights){
    vector<pair<int,int>>adj[g_nodes];
    int max_possible=0;
    int g_edges=g_from.size();
    for(int i=0;i<g_edges;i++){
        adj[g_from[i]].push_back({g_to[i],g_weights[i]});
        max_possible=max(max_possible,g_weights[i]);
    }
   for(int i=0;i<g_nodes;i++){
    sort(adj[i].begin(),adj[i].end(),[&]
    (pair<int,int>&a , pair<int,int> &b){
      return a.second<b.second;
    });
   }
   int lo=1,hi=max_possible;
   int ans=-1,count=1;
   while(lo<=hi){
    int mid=(lo+hi)/2;
     if(solve(MaxEdges,adj,g_nodes-1,mid)){
        ans=mid;
        hi=mid-1;
     }
     else lo=mid+1;
   }
   return ans;
}

int main() {
    int MaxEdges = 5;
    int g_nodes = 6;
    vector<int> g_from = {0, 1, 2, 2, 3, 4};
    vector<int> g_to = {1, 2, 3, 4, 5, 5};
    vector<int> g_weights = {2, 3, 4, 5, 1, 2};

    int minCost = getMinCost(MaxEdges, g_nodes, g_from, g_to, g_weights);
    cout << "Minimum cost: " << minCost << std::endl;
   //for this answer is 4
    return 0;
}
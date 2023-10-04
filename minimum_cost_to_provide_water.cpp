#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }
//union by rank
    void unionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
// union by size
    void unionBysize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)return ;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

};
int minCostToProvideWater(int n, vector<int>& wells,vector<vector<int> >& pipes){
 set<vector<int>> st;
  for(auto it:pipes){
    st.insert({it[2],it[0],it[1]});
  }
 for(int i=0;i<n;i++){
    st.insert({wells[i],0,i+1});
 }
DisjointSet dsu(n);
int ans=0;
while(!st.empty()){
    auto it=st.begin();
    int wt=(*it)[0];
    int u=(*it)[1];
    int v=(*it)[2];

    if(dsu.findUpar(u)!=dsu.findUpar(v)){
        ans+=wt;
        dsu.unionBysize(u,v);
    }
    st.erase(st.begin());
}
return ans;

 }
int main()
{
    int N = 4;
    vector<int> wells = { 1, 2, 1, 2 };
    vector<vector<int> > pipes
        = { { 1, 2, 1 }, { 1 ,3, 3 },{2 , 3 ,3}, {3 , 4, 1} };
    cout << minCostToProvideWater(N, wells, pipes);
    return 0;
}
//Suppose, N=4, wells[1, 2, 1, 2], pipes=[[1 2 1], [1 3 3],[2 3 3], [3 4 1]]
class Solution{
private:
void dfs(int node,vector<int> adj[],vector<int> &vis,stack<int> &st){
    vis[node]=1;
    for(auto it:adj[node]){
        
        if(!vis[it])dfs(it,adj,vis,st);
    }
    st.push(node);
}
private:
void dfs3(int node,vector<int> adjT[],vector<int> &vis,int &size){
    vis[node]=1;
    size++;
    for(auto it:adjT[node]){
        if(!vis[it]) dfs3(it,adjT,vis,size);
    }
}
public:
    int captainAmerica(int n, int m, vector<vector<int>> &V){
        vector<int> adj[n+1],out(n+1,0);
        for(int i=0;i<m;i++){
            adj[V[i][0]].push_back(V[i][1]);
            out[V[i][0]]++;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(out[i]==0)cnt++;
        }
        if(cnt==1)return 1;
        stack<int> st;
        vector<int> vis(n+1,0);
        for(int i=1;i<=n;i++){
            
             if(!vis[i]) dfs(i,adj,vis,st);
        }
        vector<int> adjT[n+1];
        for(int i=0;i<m;i++){
            vis[V[i][1]]=0;
            adjT[V[i][1]].push_back(V[i][0]);
        }
        int answer=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            if(!vis[node]){
                int size=0;
                dfs3(node,adjT,vis,size);
                if(size>1)answer+=size;
            }
        }
        return answer;
    } 
};

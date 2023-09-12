bool dfs(vector<int> adj[],vector<int> &vis, int start, int parent){
    vis[start] = true;
    for(auto u : adj[start]){
        if(!vis[u]){
            if(dfs(adj,vis,u,start)){
                return 1;    
            }
        }
        else if(u != parent){
            return 1;
        }
    }
    return 0;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]-1].push_back(B[i][1]-1);
        adj[B[i][1]-1].push_back(B[i][0]-1);
    }
    vector<int> vis(A,false);
    bool found = 0;
    for(int i=0;i<A;i++){
        if(!vis[i] && dfs(adj,vis,i,-1)){
            return 1;
        }
    }
    return 0;
}

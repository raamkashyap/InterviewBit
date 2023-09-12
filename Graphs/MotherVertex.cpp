void dfs(vector<int> adj[],vector<int> &vis, int u){
    vis[u] = true;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(adj,vis,v);
        }
    }
    return;
}
int Solution::motherVertex(int A, vector<vector<int> > &B) {
    vector<int> adj[A];
    vector<int> vis(A,false);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]-1].push_back(B[i][1]-1);
    }
    int mother;
    for(int i=0;i<A;i++){
        if(!vis[i]){
            mother = i;
            dfs(adj,vis,i);
        }
    }
    for(int i=0;i<A;i++){
        vis[i] = false;
    }
    dfs(adj,vis,mother);
    for(int i=0;i<A;i++){
        if(!vis[i]){
            return 0;
        }
    }
    return 1;
}

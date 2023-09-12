void dfs(vector<int> &vis, vector<int> adj[],int u){
    vis[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v])
            dfs(vis,adj,v);
    }
    return;
}
int Solution::breakRecords(int A, vector<vector<int> > &B) {
    vector<int> adj[A];
    vector<int> vis(A,false);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]-1].push_back(B[i][1]-1);
        adj[B[i][1]-1].push_back(B[i][0]-1);
    }
    int count =0;
    for(int i=0;i<A;i++){
        if(!vis[i]){
            dfs(vis,adj,i);
            count++;
        }
    }
    return count;
}

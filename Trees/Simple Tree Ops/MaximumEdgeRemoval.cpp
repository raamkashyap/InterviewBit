int dfs(int i,vector<int> adj[],vector<int> &vis, int count, int &res){
    vis[i] = true;
    int nodes = 1;
    for(auto u : adj[i]){
        if(!vis[u]){
            int nodesInSubTree = dfs(u,adj,vis,count+1,res);
            if(nodesInSubTree%2 == 0){
                res++;
            }
            else nodes += nodesInSubTree;
        }
    }
    return nodes;
}
int Solution::solve(int n, vector<vector<int> > &B) {
    if(n == 2) return 0;
    vector<int> adj[n+1];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    vector<int> vis(n+1,false);
    int count =1, res=0;
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            dfs(i,adj,vis,count,res);
        }
    }
    return res;
}

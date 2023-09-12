bool dfs(vector<int> adj[],vector<int> &vis, vector<int> &color, int s){
    vis[s] = 1;
    for(auto v : adj[s]){
        if(!vis[v]){
            color[v] = 1 - color[s];
            if(!dfs(adj,vis,color,v))
                return false;
        }
        else if(color[v] == color[s]){
            return false;
        }
    }
    return true;
}
int Solution::solve(int A, vector<vector<int> > &B) {
     vector<int> vis(A,0);
    vector<int> color(A,-1);
    vector<int> adj[A];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]-1].push_back(B[i][1]-1);
        adj[B[i][1]-1].push_back(B[i][0]-1);
    }
    for(int i=0;i<A;i++){
        if(!vis[i] && color[i] == -1){
            color[i] = 1;
            if(!dfs(adj,vis,color,i)){
                return false;
            }
        }
    }
    return true;
}

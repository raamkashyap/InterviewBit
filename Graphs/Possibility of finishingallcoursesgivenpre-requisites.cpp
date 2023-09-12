bool dfs(vector<int> adj[],int v, vector<int> &vis, vector<int> &rec){
   vis[v] = 1;
   rec[v] = 1;
   for(auto n : adj[v]){
       if(!vis[n]){
           if(dfs(adj,n,vis,rec)){
               return 1;
           }
       }
       else if(rec[n]){
           return 1;
       }
   }
   rec[v] = 0;
   return 0;
} 
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<int> adj[A+1];
    for(int i=0;i<B.size();i++){
        adj[B[i]].push_back(C[i]);
    }
    vector<int> vis(A+1,0);
    vector<int> rec(A+1,0);
    for(int i=1;i<A;i++){
        if(!vis[i] & dfs(adj,i,vis,rec)){
            return 0;
        }
    }
    return 1;
}
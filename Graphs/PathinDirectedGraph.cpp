void dfs(vector<int> graph[], int start, int end, vector<int> &vis){
    vis[start] = true;
    if(start == end){
        return;
    }
   for(auto v: graph[start]){
       if(!vis[v]){
           dfs(graph,v,end,vis);
       }
   }
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> graph[A];
    int m = B.size();
    for(int i=0;i<m;i++){
        graph[B[i][0]-1].push_back(B[i][1]-1);
    }
    vector<int> vis(A, 0);
    if(graph[0].size() ==0){
        return false;
    }
    dfs(graph,0,A-1,vis);
    if(vis[A-1]) return true;
    return false;
}

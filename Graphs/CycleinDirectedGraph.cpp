void dfs(vector<int> &A, int v, int &ans, vector<int> &vis){
    vis[v] = 1;
    if(vis[A[v-1]] == 0){
        dfs(A,A[v-1],ans,vis);
        vis[v] = 2;
    }
    if(vis[A[v-1]] == 1){
        ans++;
        vis[v] = 2;
        return;
    }
    if(vis[A[v-1]] == 2){
        vis[v] = 2;
        return; 
    }
    return;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> vis(n+1,0);
    vis[1] = 2;
    int ans =0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(A,i,ans,vis);
        }
    }
    return ans;
}

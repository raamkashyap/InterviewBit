void dfs(vector<int> &A, int C, vector<int> &vis, vector<int> adj[], int start,int &res, int count){
    vis[start] = 1;
    if(A[start] == 1){
        count++;
    }
    if(adj[start].size() ==1){
        if(count <= C){
            res++;
        }
        return;
    }
    for(auto v: adj[start]){
        if(!vis[v]){
            dfs(A,C,vis,adj,v,res,count);
        }
    }
}
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();
    vector<int> adj[n];
    for(int i=0;i<B.size();i++){
        vector<int> temp = B[i];
        adj[temp[0]-1].push_back(temp[1]-1);
        adj[temp[1]-1].push_back(temp[0]-1);
    }
    vector<int> vis(n,0);
    int res =0,count=0;
    dfs(A,C,vis,adj,0,res,count);
    return res;
}

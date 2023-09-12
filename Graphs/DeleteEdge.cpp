int dfs(vector<int> A,vector<int> adj[],int totalsum, long long int &ans, vector<int> &vis, int source){
    vis[source] = true;
    long long int subtreeSum = A[source -1];
    for(auto v : adj[source]){
        if(!vis[v]){
            subtreeSum += dfs(A,adj,totalsum,ans,vis,v);    
        }
        
    }
    // subtreeSum += A[source];
    long long int temp = subtreeSum*(totalsum-subtreeSum);
    if(temp > ans){
        ans = temp;
    }
    return subtreeSum;
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    long long int totalsum = 0;
    for(int i=0;i<A.size();i++){
        totalsum += A[i];
    }
    vector<int> adj[A.size()+1];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    long long int ans =INT_MIN;
    vector<int> vis(A.size()+1,0);
    dfs(A,adj,totalsum,ans,vis,1);
    return ans%(int(1e9+7));
}

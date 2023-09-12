int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<pair<int, int>>> adj(A);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]-1].push_back({B[i][1]-1,B[i][2]});
        adj[B[i][1]-1].push_back({B[i][0]-1,B[i][2]});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,0});
    int ans =0;
    bool vis[A];
    memset(vis,0,sizeof(vis));
    while(!q.empty()){
        int cost = q.top().first;
        int vertex = q.top().second;
        q.pop();
        if(vis[vertex]) continue;
        vis[vertex] = true;
        ans += cost;
        for(auto node : adj[vertex]){
            if(!vis[node.first]){
                q.push({node.second,node.first});
            }
        }
    }
    return ans;
}

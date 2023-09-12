void dijkstra(vector<pair<int,int>> adj[],vector<int> &dis, int u){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,u});
    while(!pq.empty()){
        int wt = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        for(auto n : adj[v]){
            if(dis[n.first] > dis[v] + n.second ){
                dis[n.first] = dis[v] + n.second;
                pq.push({dis[n.first],n.first});
            } 
        }
    }
    return;
}
int Solution::solve(int n, vector<vector<int> > &edges, int src, int des, vector<vector<int> > &extra) {
    src--;
    des--;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]-1].push_back({edges[i][1]-1,edges[i][2]});
        adj[edges[i][1]-1].push_back({edges[i][0]-1,edges[i][2]});
    }
    vector<int> distC(n,INT_MAX);
    vector<int> distD(n,INT_MAX);
    distC[src] =0;
    distD[des] = 0;
    dijkstra(adj,distC,src);
    dijkstra(adj,distD,des);
    
    int ans = INT_MAX;
    for(int i=0;i<extra.size();i++){
        extra[i][0]-=1;
        extra[i][1]-=1;
    }
    if(distC[des]!=INT_MAX)ans=distC[des];
    for(int i=0;i<extra.size();i++){
        if(distC[extra[i][0]] != INT_MAX &&  distD[extra[i][1]] != INT_MAX){
            ans=min(ans, min(distC[extra[i][0]]+distD[extra[i][1]]+extra[i][2], distC[extra[i][1]]+distD[extra[i][0]]+extra[i][2]));
        }
    }
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}

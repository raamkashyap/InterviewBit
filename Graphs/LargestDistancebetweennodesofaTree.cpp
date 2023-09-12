int bfs(int start,vector<int> graph[],bool flag, int n){
    vector<int> vis(n,0);
    queue<pair<int,int>> q;
    q.push({start,0});
    vis[start] = true;
    int dis;
    while(!q.empty()){
        pair<int,int> temp = q.front();
        start = temp.first;
        dis = temp.second;
        q.pop();
        
        for(auto v : graph[start]){
            if(vis[v] == false){
                q.push({v,dis+1});
                vis[v] = true;
            }
        }
    }
    if(flag == false){
        return start;
    }
    return dis;
}
int Solution::solve(vector<int> &A) {
 vector<int> graph[A.size()];
 for(int i=0;i<A.size();i++){
     if(A[i] != -1){
         graph[i].push_back(A[i]);
         graph[A[i]].push_back(i);
     }
 }   
 int last_node = bfs(0,graph,false,A.size());
 return bfs(last_node,graph,true,A.size());
}

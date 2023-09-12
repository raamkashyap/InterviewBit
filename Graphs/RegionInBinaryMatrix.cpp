int row[8] = {-1,-1,-1,0,0,1,1,1};
int col[8] = {-1,0,1,-1,1,-1,0,1};
void dfs(vector<vector<int>> &vis, vector<vector<int> > &A, int x, int y,int m,int n,int &count){
    vis[x][y] = 1;
    count++;
    for(int i=0;i<8;i++){
        int dx = x + row[i];
        int dy = y + col[i];
        if(dx >=0 && dx < m && dy >=0 && dy < n && !vis[dx][dy] && A[dx][dy] == 1){
            // count++;
            dfs(vis,A,dx,dy,m,n,count);
        }
    }
    return;
}
int Solution::solve(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> vis(m,vector<int> (n,false));
    int ans =0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && A[i][j]){
                int count =0;
                dfs(vis,A,i,j,m,n,count);
                ans = max(ans,count);
            }
        }
    }
    return ans;
    
}

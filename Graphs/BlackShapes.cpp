int row[4] = {-1,0,0,1};
int col[4] = {0,-1,1,0};
void dfs(vector<string> &A, int x,int y, vector<vector<int>> &vis,int m,int n){
    if(x <0 || x >=m || y <0 || y >=n) return;
    if(vis[x][y] || A[x][y] == 'O') return;
    vis[x][y] = true;
    for(int i=0;i<4;i++){
        int dx = x + row[i];
        int dy = y + col[i];
        if(dx >= 0 && dx < m && dy >= 0 && dy < n && !vis[dx][dy] && A[dx][dy] == 'X'){
            dfs(A,dx,dy,vis,m,n);
        }
    }
    return;
}
int Solution::black(vector<string> &A) {
    int m = A.size();
    int n = A[0].size();
    int count =0;
    vector<vector<int>> vis(m,vector<int>(n,false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j] == 'X' && !vis[i][j]){
                dfs(A,i,j,vis,m,n);
                count++;
            }
        }
    }
    return count;
}


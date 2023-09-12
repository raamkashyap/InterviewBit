void dfs(int x,int y,int m,int n,vector<vector<int>> &A, vector<vector<int>> &vis, int row[],int col[]){
    vis[x][y] = 1;
    for(int i=0;i<4;i++){
        int dx = x + row[i];
        int dy = y + col[i];
        if(dx >=0 && dx < m && y >=0 && y <n){
            if(A[dx][dy] >= A[x][y] && !vis[dx][dy]){
                dfs(dx,dy,m,n,A,vis,row,col);
            }
        }
    }
}
int Solution::solve(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> blue(m,vector<int>(n,0));
    vector<vector<int>> red(m,vector<int>(n,0));
    int row[4] = {-1,0,0,1};
    int col[4] = {0,-1,1,0};
    for(int i=0;i<n;i++){
        if(!blue[0][i])
            dfs(0,i,m,n,A,blue,row,col);
    }
    for(int i=0;i<m;i++){
        if(!blue[i][0])
            dfs(i,0,m,n,A,blue,row,col);
    }
    for(int i=0;i<n;i++){
        if(!red[m-1][i]){
            dfs(m-1,i,m,n,A,red,row,col);
        }
    }
    for(int i=0;i<m;i++){
        if(!red[i][n-1]){
            dfs(i,n-1,m,n,A,red,row,col);
        }
    }
    int res =0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(red[i][j] && blue[i][j])
                res++;
        }
    }
    return res;
    
}

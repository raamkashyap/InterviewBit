bool dfs(int sourceRow,int sourceCol,int desRow,int desCol,vector<vector<int>> &vis, vector<vector<int> > &A, int m,int n){
    if(A[sourceRow][sourceCol] == 2){
        return 1;
    }
    vis[sourceRow][sourceCol] = 1;
    int row[4] = {-1,0,0,1};
    int col[4] = {0,-1,1,0};
    for(int i=0;i<4;i++){
        int dx = sourceRow + row[i];
        int dy = sourceCol + col[i];
        if(dx >=0 && dx < m && dy >=0 && dy < n && !vis[dx][dy] && (A[dx][dy] == 3 || A[dx][dy] == 2) && dfs(dx,dy,desRow,desCol,vis,A,m,n)){
            return true;
        }
    }
    return false;
}
int Solution::checkPath(vector<vector<int> > &A) {
    int sourceRow,sourceCol, desRow, desCol;
    int m = A.size();
    int n = A[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j] == 1){
                sourceRow = i;
                sourceCol = j;
            }
            else if(A[i][j] ==2){
                desRow = i;
                desCol = j;
            }
        }
    }
    vector<vector<int>> vis(m,vector<int>(n,false));
    return dfs(sourceRow,sourceCol,desRow,desCol,vis,A,m,n);
}

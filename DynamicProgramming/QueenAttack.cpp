int row[8] = {-1,-1,-1,0,0,1,1,1};
int col[8] = {-1,1,0,-1,1,-1,1,0};
int dfs(int r, int c ,int k, vector<string> &A, int m,int n){
    int dr = r + row[k];
    int dc = c + col[k];
    int count =0;
    if(dr >=0 && dr < m && dc >=0 && dc < n){
        if(A[dr][dc] == '1'){
            count ++;
        }
        else{
            count += dfs(dr,dc,k,A,m,n);
        }
    }
    return count;
}
vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int k=0;k<8;k++){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j] += dfs(i,j,k,A,m,n);
            }
        }
    }
    return dp;
}

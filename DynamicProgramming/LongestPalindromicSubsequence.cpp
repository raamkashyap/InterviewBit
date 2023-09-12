int Solution::solve(string A) {
    string B = A;
    reverse(A.begin(),A.end());
    int m = A.size();
    int n = B.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        dp[i][0] = 0;
    for(int i=0;i<=n;i++)
        dp[0][i] = 0;
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else 
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

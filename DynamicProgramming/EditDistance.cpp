int Solution::minDistance(string A, string B) {
    int m = A.size();
    int n = B.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        dp[i][0] = i;
    for(int j=0;j<=n;j++)
        dp[0][j] = j;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else
            dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
        }
    }
    return dp[m][n];
}
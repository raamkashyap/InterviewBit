int Solution::isInterleave(string A, string B, string C) {
    int m = A.size();
    int n = B.size();
    if(m + n != C.size()){
        return 0;
    }
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    dp[0][0] =1;
    for(int i=1;i<=m;i++){
        if(A[i-1] == C[i-1]){
            dp[i][0] = dp[i-1][0];
        }
    }
    for(int i=1;i<=n;i++){
        if(B[i-1] == C[i-1]){
            dp[0][i] = dp[0][i-1];    
        }
    }
    for(int i=1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1]){
                dp[i][j] = dp[i-1][j];
            }
            else if(A[i-1] != C[i+j-1] && B[j-1] == C[i+j-1]){
                dp[i][j] = dp[i][j-1];
            }
            else if(A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1]){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }
    return dp[m][n];
}

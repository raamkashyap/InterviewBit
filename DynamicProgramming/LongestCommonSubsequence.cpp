int Solution::solve(string A, string B) {
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m,vector<int> (n, 0));
    A[0] == B[0]? dp[0][0] = 1 : dp[0][0] =0;
    for(int i=1;i<m;i++){
        if(A[i] == B[0]){
            dp[i][0] = 1;
        }
        else dp[i][0] = dp[i-1][0];
    }
    for(int i=1;i<n;i++){
        if(B[i] == A[0]){
            dp[0][i] = 1;
        }
        else dp[0][i] = dp[0][i-1];
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(A[i] == B[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max({dp[i-1][j-1],dp[i-1][j], dp[i][j-1]});
            }
        }
    }
    return dp[m-1][n-1];
}

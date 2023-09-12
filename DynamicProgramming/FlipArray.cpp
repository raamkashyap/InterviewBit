int Solution::solve(const vector<int> &A) {
    int sum =0;
    int n = A.size();
    for(int i=0;i<n;i++){
        sum += A[i];
    }
    sum = sum/2;
    vector<vector<int>>dp(n+1,vector<int>(sum+1,INT_MAX));
     for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= A[i-1] && dp[i-1][j-A[i-1]] != INT_MAX){
                dp[i][j] = min(dp[i-1][j],dp[i-1][j-A[i-1]]+1);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[n][sum] == INT_MAX){
        for(int i=sum;i >= 0;i--){
            if(dp[n][i] != INT_MAX)
                return dp[n][i];
        }
    }
    return dp[n][sum];
}

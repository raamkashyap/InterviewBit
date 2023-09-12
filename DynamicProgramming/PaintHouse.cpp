int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    // int m = A[0].size();
    vector<vector<int>> dp(n,vector<int>(3));
    for(int i=0;i<3;i++){
        dp[0][i] = A[0][i];
    }
    for(int i=1;i<n;i++){
        dp[i][0] = A[i][0] +  min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = A[i][1] +  min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = A[i][2] +  min(dp[i-1][1], dp[i-1][0]);
    }
    return *min_element(dp[n-1].begin(),dp[n-1].end());
}

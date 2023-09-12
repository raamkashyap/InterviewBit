int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int> dp(n);
     dp[0] = max(A[0][0],A[1][0]);
    dp[1] = max({dp[0],A[0][1],A[1][1]});
    for(int i=2;i<n;i++){
        int mx = max(A[0][i],A[1][i]);
        dp[i] = max(mx + dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}

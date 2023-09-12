int Solution::minSmoke(vector<int> &A) {
    int n = A.size();
    // int prefix[n];
    vector<int> prefix(n);
    prefix[0] = A[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+A[i];
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int diff=1;diff<n;diff++){
        int i=0;
        int j= i+diff;
        for(;j<n;j++,i++){
            dp[i][j] = INT_MAX;
            for(int k=i;k<j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+((prefix[k]-prefix[i-1])%100)*((prefix[j]-prefix[k])%100));
            }
        }
    }
    return dp[0][n-1];
}


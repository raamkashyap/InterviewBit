int Solution::minimumTotal(vector<vector<int> > &A) {
    int m = A.size();
    vector<vector<int>> dp(m);
    dp.push_back(A[0]);
    for(int i=1;i<m;i++){
        vector<int> rowWise(A[i].size(), 0);
        dp.push_back(rowWise);
    }
    for(int i=1;i<m;i++){
        int n = A[i].size();
        // dp[i].reserve(n);
        for(int j=0;j<n;j++){
            if(j==0){
                dp[i][j] = A[i][j] + dp[i-1][j];
            }
            else if(j == n-1){
                dp[i][j] = A[i][j] + dp[i-1][j-1];
            }
            else{
                dp[i][j] = A[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
            }
        }
    }
    return *min_element(dp[m-1].begin(),dp[m-1].end());
}

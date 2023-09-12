int Solution::solve(vector<int> &A, int B) {
    int m = A.size();
    vector<vector<bool>> dp(m+1, vector<bool>(B+1,0));
    for(int i=0;i<=m;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=B;i++){
        dp[0][i] = false;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=B;j++){
            if(j < A[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else if(j >= A[i-1]){
                dp[i][j] = dp[i-1][j] || dp[i-1][j- A[i-1]];
            }
        }
    }
    return dp[m][B];
}

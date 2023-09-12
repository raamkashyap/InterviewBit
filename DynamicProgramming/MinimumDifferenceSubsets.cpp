int Solution::solve(vector<int> &A) {
    int m = A.size();
    int B =0;
    for(int i=0;i<m;i++){
        B += A[i];
    }
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
    int minDiff = INT_MAX;
    for(int i=0;i<=B/2;i++){
        if(dp[m][i] == 1){
            minDiff = min(B-2*i,minDiff);
        }
    }
    return minDiff;
}

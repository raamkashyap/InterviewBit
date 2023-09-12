int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    int dp[C+1];
    for(int i=0; i<C+1; i++){
        dp[i] = 0;
    }
        
    for(int i=1;i<n+1;i++){
        for(int j=C;j>=B[i-1];j--){
            if(B[i-1] <= j){
                dp[j] = max(dp[j],dp[j-B[i-1]]+A[i-1]);
            }
        }
    }
    /*for(int i=0;i<=C;i++){
        cout<<dp[i]<<" ";
    }*/
    return dp[C];
}

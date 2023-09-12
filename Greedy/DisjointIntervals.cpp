int Solution::solve(vector<vector<int> > &A) {
    int res =0;
    int n = A.size();
    vector<int>dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(A[j][1] < A[i][0] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}

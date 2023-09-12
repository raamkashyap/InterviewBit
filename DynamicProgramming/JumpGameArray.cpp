int Solution::canJump(vector<int> &A) {
    int n = A.size();
    if(A[0] == 0 && n>1) return 0;
    if(A[0] ==0 && n ==1)return 1;
    vector<bool> dp(n);
    dp[n-1] = 1;
    int last = n-1;
    for(int i=n-2;i>=0;i--){
        if(i+A[i] >= last){
            dp[i] = true;
            last = i;
        }
    }
    return dp[0];
}

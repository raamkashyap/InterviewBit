int Solution::jump(vector<int> &A) {
    int n = A.size();    
    if(n ==1 ) return 0;
    if(A[0] ==0) return -1;
    vector<int> dp(n, -1);
    dp[0] = 0;
    int current = 0;
    for(int i=0;i<n;i++){
        int reach = i+A[i];
        if(dp[i] == -1){
            return -1;
        }
        for(int j =current+1;j<=min(reach,n-1);j++){
            dp[j] = dp[i]+1;
            current = min(reach,n-1);
        }
    }
    return dp[n-1];
}

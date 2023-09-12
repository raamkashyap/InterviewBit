int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if(n<=2) return n;
    unordered_map<int,int> mp;
    int dp[n][n];
    int maxLength = 2;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            dp[i][j] =2;
            int need = 2*A[i] - A[j];
            if(mp.find(need) != mp.end()){
                dp[i][j] = max(dp[i][j], dp[mp[need]][i]+1);
                maxLength = max(maxLength, dp[i][j]);
            }
        }
        mp[A[i]] = i;
    }
    return maxLength;
}

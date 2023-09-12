int Solution::coinchange2(vector<int> &coins, int n) {
     int m = coins.size();
     int mod = 1000007;
    vector<int> dp(n+1,0);
    dp[0] =1;
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            if(coins[i] <=j){
                dp[j] = ((dp[j])%mod + (dp[j-coins[i]])%mod)%mod;
            }
        }
    }
    return dp[n];   
}

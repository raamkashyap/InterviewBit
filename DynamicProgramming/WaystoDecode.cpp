int Solution::numDecodings(string A) {
    int n = A.size();
    vector<int> dp(n+1,0);    
    int mod = 1e9+7;
    dp[0] = 1;
    dp[1] = (A[0] != '0')? 1 : 0;
    for(int i=2;i<=n;i++){
        int val = stoi(A.substr(i - 2, 2));
        if(A[i-1] != '0'){
            dp[i] += dp[i-1];
        }
        if(val >=10 && val <=26){
            dp[i] += dp[i-2];
        }
        dp[i] %= mod;
    }
    return dp[n];
}

int Solution::isMatch(const string text, const string pattern) {
    int m = text.size();
    int n = pattern.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1,false));
    dp[0][0] = true;
    for(int i=1;i<=m;i++){
        dp[i][0] = false;
    }
    for(int i=1;i<=n;i++){
        bool flag = true;
        for(int j=1;j<=i;j++){
            if(pattern[j-1] != '*'){
                flag = false;
                break;
            }
        }
        dp[0][i] = flag;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(text[i-1] == pattern[j-1] || pattern[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[j-1] == '*'){
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
            }
            else dp[i][j] = false;
        }
    }
    return dp[m][n];
}

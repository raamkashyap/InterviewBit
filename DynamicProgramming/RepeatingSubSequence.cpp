int Solution::anytwo(string A) {
   string B = A;
   int m = A.size();
   vector<vector<int>> dp(m, vector<int> (m, 0));
   for(int i=1;i<m;i++){
       if(A[i] == B[0]){
           dp[i][0] = 1;
       }
   }
   for(int i=1;i<m;i++){
       if(A[0] == B[i]){
           dp[0][i] = 1;
       }
   }
   for(int i=1;i<m;i++){
       for(int j=1;j<m;j++){
           if(A[i] == B[j] && i != j){
               dp[i][j] = dp[i-1][j-1] + 1;
           }
           else 
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
       }
   }
   return (dp[m-1][m-1] >=2)? 1:0;
}

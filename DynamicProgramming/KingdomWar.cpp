void kadanes(vector<int> &temp){
    int lmax = temp[0];
    for(int i=1;i<temp.size();i++){
        lmax = max(temp[i], lmax+temp[i]);
        temp[i] = lmax;
    }
    return;
}
int Solution::solve(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    /*for(int i=0;i<m;i++){
        kadanes(A[i]);
    }
    for(int j=0;j<n;j++){
        int cmax = A[0][j];
        for(int i=1;i<m;i++){
            cmax = max(A[i][j],cmax+A[i][j]);
            A[i][j] = cmax;
        }
    }
    int res = INT_MIN;
    for(int i=0;i<m;i++){
        res = max(res,*max_element(A[i].begin(),A[i].end()));
        /*for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }*/
        // cout<<endl;
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    int res = INT_MIN;
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            dp[i][j] = dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1] + A[i][j];
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

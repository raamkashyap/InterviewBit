int Solution::minPathSum(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    for(int i=1;i<m;i++){
        A[i][0] += A[i-1][0];
    }
    for(int i=1;i<n;i++){
        A[0][i] += A[0][i-1];    
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            A[i][j] += min(A[i][j-1], A[i-1][j]);
        }
    }
    return A[m-1][n-1];
}

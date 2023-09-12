int Solution::solve(vector<vector<int> > &A) {
    int m = A.size();
    int n= A[0].size();
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            if(j == 0){
                A[i][j] += A[i-1][j];
            }
            else
                A[i][j] = A[i][j] + max(A[i-1][j], A[i-1][j-1]);
        }
    }
    return *max_element(A[m-1].begin(), A[m-1].end());
}

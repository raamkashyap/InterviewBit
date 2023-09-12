int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size(), ans = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i !=0 && A[i][j] !=0){
                A[i][j] += A[i-1][j];
            }
        }
    }   
    for(int i=0;i<n;i++){
        sort(A[i].begin(),A[i].end());
    }
    for(int i=0;i<n;i++){
        int width = 1;
        for(int j=m-1;j>=0;j--){
            ans = max(ans,width*A[i][j]);
            width++;
        }
    }
    return ans;
}

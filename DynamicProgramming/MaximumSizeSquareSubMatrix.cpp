int Solution::solve(vector<vector<int> > &A) {
    for(int i=1;i<A.size();i++){
        for(int j=1; j<A[0].size();j++){
            if(A[i][j] == 0){
                continue;
            }
            else{
                A[i][j] = min({A[i][j-1],A[i-1][j],A[i-1][j-1]})+1;
            }
        }
    }
    int maxValue = 0;
    for(int i=0;i<A.size();i++){
        int maxinRow = *max_element(A[i].begin(),A[i].end());
        maxValue = max(maxValue, *max_element(A[i].begin(),A[i].end()));
    }
    return maxValue*maxValue;
}

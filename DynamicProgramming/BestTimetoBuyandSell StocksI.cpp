int Solution::maxProfit(const vector<int> &A) {
    int n= A.size();
    if(n==0) return 0;
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0] = A[0];
    right[n-1] = A[n-1];
    // int res =0;
    for(int i =1;i<n;i++){
        left[i] = min(left[i-1],A[i]);
    }
    for(int i= n-2;i>=0;i--){
        right[i] = max(right[i+1],A[i]);
    }
    int res =0;
    for(int i=0;i<n;i++){
        res  = max(res,right[i]-left[i]);
    }
    return res;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int right[n];
    int res=0;
    right[n-1] = A[n-1];
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1],A[i]);
    }
    set<int> prevValue;
    prevValue.insert(A[0]);
    for(int i =1;i<n-1;i++){
        if(A[i] >= right[i+1]){
            continue;
        }
        prevValue.insert(A[i]);
        auto prev = prevValue.lower_bound(A[i]);
        if(prev== prevValue.begin()){
            continue;
        } 
        prev--;
        res = max(res, (*prev)+A[i]+right[i+1]);
    }
    return res;
}

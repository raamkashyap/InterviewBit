int Solution::solve(vector<int> &A) {
    pair<int,int> res;
    res.first = INT_MAX;
    res.second = INT_MIN;
    for(int i =0;i<A.size();i++){
        if(A[i] > res.second){
            res.second = A[i];
        }
        if(A[i] < res.first){
            res.first = A[i];
        }
    }
    return res.first+res.second;
}

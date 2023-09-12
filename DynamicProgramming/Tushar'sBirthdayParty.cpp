int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int cost[1001];
    int max = *max_element(A.begin(),A.end());
    cost[0] = 0;
    for(int i=1;i<=max;i++){
        cost[i] = INT_MAX;
        for(int j=0;j<B.size();j++){
            if(B[j] <=i){
                cost[i] = min(cost[i], C[j]+cost[i-B[j]]);
            }
        }
    }
    int res =0;
    for(int i=0;i<A.size();i++){
        res += cost[A[i]];
    }
    return res;
}

int Solution::maxProfit(const vector<int> &A) {
    int maxP = 0;
    for(int i=1;i<A.size();i++){
        if(A[i] >= A[i-1]){
            maxP += A[i] - A[i-1];
        }
    }
    return maxP;
}

int Solution::maxSubArray(const vector<int> &A) {
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i =0; i<A.size();i++){
        sum = max(sum+A[i],A[i]);
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}

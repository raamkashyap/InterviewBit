int Solution::maxProduct(const vector<int> &A) {
    int ans=A[0],i,n=A.size();
    int curMin=1,curMax=1;
    for(i=0;i<n;i++)
    {
        int temp=curMin;
        curMin=min(A[i],min(A[i]*curMin,A[i]*curMax));
        curMax=max(A[i],max(A[i]*curMax,A[i]*temp));
        ans=max(ans,curMax);
    }
    return ans;
}

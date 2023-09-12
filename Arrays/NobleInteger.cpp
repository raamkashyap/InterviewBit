int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i++)
    {
        if(A[i] == A.size()-(i+1) && (A[i] != A[i+1] || i == A.size()-1))
        {
           return 1;
        }
    }
   return -1;
}
// 
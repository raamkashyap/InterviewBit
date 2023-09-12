vector<int> Solution::solve(vector<int> &A) {
    int start =0;
    for(int i=0;i<A.size();i++){
        //cu<" <  <"sat"<sat<ed;
        if(A[i] != 0){
            A[start] = A[i];
            start++;   
        }   
    }
    while(start < A.size())
    {
        A[start] = 0;
        start++;
    }
    return A;
    
}

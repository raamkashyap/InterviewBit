vector<int> Solution::solve(vector<int> &A) {
    int start = 0;
    for(int i=0;i<A.size();i++){
        if(A[i] != 1){
            A[start] = 0;
            start++;
        }
    }
    while(start<A.size()){
        A[start] = 1;
        start++; 
    }
    return A;
}

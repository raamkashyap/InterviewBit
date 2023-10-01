bool checkPal(string A, int start, int end){
    while(start<end){
        if(A[start] != A[end]) return false;
        start++;
        end--;
    }
    return true;
}
int Solution::solve(string A) {
    int count =0;
    int n= A.size();
    int i = 0, j = n-1;
    while(i<j && A[i] == A[j]){
        i++;
        j--;
        
    }
    return checkPal(A,i+1,j) || checkPal(A,i,j-1);
}

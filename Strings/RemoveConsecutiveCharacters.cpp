string Solution::solve(string A, int B) {
    int i=0;
    string res ="";
    while(i < A.size()){
        int count =0;
        char c = A[i];
        string t = "";
        while(i < A.size() && A[i] == c){
            count++;
            t += A[i];
            i++;
            
        }
        if(count < B || count > B){
            res += t;
        }
    }
    return res;
}

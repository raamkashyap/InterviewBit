vector<int> Solution::solve(vector<int> &A, int B) {
    int n= A.size();
    vector<int> count(n+1);
    for(int i=0;i<n;i++){
        count[A[i]] = i;
    }
    int val = n;
    for(int i=0;i<n;i++){
        if(B==0){
            break;
        }
        if(A[i] == val){
            val--;
            continue;
        }
        else{
            int val_index = count[val];
            int temp = A[i];
            swap(A[count[val]],A[i]);
            count[val] = i;
            count[temp] = val_index;
            val--;
            B--;
        }
    }
    return A;
}

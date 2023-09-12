vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    int sum = A[n-1]+1;
    int carry;
    (sum>=10)? carry =1 : carry =0;
    A[n-1] = sum%10;
    for(int i=n-2;i>=0;i--){
        sum = A[i]+carry;
        carry = sum/10;
        A[i] = sum%10; 
    }
    if(carry ==1){
        A.insert(A.begin(),carry);
    }
    for(int i=0;i<A.size();i++){
        if(A[0]==0){
            A.erase(A.begin());
        }
        else break;
    }
    return A;
}

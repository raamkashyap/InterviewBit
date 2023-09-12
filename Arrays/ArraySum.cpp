vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {
    int sum=0;
    vector<int> res;
    int carry =0;
    int n = A.size(), m = B.size();
    int i,j;
    for(i=n-1,j=m-1;i>=0 && j >=0;i--,j--){
        sum = A[i] + B[j] + carry;
        carry = sum/10;
        sum = sum%10;
        res.push_back(sum);
    }
    if(j>i){
        i = j;
        A = B;
    }
    for(;i>=0;i--){
        sum = A[i] + carry;
        carry = sum/10;
        sum = sum%10;
        res.push_back(sum);
    }
    if(carry ==1){
        res.push_back(1);
    }
    reverse(res.begin(), res.end());
    return res;
}


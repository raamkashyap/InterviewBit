vector<int> Solution::solve(vector<int> &A) {
    int i=0;
    int j=A.size()-1;
    vector<int>res;
    while(i<=j){
        if(A[i]*A[i]>A[j]*A[j]){
            res.push_back(A[i]*A[i]);
            i++;
        }
        else{
            res.push_back(A[j]*A[j]);
            j--;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

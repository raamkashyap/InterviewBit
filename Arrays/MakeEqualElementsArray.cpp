void removeDuplicates(vector<int> &A){
    vector<int>::iterator it;
    it = unique(A.begin(), A.end());
    A.resize(distance(A.begin(), it));
}
int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    removeDuplicates(A);
    int mid = A.size()/2;
    for(int i=0;i<A.size();i++){   
        if(i > mid){
            A[i] -= B;
        }
        else if(i < mid){
            A[i] += B;
        }
    }
    bool flag = true; 
    for(int i=0;i<A.size()-1;i++){
        if(A[i] != A[i+1])
            flag = false;
    }
    return flag;
}

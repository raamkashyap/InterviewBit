int Solution::solve(vector<int> &A, int B) {
    unordered_set<int> mp;
    for(int i=0;i<A.size();i++){
        if(mp.find(A[i]-B)!=mp.end() || mp.find(A[i]+B) != mp.end()){
            return true;
        }
        mp.insert(A[i]);
    }
    return false;
}

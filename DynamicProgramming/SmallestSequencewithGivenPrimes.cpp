vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res;
    res.push_back(1);
    int i=0,j=0,k=0;
    while(D--){
        int x = min({res[i]*A, res[j]*B,res[k]*C});
        res.push_back(x);
        if(x == res[i]*A){
            i++;
        }
        if(x == res[j]*B){
            j++;
        }
        if(x == res[k]*C){
            k++;
        }
    }
    res.erase(res.begin());
    // res.pop_front();
    return res;
}

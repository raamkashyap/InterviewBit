vector<int> Solution::getRow(int k) {
    vector<int> res{1};
    for(int i=0;i<k;i++){
        res.push_back((res[i]*(k-i))/(i+1));
    }
    return res;
}

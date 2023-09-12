vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> res;
    if(A ==0)
        return res;
    res.push_back({1});
    if(A==1)
        return res;
    res.push_back({1,1});
    if(A==2)
        return res;
    for(int i=2;i<A;i++){
        vector<int> temp;
        temp.push_back(1);
        vector<int> prev = res[res.size()-1];
        for(int j=1;j<prev.size();j++){
            temp.push_back(prev[j]+prev[j-1]);
        }
        temp.push_back(1);
        res.push_back(temp);
    }
    return res;
}

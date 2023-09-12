vector<int> Solution::findOccurences(vector<int> &A) {
    map<int,int> mp;
    for(int i=0;i<A.size();i++){
        if(mp.count(A[i])){
            mp[A[i]]++;
        }
        else mp.insert({A[i],1});
    }
    vector<int> res;
    for(auto it : mp){
        res.push_back(it.second);
    }
    return res;
}

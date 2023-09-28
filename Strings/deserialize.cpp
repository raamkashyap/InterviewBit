vector<string> Solution::deserialize(string A) {
    vector<string> res;
    string temp = "";
    for(int i=0;i<A.size();i++){
        if(A[i] == '~'){
            res.push_back(temp);
            temp = "";
        }
        else if(isalpha(A[i])){
            temp += A[i];
        }
    }
    return res;
}

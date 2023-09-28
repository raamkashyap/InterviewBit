string Solution::solve(string A) {
    int count[26];
    memset(count,0,sizeof(count));
    for(auto c : A){
        count[c-'a']++;
    }
    string res ="";
    for(int i=0;i<A.size();i++){
        if(count[A[i]-'a'] > 0){
            res += A[i];
            res += to_string(count[A[i]-'a']);   
            count[A[i]-'a'] = INT_MIN;
        }
        
    }
    return res;
}

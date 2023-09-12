int Solution::isScramble(const string A, const string B) {
    int n = A.length();
    if(A.length() != B.length()){
        return 0;
    }
    if(A == B){
        return 1;
    }
    if(A.length() ==0){
        return 1;
    }
    string A_copy = A, B_copy = B;
    sort(A_copy.begin(),A_copy.end());
    sort(B_copy.begin(),B_copy.end());
    if(A_copy != B_copy){
        return 0;
    }
    map<pair<string,string>,bool> mp;
    pair<string,string> key = {A,B};
    bool flag = false;
    for(int i=1;i<n;i++){
        if(isScramble(A.substr(0,i),B.substr(0,i)) && isScramble(A.substr(i,n-i),B.substr(i,n-i))){
            flag = true;
            return 1;
        }
        if(isScramble(A.substr(0,i),B.substr(n-i,i)) && isScramble(A.substr(i,n-i),B.substr(0,n-i))){
            flag = true;
            return 1;
        }
    }
    mp[key] = flag;
    return mp[key];
    // return flag;

}

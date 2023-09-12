bool isPalindrome(string A){
    int start = 0;
    int last = A.size()-1;
    while(start<=last){
        if(A[start] == A[last]){
            start++;
            last--;
        }
        else return false;
    }
    return true;
}
int solve(string A,map<string,int> &mp){
    if(isPalindrome(A)) return 0;
    if(mp[A]) return mp[A];
    int ans = INT_MAX;
    for(int i = 1;i <=A.size();i++){
        string temp = A.substr(0,i);
        if(isPalindrome(temp)){
            ans = min(ans,1+solve(A.substr(i,A.size()-i),mp));
        }
    }
    return mp[A] = ans;
}
int Solution::minCut(string A) {
    map<string,int> mp;
    // vector<string> temp;
    return solve(A,mp);

}

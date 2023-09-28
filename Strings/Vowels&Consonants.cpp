bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return 1;
    }
    return 0;
}
int Solution::solve(string A) {
    int countV = 0 ;
    int mod = 1e9+7;
    for(int i=0;i<A.size();i++){
        if(isVowel(A[i])) countV++;
    }
    return (countV*(A.size()-countV))%mod;
}

string Solution::solve(string A, string B) {
    int countA[10];
    int countB[10];
    memset(countA,0,sizeof(countA));
    memset(countB,0,sizeof(countB));
    int bulls =0,cows = 0;
    for(int i=0;i<A.size();i++){
        if(A[i] == B[i]){
            bulls++;
        }
        countA[A[i]-'0']++;
        countB[B[i]-'0']++;
    }
    for(int i=0;i<A.size();i++){
        if(A[i] == B[i]){
            countA[A[i]-'0']--;
            countB[B[i]-'0']--;
        }
    }
    for(int i=0;i<10;i++){
        if(countA[i] > 0 && countB[i] > 0){
            cows += min(countA[i],countB[i]);
        }
    }
    string res = to_string(bulls) + "A"+ to_string(cows)+"B";
    return res;
}

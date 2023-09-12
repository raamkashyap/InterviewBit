int Solution::chordCnt(int A) {
    if(A == 1) return 1;
    int n = 2 * A;
    int mod = 1e9+7;
    long long int dpArray[n + 1]={ 0 };
    dpArray[0] = 1;
    dpArray[2] = 1;
    for (int i=4;i<=n;i+=2){
        for (int j=0;j<i-1;j+=2){
          dpArray[i] += (dpArray[j]*dpArray[i-2-j]);
          dpArray[i] %= mod;
        }
    }
    return dpArray[n];

}

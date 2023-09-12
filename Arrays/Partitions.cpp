int Solution::solve(int A, vector<int> &arr) {
    int prefix[A];
    prefix[0] = arr[0];
    for(int i=1;i<A;i++){
        prefix[i] = prefix[i-1]+arr[i];
    }
    if(prefix[A-1]%3) return 0;
    int count = 0;
    int oneThirdSum = prefix[A-1]/3;
    int twoThirdSum = 2 * oneThirdSum;
    for(int i =0;i<A-2;i++){
        if(prefix[i] == oneThirdSum){
            int j= i+1;
            while(j<A-1)
            {
                if(prefix[j] == twoThirdSum){
                    count++;
                }
                j++;
            }
        }
    }
    return count;
}

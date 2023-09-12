int Solution::fibsum(int A) {
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1); 
    for(int i=2;fib[i-1]<=A;i++){
        fib.push_back(fib[i-1]+fib[i-2]);
    }
    int ans =0;
    int size = fib.size()-1;
    while(A){
        while(fib[size] > A){
            size--;
        }
        A = A- fib[size];
        ans++;
    }
    return ans;
}

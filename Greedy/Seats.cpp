int Solution::seats(string A) {
      long long n = A.length(), totalx = 0, leftx = 0, ans = 0;
    for(int i = 0; i < n; i++) if(A[i] == 'x') totalx++;
    for(int i = 0; i < n; i++) {
        if(A[i] == 'x') leftx++;
        else ans = (ans + min(leftx, totalx-leftx)) % 10000003;
    }
    return ans;
}

int largestRectangle(vector<int> &A){
    stack<int> s;
    s.push(0);
    int max_area =0;
    int n = A.size();
    for(int i=1;i<n;i++){
        if(s.empty() || A[i] > A[s.top()]){
            s.push(i);
        }
        else{
            while(!s.empty() && A[s.top()] > A[i]){
                int val = A[s.top()];
                s.pop();
                int area;
                if(s.empty()){
                    area = val*i;
                }
                else{
                    area = val*(i-s.top()-1);
                }
                max_area = max(max_area,area);
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        int val = A[s.top()];
        s.pop();
        int area;
        if(s.empty()){
            area = val*n;
        }
        else{
            area = val*(n-s.top()-1);
        }
        max_area = max(max_area,area);
    }
    return max_area;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size();
    if(m == 0 || n ==0) return 0;
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[0][i] = A[0][i];
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j] == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = dp[i-1][j] + A[i][j];
            }
        }
    }
    int res = 0;
    for(int i=0;i<m;i++){
        res = max(res,largestRectangle(dp[i]));
    }
    return res;
}

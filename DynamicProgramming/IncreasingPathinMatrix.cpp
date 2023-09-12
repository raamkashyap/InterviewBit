int Solution::solve(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    /*queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},1});
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int moves = q.front().second;
        if(x == m-1 && y == n -1){
            if(moves = n + m -1){
                return moves;
            }
            else return -1;
        }
        q.pop();
        if(x+1 < m && y < n && A[x][y] < A[x+1][y]){
            q.push({{x+1,y},moves+1});
        }
        if(x < m && y+1 < n && A[x][y] < A[x][y+1]){
            q.push({{x,y+1},moves+1});
        }
    }
    return -1;*/
    vector<vector<int>> dp(m, vector<int> (n,0));
    dp[0][0] = 1;
    for(int i=1;i<m;i++){
        if(A[i][0] < A[i-1][0] && dp[i][0]){
            dp[i][i] = 1;
        }
    }
    for(int i=m-2;i>=0;i--){
        if(A[i][n-1] < A[i+1][n-1] && dp[i+1][n-1]){
            dp[i][n-1] = 1;
        }
    }
    for(int i=m-2;i>=0;i--){
        for(int j= n-2;j>=0;j--){
            if(A[i][j] < A[i+1][j] && dp[i+1][j]){
                dp[i][j] = 1;
            }
            if(A[i][j] < A[i][j+1] && dp[i][j+1]){
                dp[i][j] = 1;
            }
        }
    }
    return (dp[0][0] == 1)? n + m -1 : -1;
}


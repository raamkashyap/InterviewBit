int Solution::solve(int A, int B, vector<string> &C) {
    vector<vector<int>> mat(A, vector<int>(B, INT_MAX));
    mat[0][0] = 0;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > q;
    q.push({0,{0,0}});
    while(!q.empty()){
        int cost = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        if(x == A-1 && y == B-1){
            break;
        }
        vector<pair<char,pair<int,int>>> dir{{'D', {1,0}},{'R', {0,1}}, {'U', {-1,0}}, {'L', {0,-1}}};
        for(auto ele : dir){
            char ch = ele.first;
            int dx = x + ele.second.first;
            int dy = y + ele.second.second;
            if(dx < 0 || dx >= A || dy <0 || dy >=B ) continue;
            if(ch == C[x][y] && mat[dx][dy] > cost){
                q.push({cost,{dx,dy}});
                mat[dx][dy]  = cost;
            }
            else if(mat[dx][dy] > cost +1){
                q.push({cost+1,{dx,dy}});
                mat[dx][dy] = cost+1;
            }
        }    
    }
    return mat[A-1][B-1];
}

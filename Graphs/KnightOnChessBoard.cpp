int Solution::knight(int m, int n, int sx, int sy, int dx, int dy) {
    
    int row[8] = {-2,-2,-1,-1,1,1,2,2};
    int col[8] = {-1,1,-2,2,-2,2,-1,1};
    sx--;
    sy--;
    dx--;
    dy--;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
    vector<vector<int>> mat(m,vector<int>(n, INT_MAX));
    mat[sx][sy] = 0;
    pq.push({0,{sx,sy}});
    while(!pq.empty()){
        int moves = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        if(r == dx && c == dy){
            return mat[dx][dy];
        }
        for(int i=0;i<8;i++){
            int dr = r + row[i];
            int dc = c + col[i];
            if(dr <0 || dr >= m || dc < 0 || dc >= n) continue;
            if(mat[dr][dc] > moves+1){
                mat[dr][dc] = moves+1;
                pq.push({moves+1,{dr,dc}});
            }
        }
    }
    return -1;
    
}

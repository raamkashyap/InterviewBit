int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool isWord(vector<string> &A, string B, int i, int j, int k) {
    if(i < 0 || i >= A.size() || j < 0 || j >= A[0].size()) return false;
    int m = B.size();
    if(k == m) return true;
    if(A[i][j] != B[k]) return false;
    bool res = false;
    for(int it = 0; it < 4; it++) {
        int x = i + dx[it];
        int y = j + dy[it];
        res = res || (isWord(A,B,x,y,k+1));
    }
    return res;
}
int Solution::exist(vector<string> &A, string B) {
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == B[0]) {
                if(isWord(A, B, i, j, 0) ) return 1;
            }
        }
    }
    return 0;
}
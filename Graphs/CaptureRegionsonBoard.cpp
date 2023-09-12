void Helper(vector<vector<char>> &A, int r,int c){
    if(r <0 || r >= A.size()) return;
    if(c < 0 || c >= A[0].size()) return;
    
    if(A[r][c] != '-') return;
    A[r][c] = 'O';
    Helper(A,r-1,c);
    Helper(A,r+1,c);
    Helper(A,r,c-1);
    Helper(A,r,c+1);
    
}
void Solution::solve(vector<vector<char> > &A) {
    int m = A.size();
    int n = A[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j] == 'O'){
                A[i][j] = '-';
            }
        }
    }
    for(int i=0;i<n;i++){
         if(A[0][i] == '-'){
             Helper(A, 0, i);
         }
    }
    for(int i=0;i<n;i++){
        if(A[m-1][i] == '-'){
            Helper(A,m-1,i);
        }
    }
    for(int i=0;i<m;i++){
        if(A[i][0] == '-'){
            Helper(A,i,0);
        }
    }
    for(int i=0;i<m;i++){
        if(A[i][n-1] == '-'){
            Helper(A,i,n-1);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
         if(A[i][j] == '-'){
            A[i][j] = 'X';   
         }   
        }
    }    
}

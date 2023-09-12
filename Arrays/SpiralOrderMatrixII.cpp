vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> res(A,vector<int>(A,0));
    int count = 1;
    int rowStart= 0 , rowEnd = A, colStart = 0, colEnd = A;
    int i=0;
    while(rowStart < rowEnd && colStart < colEnd){
        for( i = colStart; i<colEnd; i++){
            res[rowStart][i] = count;
            count++;
        }
        rowStart++;
        for( i = rowStart; i<rowEnd;i++){
            res[i][colEnd-1] = count;
            count++;
        }
        colEnd--;
        if(rowStart < rowEnd){
            for(i = colEnd-1; i>=colStart ;i--){
                res[rowEnd-1][i] = count;
                count++;
            }
        }
        rowEnd--;
        if(colStart < colEnd){
            for(i = rowEnd-1; i >= rowStart;i--){
                res[i][colStart] = count;
                count++;
            }
        }
        colStart++;
    }
    return res;
}


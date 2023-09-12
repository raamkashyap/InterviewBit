vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<vector<int>> res;
    for(int col = 0 ; col< n ;col++){
        int startCol = col, startrow =0;
        vector<int> temp;
        while(startCol >=0 && startrow < n){
            temp.push_back(A[startrow][startCol]);
            startrow++;
            startCol--;
        }
        res.push_back(temp);
    }
    for(int row = 1; row < n ;row++){
        int startrow = row , startCol = n-1;
        vector<int> temp;
        while(startrow < n && startCol >=0)
        {
            temp.push_back(A[startrow][startCol]);
            startrow++;
            startCol--;
        }
        res.push_back(temp);
    }
    return res;
}

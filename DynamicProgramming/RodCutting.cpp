long long int helper(int i, int j , vector<int> &cuts, vector<vector<long long int>> &dp, vector<vector<int>> &pos){
    if(abs(i-j) <=1){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    long long int min_cost = -1;
    for(int k =i+1;k<=j-1;k++){
        long long int cost_for_cut = cuts[j] - cuts[i];
        long long int curr_cost = cost_for_cut + helper(i,k,cuts,dp,pos) + helper(k, j ,cuts, dp, pos);
        if(curr_cost < min_cost || min_cost == -1LL){
            min_cost = curr_cost;
            pos[i][j] = k;
        }
    }
    return dp[i][j] = min_cost;
}
void helper2(int i,int j,vector<int> &v, vector<vector<int>> &pos, vector<int> &cuts){
    if(abs(i-j) <= 1) return;
    v.push_back(cuts[pos[i][j]]);
    helper2(i,pos[i][j],v,pos,cuts);
    helper2(pos[i][j], j , v ,pos, cuts);
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
    B.push_back(0);
    B.push_back(A);
    sort(B.begin(),B.end());
    int m = B.size();
    vector<vector<long long int>> dp(m+1,vector<long long int> (m+1, -1));
    vector<vector<int>> pos(m+1,vector<int> (m+1));
    int cost = helper(0,m-1, B,dp,pos);
    vector<int> v;
    helper2(0,m-1,v,pos,B);
    return v;
}

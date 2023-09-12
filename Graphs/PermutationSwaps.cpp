unordered_set<int> visited;


bool check(vector<int> adj[], int s, int &t)

{
    if(s == t)return true;
    visited.insert(s);
    for(auto i: adj[s])
    {
        if(visited.find(i) == visited.end() && check(adj, i, t))return true;
    }
    return false;
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {

    int n = A.size();
    vector<int> adj[n+1];
    for(auto i: C)
    {
        adj[A[i[0]-1]].push_back(A[i[1]-1]);
        adj[A[i[1]-1]].push_back(A[i[0]-1]);
    }
    for(int i = 0; i < n; i++)
    {
        if(A[i] != B[i])
        {
            visited.clear();
            if(!check(adj, A[i], B[i]))return 0;
        }
    }
    visited.clear();
    return 1;
}

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
     unordered_map<int , int> hash;
    for(auto p : A)
        hash[p[0]] = p[1];
    for(auto p : B)
        hash[p[0]] = p[1];
    queue<pair<int , int>> q;
    q.push({1 , 0});
    bool vis[101] = {};
    vis[1] = true;
    while(q.size())
    {
        int i = q.front().first;
        int res = q.front().second;
        q.pop();
        if(i == 100)
            return res;
        for(int p = 6 ; p >=1 ; p--)
        {
            int ii = i + p;
            if(ii <= 100 && !vis[ii])
            {
                if(hash[ii] && !vis[hash[ii]])
                {
                    q.push({hash[ii] , res+1});
                    vis[hash[ii]] = true;
                }
                else if(!hash[ii])
                {
                    q.push({ii , res+1});
                    vis[ii] = true;
                }
            }
        }
    }
    return -1;
}

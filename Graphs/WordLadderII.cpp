vector<vector<string> > Solution::findLadders(string begin, string end, vector<string> &dict) {
    vector<vector<string>> res;
    unordered_set<string>st(dict.begin(),dict.end());
    queue<vector<string>> q;
    q.push({begin});
    vector<string> used;
    used.push_back(begin);
    int level = 0;
    while(!q.empty())
    {
        vector<string> v = q.front();
        q.pop();
        if(v.size() > level){
            level++;
            for(auto x:used){
                st.erase(x);
            }
        }
        
        string word = v.back();
        if(word == end){
            if(res.size() == 0){
                res.push_back(v);
            }
            else if(res[0].size() == v.size()){
                res.push_back(v);
            }
        }
        for(int i=0;i<word.size();i++)
        {
            char original = word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.find(word) != st.end())
                {
                    v.push_back(word);
                    q.push(v);
                    used.push_back(word);
                    v.pop_back();
                }
            }
            word[i]=original;
        }
    }
    return res;
}

bool oneLetterDiff(string x, string y){
    int count =0;
    for(int i=0;i<x.length();i++){
        if(x[i] != y[i])
            count++;
    }
    if(count == 1) return 1;
    else return 0;
}
int Solution::solve(string begin, string end, vector<string> &dict) {
    queue<pair<string,int>>q;
    unordered_set<string>st(dict.begin(),dict.end());
    q.push({begin,1});
    st.erase(begin);
    while(!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word==end)   return steps;
        for(int i=0;i<word.size();i++)
        {
            char original = word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=original;
        }
    }


    return 0;
}

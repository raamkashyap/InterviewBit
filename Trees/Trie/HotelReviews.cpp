class Trie{
public:
     Trie *child[26];
     bool isEnd;
     Trie(){
         memset(child,0,sizeof(child));
         isEnd = false;
     }
};
void insert(Trie *root, string word){
    Trie *curr = root;
    for(char c : word){
        if(!curr->child[c-'a']){
            curr->child[c-'a'] = new Trie();
        }
        curr = curr->child[c-'a'];
    }
    curr->isEnd = true;
}
bool search(Trie *root, string word){
    Trie *curr = root;
    for(char c : word){
        if(!curr->child[c-'a']){
            return false;
        }
        curr = curr->child[c-'a'];
    }
    return curr->isEnd;
}
bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    Trie *root = new Trie();
    stringstream s(A);
    string word;
    while(getline(s,word,'_')){
        insert(root,word);
    }
    vector<int> res;
    vector<pair<int,int>> goodWordsList;
    for(int i=0;i<B.size();i++){
        stringstream s(B[i]);
        string word;
        int count = 0;
        while(getline(s,word,'_')){
            if(search(root,word)){
                count++;    
            }
            
        }
        goodWordsList.push_back({count,i});
    }
    sort(goodWordsList.begin(),goodWordsList.end(),comp);
    for(auto x : goodWordsList){
        res.push_back(x.second);
    }
    return res;
}

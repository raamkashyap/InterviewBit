class Trie {
public:
    Trie* child[26];
    int pre;
    bool isEnd;
    Trie(){
        pre = 1;
        memset(child,0,sizeof(child));
        isEnd = false;
    }
};
void insert(Trie *root, string word){
    Trie *curr = root;
    for(auto c : word){
        if(curr->child[c-'a'] == NULL){
            curr->child[c-'a'] = new Trie();
        }
        else{
            curr->child[c-'a']->pre +=1;
        }
        curr = curr->child[c-'a'];
    }
    curr->isEnd = true;
}

string search(Trie *root, string word){
    string res = "";
    Trie *curr = root;
    for(auto c : word){
        res += c;
        if(curr->child[c-'a']->pre == 1){
            return res;
        }
        curr = curr->child[c-'a'];
    }
    return word;
}
vector<string> Solution::prefix(vector<string> &A) {
    Trie *root = new Trie();
    for(int i=0;i<A.size();i++){
        insert(root,A[i]);
    }
    vector<string> res;
    for(int i=0;i<A.size();i++){
        res.push_back(search(root,A[i]));
    }
    return res;
}

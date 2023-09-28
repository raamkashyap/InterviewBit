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
        curr = curr->child[c-'a'];
    }
    curr->isEnd = true;
}

int search(Trie *root, string word){
    string res = "";
    Trie *curr = root;
    int count =0;
    for(auto c : word){
        if(curr->child[c-'a'] == NULL){
            return count;
        }
        else{
            curr = curr->child[c-'a'];
            count++;    
        }
        
    }
    return count;
}
string Solution::longestCommonPrefix(vector<string> &A) {
    Trie *root = new Trie();
    insert(root,A[0]);
    int res = INT_MAX;
    for(int i=0;i<A.size();i++){
        res = min(res,search(root,A[i]));
    }
    return A[0].substr(0,res);
}

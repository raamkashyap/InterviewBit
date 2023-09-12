/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    queue<UndirectedGraphNode*> q;
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    q.push(node);
    UndirectedGraphNode *res = new UndirectedGraphNode(node->label);
    mp[node] = res; 
    while(!q.empty()){
        UndirectedGraphNode *temp = q.front();
        q.pop();
        vector<UndirectedGraphNode *> v = temp->neighbors;
        for(int i=0;i<v.size();i++){
            if(mp.find(v[i]) == mp.end()){
                UndirectedGraphNode *temp2 = new UndirectedGraphNode(v[i]->label);
                mp[v[i]] = temp2;
                q.push(v[i]);
            }
            mp[temp]->neighbors.push_back(mp[v[i]]);
        } 
    }
    return mp[node];
    
    
}

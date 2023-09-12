void bfs(int A, int B, int num, vector<int> &res){
    queue<int> q;
    q.push(num);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        if(x >= A && x <= B){
            res.push_back(x);
        }
        if(x == 0 || x > B){
            continue;
        }
        
        int lastDigit = x %10;
        int stepA = x*10 + lastDigit -1;
        int stepB = x*10 + lastDigit +1;
        
        if(lastDigit == 0){
            q.push(stepB);
        }
        else if(lastDigit == 9){
            q.push(stepA);
        }
        else{
            q.push(stepA);
            q.push(stepB);
        }
    }
}
vector<int> Solution::stepnum(int A, int B) {
    vector<int> res;
    for(int i=0;i<=9;i++){
        bfs(A,B,i,res);
    }
    sort(res.begin(),res.end());
    return res;
}

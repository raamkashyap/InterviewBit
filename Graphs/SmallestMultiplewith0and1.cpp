string Solution::multiple(int A) {
    if(A == 1) return "1";
    vector<char> v(A, '2');
    vector<int> p(A, -1);
    queue<int> q;
    q.push(1);
    v[1] = '1';
    while(!q.empty()){
        int r = q.front();
        q.pop();
        if(r == 0){
            break;
        }
        int r0 = (r*10)%A;
        int r1 = (r*10 + 1)%A;
        if(v[r0] == '2'){
            v[r0] = '0';
            p[r0] = r;
            q.push(r0);
        }
        if(v[r1] == '2'){
            v[r1] = '1';
            p[r1] = r;
            q.push(r1);
        }
    }
    string res= "";
    int rem = 0;
    while(rem !=1){
        res += v[rem];
        rem = p[rem];
    }
    res += '1';
    reverse(res.begin(),res.end());
    return res;
}

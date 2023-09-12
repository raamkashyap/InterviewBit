bool Comp(string a, string b){
    string ab=a.append(b);
    string ba=b.append(a);
    if(ab.compare(ba)>0)
        return 1;
    else return 0;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<string> arr(A.size());
    int count =0;
    for(int i =0 ;i<A.size();i++){
        if(A[i] == 0)
            count++;
        arr[i] = to_string(A[i]);
    }
    if(count ==A.size())
        return "0";
    sort(arr.begin(),arr.end(),Comp);
    string res = "";
    for(int i=0;i<arr.size();i++){
        res += arr[i];
    }    
    return res;
}

vector<int> Solution::solve(int A, vector<int> &B) {
    int minStrength = B[0],minIndex=0;
    for(int i=0;i<B.size();i++){
        if(minStrength > B[i]){
            minStrength = B[i];
            minIndex = i;
        }
    }
    vector<int> res;
    while(A >= minStrength){
        res.push_back(minIndex);
        A -= minStrength;
    }
    int start =0,i=0;
    while(start < res.size() && i < minIndex){
        if(A - B[i] + minStrength >=0){
            A = A - B[i] + minStrength;
            res[start] = i;
            start++;
        }
        else{
            i++;
        }
    }
    return res;
}

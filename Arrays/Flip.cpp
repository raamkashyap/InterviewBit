vector<int> Solution::flip(string A) {
    vector<int> arr;
    int count =0; 
    for(int i=0;i<A.size();i++)
    {
        if(A[i] == '1')
        {
            arr.push_back(-1);
            count++;
        }
        else
        {
            arr.push_back(1);
        }
    }
    vector <int> res;
    if(count == A.size()) return {};
    res.resize(2);
    int currSum = 0 ,maxSum = INT_MIN,left = 0, right =0;
    for(int i=0;i<A.size();i++){
        currSum += arr[i];
        if(currSum > maxSum){
            maxSum = currSum;
            right = i;
            res[0] = left+1;
            res[1] = right +1;
        }
        if(currSum < 0){
            currSum = 0;
            left = i+1;
        }
    }
    if(currSum < 0){
        return {};
    }
    return res;
}

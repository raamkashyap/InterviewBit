int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int i=0;
    int res = INT_MAX;
    int min_diff = INT_MAX;
    while(i<A.size()-2){
        int j= i+1;
        int k = A.size()-1;
        while(j<k){
            int sum = A[i]+A[j]+A[k];
            int diff = B-sum;
            if(sum == B){
                return sum;
            }
            else if(sum < B){
                if(abs(diff) < min_diff){
                    min_diff = abs(diff);
                    res = sum;
                }
                j++;
            }
            else{
                if(abs(diff) < min_diff){
                    min_diff = abs(diff);
                    res = sum;
                }
                k--;
            }
        }
        i++;
    }
    return res;
}

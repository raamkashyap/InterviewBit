bool util(vector<int> &A, int start,int end,int B){
    while(start<=end){
        int mid = start + (end-start)/2;
        if((A[mid]-A[start]) == B){
            return 1;
        }
        else if((A[mid]-A[start]) < B){
            start = mid+1;
        }
        else end = mid-1;
    }
    return 0;
}
int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
    for(int i=0;i<n;i++){
        int start = i+1;
        int end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if((A[mid]-A[i]) == B){
                return 1;
            }
            else if((A[mid]-A[i]) < B){
                start = mid+1;
            }
            else end = mid-1;
        }
    }
    return 0;
}

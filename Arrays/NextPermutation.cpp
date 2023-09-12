vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size(),right = n-1,index=0;
    bool flag = 0;
    for(int i = 1 ; i<n ; ++i)
    {
        if(A[i-1] < A[i])
        {
            flag = 1;
        }
    }    
    if(!flag)
    {
        reverse(A.begin() , A.end());
        return A;
    }
    int i = A.size()-1;
    for(int j=i-1;j>=0;j--)
    {
        if(A[j] > A[j+1])
        {
            continue;
        }
        i=j;
        break;
    }
    
    int mni = -1, mn = INT_MAX;
    for(int j = i+1 ; j<A.size() ; ++j)
    {
        if(A[j] > A[i] and A[j] < mn)
        {
            mn = A[j];
            mni = j;
        }
    } 
    swap(A[i] , A[mni]);
    sort(A.begin() + i+1 , A.end());
    // int index , right = -1;
    // for(int j= n-1;j>right;j--){
    //     if(A[j] > A[right]){
            
    //     }
    // }
    // int i = right -1;
    // while(right>=1){
    //      if(i==0){
    //          right--;    
    //          i = right -1;
    //      }
    //      if(A[i] < A[right]){
    //          index = i;
    //          // cout<<"index "<< index << "right "<< right;
    //          break;
    //      }
    //      i--;
    //  }
    /*int i = A.size()-1;
    for(int j=i-1;j>=0;j--)
    {
        if(A[j] > A[j+1])
        {
            continue;
        }
        i=j;
        break;
    }*/
    // cout<<"index "<< index << "right "<< right;
    return A;
}

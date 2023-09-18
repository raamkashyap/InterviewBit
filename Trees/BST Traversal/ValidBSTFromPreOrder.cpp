//Using next greater element Idea
int Solution::solve(vector<int> &A) {
    int n = A.size();
    stack<int> s;
    int root = INT_MIN;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top() <= A[i]){
            root = s.top();
            s.pop();
        }
        if(A[i] <= root){
            return false;
        }
        s.push(A[i]);
    }
    return true;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval a ,Interval b){
    return a.start < b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), comp);
    int n = A.size();
    vector<Interval> res;
    if(n ==0){
        return res;
    }
    res.push_back(A[0]);
    for(int i=1;i<n;i++){
        if(res[res.size()-1].end >= A[i].start){
            res[res.size()-1].end = max(A[i].end, res[res.size()-1].end);
        }
        else
        {
            res.push_back(A[i]);
        }
    }
    Interval i = new Interval;
    
    res.push_back()
    return res;
}
